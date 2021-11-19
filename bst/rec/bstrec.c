
#include "bstrec.h"
#include "../adt/int/adtint.h"
#include "../adt/pointer/adtpointer.h"
/* ************************************************************************** */
BSTType* ConstructBSTRecursive(){
BSTType* recalgo=(BSTType*)malloc(sizeof(BSTType));
recalgo->bstdestruct=(void*)(&RicDestruct);
recalgo->bstclone=(void*)(&RicClone);
recalgo->bstequal=(void*)(&RicEqual);
recalgo->bstexists=(void*)(&RicExists);
recalgo->bstinsert=(void*)(&RicInsert);
recalgo->bstremove=(void*)(&RicRemove);
recalgo->bstgetmin=(void*)(&RicGetMin);
recalgo->bstgetnremovemin=(void*)(&RicGetNRemoveMin);
recalgo->bstremovemin=(void*)(&RicRemoveMin);
recalgo->bstgetmax=(void*)(&RicGetMax);
recalgo->bstgetnremovemax=(void*)(&RicGetNRemoveMax);
recalgo->bstremovemax=(void*)(&RicRemoveMax);
recalgo->bstgetpredecessor=(void*)(&RicGetPredecessor);
recalgo->bstgetnremovepredecessor=(void*)(&RicGetNRemovePredecessor);
recalgo->bstremovepredecessor=(void*)(&RicRemovePredecessor);
recalgo->bstgetsuccessor=(void*)(&RicGetSuccessor);
recalgo->bstgetnremovesuccessor=(void*)(&RicGetNRemoveSuccessor);
recalgo->bstremovesuccessor=(void*)(&RicRemoveSuccessor);
recalgo->bstpreordermap=(void*)(&RicPreOrderMap);
recalgo->bstpostordermap=(void*)(&RicPostOrderMap);
recalgo->bstinordermap=(void*)(&RicInOrderMap);
recalgo->bstbreadthmap=(void*)(&RicBreadthMap);
recalgo->bstpreorderfold=(void*)(&RicPreOrderFold);
recalgo->bstpostorderfold=(void*)(&RicPostOrderFold);
recalgo->bstinorderfold=(void*)(&RicInOrderFold);
recalgo->bstbreadthfold=(void*)(&RicBreadthFold);
return recalgo;
//...
}

void DestructBSTRecursive(BSTType* recalgo){
recalgo->bstdestruct=(void*)(NULL);
recalgo->bstclone=(void*)(NULL);
recalgo->bstequal=(void*)(NULL);
recalgo->bstexists=(void*)(NULL);
recalgo->bstinsert=(void*)(NULL);
recalgo->bstremove=(void*)(NULL);
recalgo->bstgetmin=(void*)(NULL);
recalgo->bstgetnremovemin=(void*)(NULL);
recalgo->bstremovemin=(void*)(NULL);
recalgo->bstgetmax=(void*)(NULL);
recalgo->bstgetnremovemax=(void*)(NULL);
recalgo->bstremovemax=(void*)(NULL);
recalgo->bstgetpredecessor=(void*)(NULL);
recalgo->bstgetnremovepredecessor=(void*)(NULL);
recalgo->bstremovepredecessor=(void*)(NULL);
recalgo->bstgetsuccessor=(void*)(NULL);
recalgo->bstgetnremovesuccessor=(void*)(NULL);
recalgo->bstremovesuccessor=(void*)(NULL);
recalgo->bstpreordermap=(void*)(NULL);
recalgo->bstpostordermap=(void*)(NULL);
recalgo->bstinordermap=(void*)(NULL);
recalgo->bstbreadthmap=(void*)(NULL);
recalgo->bstpreorderfold=(void*)(NULL);
recalgo->bstpostorderfold=(void*)(NULL);
recalgo->bstinorderfold=(void*)(NULL);
recalgo->bstbreadthfold=(void*)(NULL);
free(recalgo);
}

void RicDestruct(BSTNode* tree){
if(tree!=NULL){
   RicDestruct(tree->sx);
   RicDestruct(tree->dx);
   adtDestruct(tree->info);
   free(tree);
   }
}

BSTNode* RicInsert(BSTNode* tree,DataObject* elem){
  if(tree!=NULL){
    if(adtCompare(tree->info,elem)==2)tree->sx=RicInsert(tree->sx,elem);
    else if (adtCompare(tree->info,elem)==1)tree->dx=RicInsert(tree->dx,elem);
  }
  else tree=newNode(elem);
 return tree;
}



