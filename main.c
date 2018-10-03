#include <iostream>
#include <stdlib.h>
#define STACK_INIT_SIZE 100 
#define STACK_INCREMENT 10
#define elemType int
//栈的初始化大小100，一旦空间不足每次增加10
//数组的元素为int

//栈的存储结构——顺序栈（动态分配存储空间）
typedef struct{
   elemType *top, *base;
   int listSize;
}Stack;

//初始化栈
void initStack(Stack &s){
   s.base=(elemType *)malloc(STACK_INIT_SIZE*sizeof(elemType));
   if(!s.base){
      exit(-1);
   }else{
      s.top=s.base;
      s.listSize=STACK_INIT_SIZE;
   }
}

//检查栈是否为空
bool isEmpty(Stack s){
   if(s.top-s.base==0){
      return true;
   }else{
      return false;
   }
}

//入栈
bool push(Stack &s,elemType e){
   if(s.top-s.base>=s.listSize){
      s.base=(elemType *)realloc(s.base, (s.listSize+STACK_INCREMENT) * sizeof(elemType));
      if(!s.base){
         return false;
      }else{
         s.top=s.base+s.listSize;
         s.listSize+=STACK_INCREMENT;
      }
   }
   *s.top++=e;
   return true;
}

//出栈
bool pop(Stack &s,elemType &e){
   if(s.top-s.base==0){
      return false;
   }else{
      e=*--s.top;
      return true;
   }
}

//获得栈顶元素
bool getTop(Stack s,elemType &e){
   if(s.top-s.base==0){
      return false;
   }else{
      e=*(s.top-1);
      return true;
   }
}