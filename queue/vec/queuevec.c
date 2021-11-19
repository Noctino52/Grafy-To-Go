
#include "queuevec.h"

/* ************************************************************************** */
QueueType* ConstructQueueVecType(){
QueueType* queuevecdatatype=(QueueType*)malloc(sizeof(QueueType));
queuevecdatatype->queConstruct=(void*)(&queConstructVec);
queuevecdatatype->queDestruct=(void*)(&queDestructVec);
queuevecdatatype->queEnqueue=(void*)(&queEnqueueVec);
queuevecdatatype->queSize=(void*)(&queSizeVec);
queuevecdatatype->queClear=(void*)(&queClearVec);
queuevecdatatype->queHeadNDequeue=(void*)(&queHeadNDequeueVec);
queuevecdatatype->queHead=(void*)(&queHeadVec);
queuevecdatatype->queDequeue=(void*)(&queDequeueVec);
queuevecdatatype->queEmpty=(void*)(&queEmptyVec);
queuevecdatatype->queClone=(void*)(&queCloneVec);
queuevecdatatype->queEqual=(void*)(&queEqualVec);
queuevecdatatype->queExists=(void*)(&queExistsVec);
queuevecdatatype->queMap=(void*)(&queMapVec);
queuevecdatatype->queFold=(void*)(&queFoldVec);
queuevecdatatype->quePrintf=(void*)(&quePrintfVec);
return queuevecdatatype;
}

void DestructQueueVecType(QueueType* queuevecdatatype){
queuevecdatatype->queConstruct=(void*)(NULL);
queuevecdatatype->queDestruct=(void*)(NULL);
queuevecdatatype->queEnqueue=(void*)(NULL);
queuevecdatatype->queSize=(void*)(NULL);
queuevecdatatype->queClear=(void*)(NULL);
queuevecdatatype->queHeadNDequeue=(void*)(NULL);
queuevecdatatype->queHead=(void*)(NULL);
queuevecdatatype->queDequeue=(void*)(NULL);
queuevecdatatype->queEmpty=(void*)(NULL);
queuevecdatatype->queClone=(void*)(NULL);
queuevecdatatype->queEqual=(void*)(NULL);
queuevecdatatype->queExists=(void*)(NULL);
queuevecdatatype->queMap=(void*)(NULL);
queuevecdatatype->queFold=(void*)(NULL);
queuevecdatatype->quePrintf=(void*)(NULL);
free(queuevecdatatype);
}

QueueVec* queConstructVec(){
	QueueVec* queue=(QueueVec*)malloc(sizeof(QueueVec));
	queue->dim=0;
	queue->key=(DataObject**)malloc(sizeof(DataObject**));
	queue->top=0;
        queue->testa=0;
	return queue;
}

void queDestructVec(QueueVec* queue){
     uint i;
     if(!queEmptyVec(queue)){
     for(i=queue->testa;i<((queue->testa+queue->top)%queue->dim);(++i)%queue->dim)
        adtDestruct(queue->key[i]);
     }
     free(queue->key);
     free(queue);
}

void queDequeueVec(QueueVec* queue){
  assert(queue!=NULL && queue->top!=0);
  
  adtDestruct(queue->key[queue->testa]);
  queue->testa=(queue->testa+1)%queue->dim;
  queue->top--;
  if(queue->top==0){
     queue->dim=0;
     queue->key=(DataObject**)realloc(queue->key,sizeof(DataObject**));
  }  
  else if(queue->dim/4 == queue->top) queReallocVec(queue,(queue->dim/2)*(sizeof(DataObject*)));
}

void queEnqueueVec(QueueVec* queue,DataObject* key){
  assert(queue!=NULL && key!=NULL);
  

  if(queue->dim==0){
      queue->dim=2;
      queue->key=(DataObject**)realloc(queue->key,sizeof(DataObject*)*2);
  }
  else if(queue->top==queue->dim) queReallocVec(queue,((queue->dim*2)*sizeof(DataObject*)));
  int coda=((queue->testa+queue->top)%queue->dim);
  queue->key[coda]=adtConstruct(key->op);
  adtSetValue(queue->key[coda],key->dato);
  queue->top++;

}

int queSizeVec(QueueVec* queue){
assert(queue!=NULL);
return queue->top;
}