uint RicExists(BSTNode* tree,DataObject* elem){
if(tree!=NULL){
    uint flag=1;
    if(adtCompare(tree->info,elem)==0)return 0;
    if(tree->sx && flag)flag=RicExists(tree->sx,elem);
    if(tree->dx && flag)flag=RicExists(tree->dx,elem);
    return flag;
}
return 1;
}

BSTNode* RicClone(BSTNode* tree){
BSTNode* temp=NULL;
BSTNode* clone=NULL;
temp=tree;
if(temp!=NULL){
clone=newNode(temp->info);
if(temp->sx)clone->sx=RicClone(temp->sx);
if(temp->dx)clone->dx=RicClone(temp->dx);
}
return clone;
}

uint RicEqual(BSTNode* tree1,BSTNode* tree2){
if(tree1!=NULL && tree2!=NULL){
if(adtCompare(tree1->info,tree2->info)!=0)return 0;
else return(RicEqual(tree1->sx,tree2->sx)) && (RicEqual(tree1->dx,tree2->dx));
}
else return 1;
}

void RicRemove(BSTNode** tree,DataObject* elem){
    if((*tree)!=NULL){
        if(adtCompare((*tree)->info,elem)==0) { printf("Ciao2 \n"); (*tree)=RicCancRadice(*tree);}
        else if(adtCompare((*tree)->info,elem)==1) RicRemove(&(*tree)->dx,elem);
        else RicRemove(&(*tree)->sx,elem);
    }
}

BSTNode* RicGetMin(BSTNode* tree) {
    if (tree != NULL) {
        if (tree->sx != NULL)
            return RicGetMin(tree->sx);
    }
    return tree;
}



void RicPreOrderMap(BSTNode* tree,MapFun mapper){
if(tree!=NULL){
mapper(tree->info,NULL);
RicPreOrderMap(tree->sx,mapper);
RicPreOrderMap(tree->dx,mapper);
}
}

void RicInOrderMap(BSTNode* tree,MapFun mapper){
if(tree!=NULL){
RicInOrderMap(tree->sx,mapper);
mapper(tree->info,NULL);
RicInOrderMap(tree->dx,mapper);
}
}

void RicPostOrderMap(BSTNode* tree,MapFun mapper){
if(tree!=NULL){
RicPostOrderMap(tree->sx,mapper);
RicPostOrderMap(tree->dx,mapper);
mapper(tree->info,NULL);
}
}

void RicBreadthMap(BSTNode* tree,MapFun mapper){
if(tree!=NULL){

    BSTNode* curr=NULL;
    curr=tree;
    QueueType* tipo_coda=ConstructQueueVecType();
    QueueObject* coda=queConstruct(tipo_coda);
    DataType*  type=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(type);

    adtSetValue(pointer,curr);
    queEnqueue(coda,pointer);
    free(pointer);

    while(!queEmpty(coda)){
        pointer=queHead(coda);
        curr=adtGetValue(pointer);
        mapper(curr->info,NULL);
        queDequeue(coda);
        if(curr->sx!=NULL){adtSetValue(pointer,curr->sx); queEnqueue(coda,pointer);}
        if(curr->dx!=NULL){adtSetValue(pointer,curr->dx); queEnqueue(coda,pointer);}
        adtDestruct(pointer);
    }
    queDestruct(coda);
    DestructVoidDataType(type);

}
}

void RicPreOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem){
if(tree!=NULL){
folder(tree->info,elem,NULL);
RicPreOrderFold(tree->sx,folder,elem);
RicPreOrderFold(tree->dx,folder,elem);
}
}

void RicInOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem){
if(tree!=NULL){
RicPreOrderFold(tree->sx,folder,elem);
folder(tree->info,elem,NULL);
RicPreOrderFold(tree->dx,folder,elem);
}
}

void RicPostOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem){
if(tree!=NULL){
RicPreOrderFold(tree->sx,folder,elem);
RicPreOrderFold(tree->dx,folder,elem);
folder(tree->info,elem,NULL);
}
}

void RicBreadthFold(BSTNode* tree,FoldFun folder,DataObject* elem){

    BSTNode* curr=tree;
    QueueType* tipo_coda=ConstructQueueVecType();
    QueueObject* coda=queConstruct(tipo_coda);

    DataType*  type=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(type);

    adtSetValue(pointer,curr);
    queEnqueue(coda,pointer);
    free(pointer);

    while(!queEmpty(coda)){
        pointer=queHead(coda);
        curr=adtGetValue(pointer);
        folder(curr->info,elem,NULL);
        queDequeue(coda);
        if(curr->sx!=NULL){adtSetValue(pointer,curr->sx); queEnqueue(coda,pointer);}
        if(curr->dx!=NULL){adtSetValue(pointer,curr->dx); queEnqueue(coda,pointer);}
        adtDestruct(pointer);
    }
    queDestruct(coda);
    DestructVoidDataType(type);
}


