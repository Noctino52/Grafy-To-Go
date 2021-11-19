
#ifndef ADT_H
#define ADT_H

/* ************************************************************************** */

#include "../utility.h"


/* ************************************************************************** */


typedef void *(*ADTConstruct)();
typedef void (*ADTDestruct)(void*);

typedef void* (*ADTGetValue)(void*);
typedef void* (*ADTSetValue)(void*,void*);

typedef void (*ADTRandomValue)(void*);
typedef void (*ADTReadFromKeyboard)(void*);
typedef void (*ADTWriteToMonitor)(void*);

typedef void* (*ADTClone)(void*);
typedef uint (*ADTCompare)(void*,void*);

/* ************************************************************************** */

typedef struct DataType
{
  ADTConstruct adtConstruct;
  ADTDestruct adtDestruct;
  ADTGetValue adtGetValue;
  ADTSetValue adtSetValue;
  ADTRandomValue adtRandomValue;
  ADTReadFromKeyboard adtReadFromKeyBoard;
  ADTWriteToMonitor adtWriteToMonitor;
  ADTClone adtClone;
  ADTCompare adtCompare;

} DataType;

typedef struct DataObject
{
  void* dato;
  DataType * op;

} DataObject;


DataObject* adtConstruct(DataType* type);
void adtDestruct(DataObject* object);

void* adtGetValue(DataObject* object);
void adtSetValue(DataObject* object,void* dato);

void adtRandomValue(DataObject* object);
void adtReadFromKeyboard(DataObject* object);
void adtWriteToMonitor(DataObject* object);

DataObject* adtClone(DataObject* object);
uint adtCompare(DataObject* object1,DataObject* object2);

/* ************************************************************************** */

typedef void (*MapFun)(DataObject *, void *);
typedef void (*FoldFun)(DataObject *, void *, void *);
#endif
