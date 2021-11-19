#ifndef NODE_H
#define NODE_H
/* ************************************************************************** */

#include "../bst/bst.h"
#include "../adt.h"

/* ************************************************************************** */

/* ************************************************************************** */

DataType* ConstructVoidDataType();
void DestructVoidDataType(DataType*);

/* ************************************************************************** */

void* CreateVoid();
void DestructVoid(void* var);
void* GetValueVoid(void* var);
void* SetValueVoid(void* var,void* dato);
void RandomValueVoid(void* var);
void ReadFromKeyBoardVoid(void* var);
void WriteToMonitorVoid(void* var);
void* CloneVoid(void* var);
uint CompareVoid(void* var1, void* var2);


#endif
