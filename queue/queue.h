
#ifndef QUEUE_H
#define QUEUE_H

/* ************************************************************************** */

#include "../utility.h"

#include "../adt/adt.h"

/* ************************************************************************** */

typedef void* (*QueConstruct)();
typedef void(*QueDestruct)(void*);

typedef uint(*QueEmpty)(void*);
typedef void* (*QueHead)(void*);
typedef void(*QueDequeue)(void*);
typedef void* (*QueHeadNDequeue)(void*);
typedef void (*QueEnqueue)(void*,void*);
typedef void*(*QueClear)(void*);
typedef void* (*QueClone)(void*);
typedef uint (*QueEqual)(void*,void*);

typedef void(*QueMap)(void*,void*,void*);
typedef void (*QueFold)(void*,void*,void*,void*);
typedef int (*QueSize)(void*);
typedef uint (*QueExists)(void*,void*);
typedef void (*QuePrintf)(void*);


/* ************************************************************************** */

typedef struct QueueType
{
  QueConstruct queConstruct;
  QueDestruct queDestruct;
  QueEmpty queEmpty;
  QueHead  queHead;
  QueDequeue queDequeue;
  QueHeadNDequeue queHeadNDequeue;
  QueEnqueue queEnqueue;
  QueClear queClear;
  QueClone queClone;
  QueEqual queEqual;
  QueMap queMap;
  QueFold queFold;
  QueSize queSize;
  QueExists queExists;
  QuePrintf quePrintf;

} QueueType;

typedef struct QueueObject
{
  void* queue;
  QueueType* type;

} QueueObject;

/* ************************************************************************** */

QueueObject* queConstruct(QueueType* tipo);
void queDestruct(QueueObject* queue);

uint queEmpty(QueueObject* queue);
DataObject* queHead(QueueObject* queue);
void queDequeue(QueueObject* queue);
DataObject* queHeadNDequeue(QueueObject* queue);
void queEnqueue(QueueObject* queue,DataObject* elem);
void queClear(QueueObject* queue);

QueueObject* queClone(QueueObject* queue);
uint queEqual(QueueObject* queue1,QueueObject* queue2);
void queMap(QueueObject* queue,MapFun mapper,void*_);
void queFold(QueueObject* queue,FoldFun mapper,void*elem,void*_);

int queSize(QueueObject* queue);
uint queExists(QueueObject* queue,DataObject* elem);

void queRealloc(QueueObject* queue,uint nuova_dim);
void quePrintf(QueueObject* queue);
/* ************************************************************************** */
#endif