DataObject* RicGetNRemoveMin(BSTNode** tree){
    if(*tree!=NULL){
        if((*tree)->sx!=NULL) return RicGetNRemoveMin(&((*tree)->sx));
        else{
            BSTNode *temp = (*tree);
            DataObject* ris=NULL;
            if(temp->dx!=NULL) (*tree) = (*tree)->dx;
            else (*tree)=NULL;
            ris=adtClone(temp->info);
            adtDestruct(temp->info);
            free(temp);
            return ris;
        }

    }

}
void RicRemoveMin(BSTNode** tree){
    if((*tree)->sx!=NULL) RicRemoveMin(&((*tree)->sx));
    else{
        BSTNode* temp = (*tree);
        if(temp->dx!=NULL) (*tree) = (*tree)->dx;
        else (*tree)=NULL;
        adtDestruct(temp->info);
        free(temp);
    }
}

BSTNode* RicGetMax(BSTNode* tree){
    if (tree != NULL) {
        if (tree->dx != NULL)
            return RicGetMax(tree->dx);
    }
    return tree;

}

DataObject* RicGetNRemoveMax(BSTNode** tree){
    if(*tree!=NULL){
        if((*tree)->dx!=NULL) return RicGetNRemoveMax(&((*tree)->dx));
        else{
            BSTNode *temp = (*tree);
            DataObject* ris=NULL;
            if(temp->sx!=NULL) (*tree) = (*tree)->sx;
            else (*tree)=NULL;
            ris=adtClone(temp->info);
            adtDestruct(temp->info);
            free(temp);
            return ris;
        }

    }
}

void RicRemoveMax(BSTNode** tree){
    if((*tree)->dx!=NULL) RicRemoveMax(&((*tree)->dx));
    else{
        BSTNode* temp = (*tree);
        if(temp->sx!=NULL) (*tree) = (*tree)->sx;
        else (*tree)=NULL;
        adtDestruct(temp->info);
        free(temp);
    }
}

BSTNode* RicGetPredecessor(BSTNode* tree,DataObject* elem){
    if(tree!=NULL){
        if(adtCompare(tree->info,elem)==0) return RicGetMax(tree->sx);
        else if(adtCompare(tree->info,elem)==2) return RicGetPredecessor(tree->sx,elem);
        else{
            BSTNode* pred=NULL;
            pred=RicGetPredecessor(tree->dx,elem);
            if(pred!=NULL)return pred;
        }
    }
    return tree;
}

DataObject* RicGetNRemovePredecessor(BSTNode** tree,DataObject* elem){
    DataObject* pred=NULL;
    if(tree!=NULL){
        if(adtCompare((*tree)->info,elem)==0){
            if((*tree)->sx!=NULL) pred=RicGetNRemoveMax(&(*tree)->sx);
            else pred=(*tree)->info;
        }
        else if(adtCompare((*tree)->info,elem)==2) pred=RicGetNRemovePredecessor(&(*tree)->sx,elem);
        else pred=RicGetNRemovePredecessor(&(*tree)->dx,elem);
        if(pred==NULL){
            pred=(*tree)->info;
            if((*tree)->sx!=NULL && (*tree)->dx!=NULL){
                DataObject* min= RicGetNRemoveMin(&(*tree)->dx);
                adtSetValue((*tree)->info,min);
            }
            else {
                BSTNode* temp=NULL;
                if ((*tree)->sx != NULL && (*tree)->dx == NULL) (*tree)=(*tree)->sx;
                else if((*tree)->sx == NULL && (*tree)->dx != NULL) (*tree)=(*tree)->dx;
                else (*tree)=NULL;
                free(temp);
            }
        }
    }
    return pred;
}


DataObject* RicRemovePredecessor(BSTNode** tree,DataObject* elem){
    DataObject* pred=NULL;
    if(tree!=NULL){
        if(adtCompare((*tree)->info,elem)==0){
            if((*tree)->sx!=NULL) pred=RicGetNRemoveMax(&(*tree)->sx);
            else pred=(*tree)->info;
        }
        else if(adtCompare((*tree)->info,elem)==2) {
            pred = RicRemovePredecessor(&(*tree)->sx, elem);
        }
        else if(adtCompare((*tree)->info,elem)==1) {
            pred=RicRemovePredecessor(&(*tree)->dx,elem);
        }
        if(pred==NULL){
            pred=(*tree)->info;
            if((*tree)->sx!=NULL && (*tree)->dx!=NULL){
                DataObject* min= RicGetNRemoveMin(&(*tree)->dx);
                adtSetValue((*tree)->info,min);
            }
            else {
                BSTNode* temp=NULL;
                if ((*tree)->sx != NULL && (*tree)->dx == NULL) (*tree)=(*tree)->sx;
                else if((*tree)->sx == NULL && (*tree)->dx != NULL) (*tree)=(*tree)->dx;
                else (*tree)=NULL;
                free(temp);
            }
        }
    }
    return pred;

}

