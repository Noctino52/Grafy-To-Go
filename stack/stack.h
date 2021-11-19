
#ifndef STACK_H
#define STACK_H

/* ************************************************************************** */

#include "../utility.h"

#include "../adt/adt.h"

/* ************************************************************************** */

 typedef  void* (*StkConstruct)();
 typedef void (*StkDestruct)(void*);

 typedef uint (*StkEmpty)(void*);
 typedef void* (*StkTop)(void*);
 typedef void (*StkPop)(void*);
 typedef void* (*StkTopNPop)(void*);
 typedef void (*StkPush)(void*,void*);
 typedef int (*StkSize)(void*);

 typedef uint (*StkExists)(void*,void*);

 typedef void* (*StkClone)(void*);
 typedef uint (*StkEqual)(void*,void*);
 typedef void (*StkMap)(void*,void*,void*);
 typedef void (*StkFold)(void*,void*,void*,void*);
 typedef void* (*StkClear)(void*);
/* ************************************************************************** */

typedef struct StackType
{
  StkConstruct stkConstruct;
  StkDestruct stkDestruct;
  StkEmpty stkEmpty;
  StkTop stkTop;
  StkPop  stkPop;
  StkTopNPop  stkTopNPop;
  StkPush  stkPush;
  StkClear stkClear;
  StkExists stkExists;
  StkSize stkSize;
  StkClone  stkClone;
  StkEqual  stkEqual;
  StkMap  stkMap;
  StkFold  stkFold;
 
} StackType;

typedef struct StackObject
{
  void* stack;
  StackType* type;

} StackObject;

/* ************************************************************************** */

StackObject* stkConstruct(StackType* tipo);
void stkDestruct(StackObject* stack);

uint stkEmpty(StackObject* stack);
DataObject* stkTop(StackObject* stack);
void stkPop(StackObject* stack);
DataObject* stkTopNPop(StackObject* stack);
void stkPush(StackObject* stack,DataObject* elem);

StackObject* stkClone(StackObject* stack);
uint stkEqual(StackObject* stack1,StackObject* stack2);
int stkSize(StackObject* stack);
uint stkExists(StackObject* stack,DataObject* elem);
void stkClear(StackObject* stack);

void stkMap(StackObject* stack,MapFun mapper,void* _);
void stkFold(StackObject* stack,FoldFun folder,void* elem,void*_);

/* ************************************************************************** */

#endif
