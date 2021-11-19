
#ifndef STACKLST_H
#define STACKLST_H

/* ************************************************************************** */

#include "../stack.h"

/* ************************************************************************** */

typedef struct StackLst StackLst;
struct StackLst
{
  StackLst* top;
  DataObject* key;
  StackLst* next;
};

/* ************************************************************************** */

StackType* ConstructStackLstType();
void DestructStackLstType(StackType* tipo);

/* ************************************************************************** */

StackLst* stkConstructLst();
void stkDestructLst(StackLst* stack);

uint stkEmptyLst(StackLst* stack);
DataObject* stkTopLst(StackLst* stack);
void stkPopLst(StackLst* stack);
DataObject* stkTopNPopLst(StackLst* stack);
void stkPushLst(StackLst* stack,DataObject* key);
int stkSizeLst(StackLst* stack);
StackLst* stkCloneLst(StackLst* stack);
void stkClearLst(StackLst* stack);
uint stkEqualLst(StackLst* stack1,StackLst* stack2);
uint stkExistsLst(StackLst* stack, DataObject* elem);
void stkMapLst(StackLst* stack,MapFun mapper,void* _); 
void stkFoldLst(StackLst* stack,FoldFun folder,void* elem,void* _); 

#endif
