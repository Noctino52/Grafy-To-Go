
#ifndef ADTINT_H
#define ADTINT_H

/* ************************************************************************** */

#include "../adt.h"

/* ************************************************************************** */

#define MaxIntAbsRndVal 250

/* ************************************************************************** */

DataType* ConstructIntDataType();
void DestructIntDataType(DataType*);

/* ************************************************************************** */

long long int* CreateInteger();
void DestructInteger(long long int* var);
long long int* GetValueInt(long long int* var);
long long int* SetValueInt(long long int* var,long long int* dato);
void RandomValueInt(long long int* var);
void ReadFromKeyBoardInt(long long int* var);
void WriteToMonitorInt(long long int* var);
long long int* CloneInt(long long int* var);
uint CompareInt(long long int* var1, long long int* var2);

#endif
