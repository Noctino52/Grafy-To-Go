
#include "queue.h"

/* ************************************************************************** */


QueueObject* queConstruct(QueueType* tipo){

   QueueObject* queue=(QueueObject*)malloc(sizeof(QueueObject));
   queue->type=tipo;
   queue->queue=queue->type->queConstruct();
   return queue;
}

void queDestruct(QueueObject* queue){
queue->type->queDestruct(queue->queue);
queue->type=NULL;
free(queue);
}

uint queEmpty(QueueObject* queue){
return queue->type->queEmpty(queue->queue);
}

DataObject* queHead(QueueObject* queue){
return queue->type->queHead(queue->queue);
}

void queDequeue(QueueObject* queue){
queue->type->queDequeue(queue->queue);
}

DataObject* queHeadNDequeue(QueueObject* queue){
return queue->type->queHeadNDequeue(queue->queue);
}

void queEnqueue(QueueObject* queue,DataObject* elem){
queue->type->queEnqueue(queue->queue,elem);
}

int queSize(QueueObject* queue){
return queue->type->queSize(queue->queue);
}

QueueObject* queClone(QueueObject* queue){
QueueObject* clone=(QueueObject*)malloc(sizeof(QueueObject));
clone->type=queue->type;
clone->queue=queue->type->queClone(queue->queue);
return clone;
}

uint queEqual(QueueObject* queue1,QueueObject* queue2){
return queue1->type->queEqual(queue1->queue,queue2->queue);
}

void queClear(QueueObject* queue){
queue->type->queClear(queue->queue);
}

uint queExists(QueueObject* queue, DataObject* elem){
return queue->type->queExists(queue->queue,elem);
}

void queMap(QueueObject* queue,MapFun mapper,void* _){
queue->type->queMap(queue->queue,mapper,NULL);
}

void queFold(QueueObject* queue,FoldFun folder,void* elem,void* _){
queue->type->queFold(queue->queue,folder,elem,NULL);
}

void quePrintf(QueueObject* queue){
queue->type->quePrintf(queue->queue);
}


// ...
