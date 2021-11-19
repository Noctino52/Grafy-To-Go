
#ifndef ADTFLT_H
#define ADTFLT_H

/* ************************************************************************** */

#include "../adt.h"

/* ************************************************************************** */

#define MaxFltAbsRndVal 250.0
#define MaxFltPrcRndVal 1000.0

/* ************************************************************************** */

DataType* ConstructFloatDataType();
void DestructFloatDataType(DataType* type);



/* ************************************************************************** */
float* CreateFloat();
void DestructFloat(float* var);
float* GetValueFlt(float* var);
void SetValueFlt(float* var,float* dato);
void RandomValueFlt(float* var);
void ReadFromKeyBoardFlt(float* var);
void WriteToMonitorFlt(float* var);
float* CloneFlt(float* var);
uint CompareFlt(float* var1, float* var2);

#endif
