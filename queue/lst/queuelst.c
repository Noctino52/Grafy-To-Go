
#include "queuelst.h"

/* ************************************************************************** */
QueueType* ConstructQueueLstType(){
QueueType* queuelstdatatype=(QueueType*)malloc(sizeof(QueueType));
queuelstdatatype->queConstruct=(void*)(&queConstructLst);
queuelstdatatype->queDestruct=(void*)(&queDestructLst);
queuelstdatatype->queEnqueue=(void*)(&queEnqueueLst);
queuelstdatatype->queSize=(void*)(&queSizeLst);
queuelstdatatype->queClear=(void*)(&queClearLst);
queuelstdatatype->queHeadNDequeue=(void*)(&queHeadNDequeueLst);
queuelstdatatype->queHead=(void*)(&queHeadLst);
queuelstdatatype->queDequeue=(void*)(&queDequeueLst);
queuelstdatatype->queEmpty=(void*)(&queEmptyLst);
queuelstdatatype->queClone=(void*)(&queCloneLst);
queuelstdatatype->queEqual=(void*)(&queEqualLst);
queuelstdatatype->queExists=(void*)(&queExistsLst);
queuelstdatatype->queMap=(void*)(&queMapLst);
queuelstdatatype->queFold=(void*)(&queFoldLst);
queuelstdatatype->quePrintf=(void*)(&quePrintfLst);
return queuelstdatatype;
}

void DestructQueueLstType(QueueType* queuelstdatatype){
queuelstdatatype->queConstruct=(void*)(NULL);
queuelstdatatype->queDestruct=(void*)(NULL);
queuelstdatatype->queEnqueue=(void*)(NULL);
queuelstdatatype->queSize=(void*)(NULL);
queuelstdatatype->queClear=(void*)(NULL);
queuelstdatatype->queHeadNDequeue=(void*)(NULL);
queuelstdatatype->queHead=(void*)(NULL);
queuelstdatatype->queDequeue=(void*)(NULL);
queuelstdatatype->queEmpty=(void*)(NULL);
queuelstdatatype->queClone=(void*)(NULL);
queuelstdatatype->queEqual=(void*)(NULL);
queuelstdatatype->queExists=(void*)(NULL);
queuelstdatatype->queMap=(void*)(NULL);
queuelstdatatype->queFold=(void*)(NULL);
queuelstdatatype->quePrintf=(void*)(NULL);
free(queuelstdatatype);
}

QueueLst* queConstructLst(){
QueueLst* queue=(QueueLst*)malloc(sizeof(QueueLst));
queue->coda=NULL;
queue->testa=NULL;
return queue;
}

void queDestructLst(QueueLst* queue){
assert(queue!=NULL);
if(queEmptyLst(queue))free(queue);
else{queClearLst(queue); free(queue);}
}

void queDequeueLst(QueueLst* queue){
assert(queue!=NULL);
    if (queue->coda == queue->testa) 
    {  
        adtDestruct(queue->coda->dato);
        free(queue->coda);
        queue->coda = NULL; 
        queue->coda = NULL; 
    }
    else{
        Nodo *temp = queue->coda; 
        queue->coda = queue->coda->next; 
        queue->testa->next= queue->coda; 
        adtDestruct(temp->dato);
        free(temp); 
    }
    
}

void queEnqueueLst(QueueLst* queue,DataObject* key){
  assert(queue!=NULL && key!=NULL);
   
    Nodo *temp =(Nodo*)malloc(sizeof(Nodo));
    temp->dato=adtConstruct(key->op); 
    adtSetValue(temp->dato,key->dato); 
    if (queue->coda == NULL) 
        queue->coda = temp; 
    else
        queue->testa->next = temp; 
  
    queue->testa = temp; 
    queue->testa->next = queue->coda; 

}

int queSizeLst(QueueLst* queue){
assert(queue!=NULL);
uint i=0;
Nodo* temp = queue->coda;
if(!temp)return 0;
    do 
    { 
        i++;
        temp = temp->next; 
    }while(temp->next == queue->coda);
return i;
}

