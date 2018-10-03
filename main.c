#include <iostream>
#include <stdlib.h>
#define STACK_INIT_SIZE 100 
#define STACK_INCREMENT 10
#define elemType int
//ջ�ĳ�ʼ����С100��һ���ռ䲻��ÿ������10
//�����Ԫ��Ϊint

//ջ�Ĵ洢�ṹ����˳��ջ����̬����洢�ռ䣩
typedef struct{
   elemType *top, *base;
   int listSize;
}Stack;

//��ʼ��ջ
void initStack(Stack &s){
   s.base=(elemType *)malloc(STACK_INIT_SIZE*sizeof(elemType));
   if(!s.base){
      exit(-1);
   }else{
      s.top=s.base;
      s.listSize=STACK_INIT_SIZE;
   }
}

//���ջ�Ƿ�Ϊ��
bool isEmpty(Stack s){
   if(s.top-s.base==0){
      return true;
   }else{
      return false;
   }
}

//��ջ
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

//��ջ
bool pop(Stack &s,elemType &e){
   if(s.top-s.base==0){
      return false;
   }else{
      e=*--s.top;
      return true;
   }
}

//���ջ��Ԫ��
bool getTop(Stack s,elemType &e){
   if(s.top-s.base==0){
      return false;
   }else{
      e=*(s.top-1);
      return true;
   }
}