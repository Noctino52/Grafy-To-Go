
#ifndef QUEUELST_H
#define QUEUELST_H

/* ************************************************************************** */

#include "../queue.h"

/* ************************************************************************** */
typedef struct Nodo 
{ 
  DataObject* dato; 
  struct Nodo* next; 

} Nodo; 

typedef struct QueueLst QueueLst;
struct QueueLst
{
  Nodo *testa;
  Nodo *coda;
 
};

/* ************************************************************************** */

QueueType* ConstructQueueLstType();
void DestructQueueLstType(QueueType* queuelstdatatype);

/* ************************************************************************** */

QueueType* ConstructQueueLstType();
void DestructQueueLstType(QueueType* queuelstdatatype);


QueueLst* queConstructLst();
void queDestructLst(QueueLst* queue);

uint queEmptyLst(QueueLst* queue);
DataObject* queHeadLst(QueueLst* queue);
void queDequeueLst(QueueLst* queue);
DataObject* queHeadNDequeueLst(QueueLst* queue);
void queEnqueueLst(QueueLst* queue,DataObject* key);
int queSizeLst(QueueLst* queue);
QueueLst* queCloneLst(QueueLst* queue);
uint queEqualLst(QueueLst* queue1,QueueLst* queue2);
uint queExistsLst(QueueLst* queue, DataObject* elem);
void queMapLst(QueueLst* queue,MapFun mapper,void* _); 
void queFoldLst(QueueLst* queue,FoldFun folder,void* elem,void* _); 
void queClearLst(QueueLst* queue);


// FUNZIONI AGGIUNTIVE
void queReallocLst(QueueLst* queue,uint nuova_dim);
void quePrintfLst(QueueLst* queue);
#endif