void queReallocVec(QueueVec* queue,uint nuova_dim){

      assert(queue!=NULL);
         uint i;
         int temptesta=queue->testa;
         int nuova=nuova_dim/sizeof(DataObject*);
         int vecchia=queue->dim;
         DataObject** temp=(DataObject**)malloc((sizeof(DataObject*)*queue->top));
         for(i=0;i<queue->top;i++){
             temp[i]=adtConstruct(queue->key[temptesta]->op);
             adtSetValue(temp[i],queue->key[temptesta]->dato);
             temptesta=((temptesta+1)%(vecchia));     
         }
         temptesta=queue->testa;
         for(i=0;i<queue->top;i++){
             adtDestruct(queue->key[temptesta]);
             temptesta=((temptesta+1)%(vecchia));
         }
         queue->key=(DataObject**)realloc(queue->key,(sizeof(DataObject*)*nuova));
         queue->testa=0;
         for(i=0;i<queue->top;i++){
             queue->key[i]=adtConstruct(temp[i]->op);
             adtSetValue(queue->key[i],temp[i]->dato);
             adtDestruct(temp[i]);
         }
         free(temp);
         queue->dim=nuova; 
}

void quePrintfVec(QueueVec* queue){
  assert(queue!=NULL);
  if(queue->top==0)printf("La coda e' vuota! \n");
  else{
  int coda=(queue->testa+queue->top)%queue->dim;
  printf("queue->dim : %d \n",queue->dim);
  printf("queue->top : %d \n",queue->top);
  printf("queue->testa : %d \n",queue->testa);
  printf("coda : %d \n",coda);
     uint i=0;
     int temptesta=queue->testa;
          printf("------------------------------------------------------------------------------------- \n");
          printf("---------LOCAZIONE-------------DATO-------------\n");
     while(i!=queue->top){
          printf("queue->key[%d] (testa= %d)  = ",i,temptesta);
          adtReadFromKeyboard(queue->key[temptesta]);
          i++;
          if(temptesta!=queue->dim-1)temptesta++;
          else temptesta=0;
  }
          printf("------------------------------------------------------------------------------------- \n");
  }
}


uint queEmptyVec(QueueVec* queue){
assert(queue!=NULL);
if(queue->top==0 || queue->dim==0) return 1;
else return 0;
}

DataObject* queHeadVec(QueueVec* queue){
assert(queue!=NULL && queue->top!=0 && queue->dim!=0);
DataObject* temp=adtClone(queue->key[queue->testa]);
return temp;
}

DataObject* queHeadNDequeueVec(QueueVec* queue){
   assert(queue!=NULL || queue->top==0);
   DataObject* temp=adtConstruct(queue->key[queue->testa]->op);
   adtSetValue(temp,queue->key[queue->testa]->dato);
   queDequeueVec(queue);
   return temp;
}

QueueVec* queCloneVec(QueueVec* queue){
assert(queue!=NULL);
QueueVec* queue2=queConstructVec();
if(queEmptyVec(queue))printf("La coda e' vuota! ti creo una nuova coda direttamente");
else{
   uint i;
  queue2->key=(DataObject**)realloc(queue2->key,sizeof(DataObject*)*queue->dim);
  for(i=queue->testa;i<((queue->testa+queue->top)%queue->dim);(++i)%queue->dim){
   queue2->key[i]=adtConstruct(queue->key[i]->op);
   adtSetValue(queue2->key[i],queue->key[i]->dato);
   }
   queue2->top=queue->top;
   queue2->dim=queue->dim;
   queue2->testa=queue->testa;
}
  return queue2;
}

uint queEqualVec(QueueVec* queue1,QueueVec* queue2){
uint i;
if(queEmptyVec(queue1)&&(queEmptyVec(queue2)))return 1;
if(queue1->dim==queue2->dim && queue1->testa==queue2->testa && queue1->top==queue2->top && queue1!=queue2)
{
  for(i=queue1->testa;i<((queue1->testa+queue1->top)%queue1->dim);(++i)%queue1->dim)
     if((adtCompare(queue1->key[i],queue2->key[i]))!=1)return 0;
  return 1;
}
else return 0;
}


uint queExistsVec(QueueVec* queue, DataObject* elem){
uint i;
assert(elem!=NULL && queue!=NULL);
if(queEmptyVec(queue))return 0;
else{
  for(i=queue->testa;i<((queue->testa+queue->top)%queue->dim);(++i)%queue->dim){
     if((adtCompare(queue->key[i],elem)))return 1;
  }
  return 0;
    }

}

void queMapVec(QueueVec* queue,MapFun mapper,void* _){

     assert(queue!=NULL && queue->key!=NULL);
     uint i;
     for(i=queue->testa;i<(queue->testa+queue->top);((++i)%queue->dim))
     mapper((void*)(queue->key[i]),NULL);
}

void queFoldVec(QueueVec* queue,FoldFun folder,void* elem,void* _){
   assert(queue!=NULL && queue->key!=NULL && elem!=NULL);
   
   uint i;
   for(i=queue->testa;i<(queue->testa+queue->top);((++i)%queue->dim))
   folder(((void*)queue->key[i]),((void*)elem),NULL);

}

void queClearVec(QueueVec* queue){
uint i;
  for(i=queue->testa;i<((queue->testa+queue->top)%queue->dim);(++i)%queue->dim) queDequeueVec(queue);
}

// ...
