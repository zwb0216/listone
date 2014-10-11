#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define OK 1
#define ERROR 0 　　　
#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 20
using namespace std;

typedef struct {      //定义字符类型栈 
   int stacksize; 
   char *base; 
   char *top; 
}Stack1; 

typedef struct{      // 定义整型栈 
   int stacksize; 
   int *base; 
   int *top; 
}Stack2;

Stack1 OPTR;         // 定义运算符栈
Stack2 OPND;         // 定义操作数栈

char InitStack1(Stack1 &S){        //构造运算符栈
   S.base=(char *)malloc(STACK_INIT_SIZE*sizeof(char));
   if(!S.base) exit(1);
   S.top=S.base;
   S.stacksize = STACK_INIT_SIZE;
   return OK;
}

int InitStack2(Stack2 &S){
S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));  //构造操作数栈
if(!S.base) exit(1);
S.top=S.base;
S.stacksize = STACK_INIT_SIZE;
return OK;
}

bool In(char ch){                //判断字符是否是运算符，运算符即返回1
     if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='=')
 return true; 
 else 
 return false; 
}

char Push1(Stack1 &S,char ch) {        //运算符栈插入ch为新的栈顶元素 
    *S.top++=ch; 
    return 0; 
}

int Push2(Stack2 &S,int ch){           //操作数栈插入ch为新的栈顶元素 
*S.top++=ch;
return 0;
}

char Pop1(Stack1 &S,char&e){        //删除运算符栈s的栈顶元素，用e返回其值
    e = *--S.top;
    return e;
}

int Pop2(Stack2 &S,int&e){           //删除操作数栈s的栈顶元素，用e返回其值
e = *--S.top;
return e;
}

char GetTop1(Stack1 &S){        //用e返回运算符栈s的栈顶元素 
char e;
if(S.top==S.base) exit(1);
e=*(S.top-1); 
    return e; 
}

int GetTop2(Stack2 &S){        //用e返回操作数栈s的栈顶元素
int e;
if(S.top==S.base) exit(1);
    e=*(S.top-1); 
    return e; 
}

char OPSET[7]={'+' , '-' , '*' , '/' ,'(' , ')' , '='};
char Precede(char c1,char c2){       // 判断运算符优先权，返回优先权高的 
    int i=0,j=0; 
    static char array[7][7]={
'>', '>', '<', '<', '<', '>', '>',
    '>', '>', '<', '<', '<', '>', '>',
'>', '>', '>', '>', '<', '>', '>', 
'>', '>', '>', '>', '<', '>', '>',
'<', '<', '<', '<', '<', '=', '!',
'>', '>', '>', '>', '!', '>', '>',
'<', '<', '<', '<', '<', '!', '='};
    switch(c1){
case '+' : i=0; break;
case '-' : i=1; break;
case '*' : i=2; break;
case '/' : i=3; break;
case '(' : i=4; break;
case ')' : i=5; break;
case '=' : i=6; break;
}
    switch(c2){
case '+' : j=0; break;
case '-' : j=1; break;
case '*' : j=2; break;
case '/' : j=3; break;
case '(' : j=4; break;
case ')' : j=5; break;
case '=' : j=6; break;
}
    return (array[i][j]);         //返回运算符　　　
}

int Operate(int a,char op,int b){            //运算执行函数
    switch(op){
case '+' : return (a+b);
case '-' : return (a-b);
case '*' : return (a*b);
case '/' : return (a/b);
}
return 0;
}

int main( ) {
printf("请输入正确的表达式以'='结尾:"); 
    char c,x,theta;
int a,b;
Stack1 OPTR;
Stack2 OPND;
InitStack1(OPTR); Push1(OPTR,'=');
InitStack2(OPND); c=getchar();
    while(c!='='||GetTop1(OPTR)!='='){
      if(!In(c)) {Push2(OPND,c-'0');c=getchar();}
      else
  switch(Precede(GetTop1(OPTR),c)){
          case '<': 
            Push1(OPTR,c);
c=getchar(); 
            break; 
  case '=':
Pop1(OPTR,x); c=getchar(); 
            break; 
          case '>':
Pop1(OPTR,theta);
Pop2(OPND,b); Pop2(OPND,a);
            Push2(OPND,Operate(a,theta,b));
            break;
}
}
    cout<< GetTop2(OPND)<<endl; 
return 0;
}
