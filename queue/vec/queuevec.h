
#ifndef QUEUEVEC_H
#define QUEUEVEC_H

/* ************************************************************************** */

#include "../queue.h"

/* ************************************************************************** */

typedef struct QueueVec
{
  int top;
  DataObject** key;
  int dim;
  int testa;

} QueueVec;

/* ************************************************************************** */

QueueType* ConstructQueueVecType();
void DestructQueueVecType(QueueType* queuevecdatatype);


QueueVec* queConstructVec();
void queDestructVec(QueueVec* queue);

uint queEmptyVec(QueueVec* queue);
DataObject* queHeadVec(QueueVec* queue);
void queDequeueVec(QueueVec* queue);
DataObject* queHeadNDequeueVec(QueueVec* queue);
void queEnqueueVec(QueueVec* queue,DataObject* key);
int queSizeVec(QueueVec* queue);
QueueVec* queCloneVec(QueueVec* queue);
uint queEqualVec(QueueVec* queue1,QueueVec* queue2);
uint queExistsVec(QueueVec* queue, DataObject* elem);
void queMapVec(QueueVec* queue,MapFun mapper,void* _); 
void queFoldVec(QueueVec* queue,FoldFun folder,void* elem,void* _); 
void queClearVec(QueueVec* queue);


// FUNZIONI AGGIUNTIVE
void queReallocVec(QueueVec* queue,uint nuova_dim);
void quePrintfVec(QueueVec* queue);
/* ************************************************************************** */

#endif
