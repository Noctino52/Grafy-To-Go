
#ifndef ADTSTR_H
#define ADTSTR_H

/* ************************************************************************** */

#include "../adt.h"

/* ************************************************************************** */

#define MaxStrLen 25

/* ************************************************************************** */

DataType* ConstructStringDataType();
void DestructStringDataType(DataType*);
/* ************************************************************************** */

char** CreateString();
void DestructString(char** var);
char** GetValueStr(char** var);
void SetValueStr(char** var,char** dato);
void RandomValueStr(char** var);
void ReadFromKeyBoardStr(char** var);
void WriteToMonitorStr(char** var);
char** CloneStr(char** var);
uint CompareStr(char** var1, char** var2);

#endif
