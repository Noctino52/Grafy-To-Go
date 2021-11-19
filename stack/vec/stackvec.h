
#ifndef STACKVEC_H
#define STACKVEC_H

/* ************************************************************************** */

#include "../stack.h"

typedef struct StackVec
{
  int top;
  int dim;
  DataObject** key;

} StackVec;
/* ************************************************************************** */

StackType* ConstructStackVecType();
void DestructStackVecType(StackType* type);

/* ************************************************************************** */

StackVec* stkConstructVec();
void stkDestructVec(StackVec* stack);

uint stkEmptyVec(StackVec* stack);
DataObject* stkTopVec(StackVec* stack);
void stkPopVec(StackVec* stack);
DataObject* stkTopNPopVec(StackVec* stack);
void stkPushVec(StackVec* stack,DataObject* key);
int stkSizeVec(StackVec* stack);
StackVec* stkCloneVec(StackVec* stack);
void stkClearVec(StackVec* stack);
uint stkEqualVec(StackVec* stack1,StackVec* stack2);
uint stkExistsVec(StackVec* stack, DataObject* elem);
void stkMapVec(StackVec* stack,MapFun mapper,void* _); 
void stkFoldVec(StackVec* stack,FoldFun folder,void* elem,void* _); 


// FUNZIONI AGGIUNTIVE
void stkReallocVec(StackVec* stack,uint nuova_dim);
#endif