BSTNode* RicGetSuccessor(BSTNode* tree,DataObject* elem){
    if(tree!=NULL){
        if(adtCompare(tree->info,elem)==0) return RicGetMin(tree->dx);
        else if(adtCompare(tree->info,elem)==1) return RicGetSuccessor(tree->dx,elem);
        else{
            BSTNode* succ=NULL;
            succ=RicGetSuccessor(tree->sx,elem);
            if(succ!=NULL)return succ;
        }
    }
    return tree;
}

DataObject* RicGetNRemoveSuccessor(BSTNode** tree,DataObject* elem){
    DataObject* succ=NULL;
    if(tree!=NULL){
        if(adtCompare((*tree)->info,elem)==0){
            if((*tree)->dx!=NULL) succ=RicGetNRemoveMin(&(*tree)->dx);
            else succ=(*tree)->info;
        }
        else if(adtCompare((*tree)->info,elem)==2) succ=RicGetNRemoveSuccessor(&(*tree)->sx,elem);
        else succ=RicGetNRemoveSuccessor(&(*tree)->dx,elem);
        if(succ==NULL){
            succ=(*tree)->info;
            if((*tree)->sx!=NULL && (*tree)->dx!=NULL){
                DataObject* min= RicGetNRemoveMax(&(*tree)->sx);
                adtSetValue((*tree)->info,min);
            }
            else {
                BSTNode* temp=NULL;
                if ((*tree)->sx != NULL && (*tree)->dx == NULL) (*tree)=(*tree)->sx;
                else if((*tree)->sx == NULL && (*tree)->dx != NULL) (*tree)=(*tree)->dx;
                else (*tree)=NULL;
                free(temp);
            }
        }
    }
    return succ;
}

DataObject* RicRemoveSuccessor(BSTNode** tree,DataObject* elem){
    DataObject* succ=NULL;
    if(tree!=NULL){
        if(adtCompare((*tree)->info,elem)==0){
            if((*tree)->dx!=NULL) succ=RicGetNRemoveMin(&(*tree)->dx);
            else succ=(*tree)->info;
        }
        else if(adtCompare((*tree)->info,elem)==2) succ=RicGetNRemoveSuccessor(&(*tree)->sx,elem);
        else succ=RicGetNRemoveSuccessor(&(*tree)->dx,elem);
        if(succ==NULL){
            succ=(*tree)->info;
            if((*tree)->sx!=NULL && (*tree)->dx!=NULL){
                DataObject* min= RicGetNRemoveMax(&(*tree)->sx);
                adtSetValue((*tree)->info,min);
            }
            else {
                BSTNode* temp=NULL;
                if ((*tree)->sx != NULL && (*tree)->dx == NULL) (*tree)=(*tree)->sx;
                else if((*tree)->sx == NULL && (*tree)->dx != NULL) (*tree)=(*tree)->dx;
                else (*tree)=NULL;
                free(temp);
            }
        }
    }
    return succ;
}

//FUNZIONI AGGIUNTIVE


BSTNode* RicCancRadice(BSTNode* tree){
    if(tree!=NULL){
        if(tree->sx!=NULL && tree->dx!=NULL){
            BSTNode* temp=RicStaccaMinimo(tree->dx,tree);
            adtDestruct(tree->info);
            tree->info=adtClone(temp->info);
            adtDestruct(temp->info);
            free(temp);
        }
        else if(tree->sx==NULL && tree->dx!=NULL){
            BSTNode* temp=tree;
            tree=tree->dx;
            adtDestruct(temp->info);
            free(temp);
        }
        else if(tree->sx!=NULL && tree->dx==NULL ){
            BSTNode* temp=tree;
            tree=tree->sx;
            adtDestruct(temp->info);
            free(temp);
        }
        else {
            adtDestruct(tree->info);
            free(tree);
            tree=NULL;
        }
        return tree;
    }
}

BSTNode* RicStaccaMinimo(BSTNode* figlio,BSTNode* padre){
    if(figlio!=NULL){
        if(figlio->sx!=NULL) return RicStaccaMinimo(figlio->sx,figlio);
        else{
            if(figlio==padre->sx) padre->sx=figlio->dx;
            else padre->dx=figlio->dx;
        }
    }
    return figlio;
}




// ...