void quePrintfLst(QueueLst* queue){
assert(queue!=NULL);

    Nodo* temp = queue->coda; 
    uint i=0;
    printf("\nElementi nella coda: %d \n",queSizeLst(queue)); 
    printf("------------------------------------------------ \n");
    while (temp->next != queue->coda) 
    {
        if(temp==queue->coda)printf("(Coda) ");
        printf("queue[%d]:",i);
        adtWriteToMonitor(temp->dato); 
        temp = temp->next;
        if(temp==queue->testa)printf("(Testa) ");
        i++;
    } 
printf("queue[%d]:",i);
adtWriteToMonitor(temp->dato); 
printf("------------------------------------------------ \n");
}


uint queEmptyLst(QueueLst* queue){
assert(queue!=NULL);
if(queue->coda==NULL)return 1;
else return 0;
}

DataObject* queHeadLst(QueueLst* queue){
assert(queue!=NULL);
return queue->testa->dato;
}

DataObject* queHeadNDequeueLst(QueueLst* queue){
assert(queue!=NULL);
DataObject* valore=NULL;
Nodo* temp = queue->coda;
    if (queue->coda == queue->testa) 
    { 
        valore=adtClone(queue->coda->dato);
        adtDestruct(queue->coda->dato);
        queue->coda=NULL;
        queue->testa=NULL;
        free(temp);
    }
    else{
        valore=adtClone(temp->dato);
        queue->coda = queue->coda->next; 
        queue->testa->next= queue->coda;
        adtDestruct(temp->dato); 
        free(temp); 
    }
    return valore;
}

QueueLst* queCloneLst(QueueLst* queue){
    printf("ciao");
    assert(queue!=NULL);
    QueueLst* clone=queConstructLst();
    Nodo* temp = queue->coda;
    if(queue->coda!=NULL){
    while(temp->next!=queue->coda); 
    {
      queEnqueueLst(clone,temp->dato);
      temp=temp->next;
    }
    }
    return clone;
}

uint queEqualLst(QueueLst* queue1,QueueLst* queue2){
assert(queue1!=NULL && queue2!=NULL);

    Nodo* temp1 = queue1->coda;
    Nodo* temp2 = queue1->coda;
if(queSizeLst(queue1)==queSizeLst(queue2)){
    while (temp1->next != queue1->coda && temp2->next != queue2->coda) 
    { 
        if(!adtCompare(temp1->dato,temp2->dato))return 0;
        temp1 = temp1->next;
        temp1 = temp1->next; 
    }
}
else return 0;
return 1;
}


uint queExistsLst(QueueLst* queue, DataObject* elem){
assert(queue!=NULL);

    Nodo* temp = queue->coda; 
    while (temp->next != queue->coda) 
    { 
        if(adtCompare(temp->dato,elem))return 1;
        temp = temp->next; 
    }
return 0;
}

void queMapLst(QueueLst* queue,MapFun mapper,void* _){
assert(queue!=NULL);

    Nodo* temp = queue->coda; 
    while (temp->next != queue->coda) 
    { 
        mapper(temp->dato,NULL);
        temp = temp->next;
    }
    mapper(temp->dato,NULL);
}

void queFoldLst(QueueLst* queue,FoldFun folder,void* elem,void* _){
assert(queue!=NULL);

    Nodo* temp = queue->coda;
    folder(temp->dato,elem,NULL);
    while (temp->next != queue->coda) 
    { 
        folder(temp->dato,elem,NULL);
        temp = temp->next;
    }
    folder(temp->dato,elem,NULL);
}

void queClearLst(QueueLst* queue){
assert(queue!=NULL);
if(queue->coda==NULL) return;
Nodo* temp=queue->coda;
while(queue->coda!=NULL){
    if (queue->coda == queue->testa) 
    { 
        adtDestruct(queue->coda->dato);
        free(queue->coda);
        queue->coda=NULL;
        queue->testa=NULL;
    }
    else{
        temp=queue->coda;
        queue->coda = queue->coda->next; 
        queue->testa->next= queue->coda;
        adtDestruct(temp->dato);
        free(temp);
    }
   }
}

// ...
