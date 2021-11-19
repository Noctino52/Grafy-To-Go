

#include "bstitr.h"

#include "../bstitrpreord.h"
#include "../bstitrinord.h"
#include "../bstitrpostord.h"
#include "../bstitrbreadth.h"
#include "stackvec.h"
#include "stacklst.h"
#include "../pointer/adtpointer.h"

/* ************************************************************************** */
//EQUAL,DESTRUCT,MAP E FOLD CLEAR CHE CHIAMA LA FUNZIONE CONCRETA DESTRUCT
BSTType* ConstructBSTIterative(){
    BSTType* itralgo=(BSTType*)malloc(sizeof(BSTType));
    itralgo->bstdestruct=(void*)(&ItrDestruct);
    itralgo->bstclone=(void*)(&ItrClone);
    itralgo->bstequal=(void*)(&ItrEqual);
    itralgo->bstexists=(void*)(&ItrExists);
    itralgo->bstinsert=(void*)(&ItrInsert);
    itralgo->bstremove=(void*)(&ItrRemove);
    itralgo->bstgetmin=(void*)(&ItrGetMin);
    itralgo->bstgetnremovemin=(void*)(&ItrGetNRemoveMin);
    itralgo->bstremovemin=(void*)(&ItrRemoveMin);
    itralgo->bstgetmax=(void*)(&ItrGetMax);
    itralgo->bstgetnremovemax=(void*)(&ItrGetNRemoveMax);
    itralgo->bstremovemax=(void*)(&ItrRemoveMax);
    itralgo->bstgetpredecessor=(void*)(&ItrGetPredecessor);
    itralgo->bstgetnremovepredecessor=(void*)(&ItrGetNRemovePredecessor);
    itralgo->bstremovepredecessor=(void*)(&ItrRemovePredecessor);
    itralgo->bstgetsuccessor=(void*)(&ItrGetSuccessor);
    itralgo->bstgetnremovesuccessor=(void*)(&ItrGetNRemoveSuccessor);
    itralgo->bstremovesuccessor=(void*)(&ItrRemoveSuccessor);
    itralgo->bstpreordermap=(void*)(&ItrPreOrderMap);
    itralgo->bstpostordermap=(void*)(&ItrPostOrderMap);
    itralgo->bstinordermap=(void*)(&ItrInOrderMap);
    itralgo->bstbreadthmap=(void*)(&ItrBreadthMap);
    itralgo->bstpreorderfold=(void*)(&ItrPreOrderFold);
    itralgo->bstpostorderfold=(void*)(&ItrPostOrderFold);
    itralgo->bstinorderfold=(void*)(&ItrInOrderFold);
    itralgo->bstbreadthfold=(void*)(&ItrBreadthFold);

    return itralgo;
}

void DestructBSTIterative(BSTType* itralgo){
    
    itralgo->bstdestruct=(void*)(NULL);
    itralgo->bstclone=(void*)(NULL);
    itralgo->bstequal=(void*)(NULL);
    itralgo->bstexists=(void*)(NULL);
    itralgo->bstinsert=(void*)(NULL);
    itralgo->bstremove=(void*)(NULL);
    itralgo->bstgetmin=(void*)(NULL);
    itralgo->bstgetnremovemin=(void*)(NULL);
    itralgo->bstremovemin=(void*)(NULL);
    itralgo->bstgetmax=(void*)(NULL);
    itralgo->bstgetnremovemax=(void*)(NULL);
    itralgo->bstremovemax=(void*)(NULL);
    itralgo->bstgetpredecessor=(void*)(NULL);
    itralgo->bstgetnremovepredecessor=(void*)(NULL);
    itralgo->bstremovepredecessor=(void*)(NULL);
    itralgo->bstgetsuccessor=(void*)(NULL);
    itralgo->bstgetnremovesuccessor=(void*)(NULL);
    itralgo->bstremovesuccessor=(void*)(NULL);
    itralgo->bstpreordermap=(void*)(NULL);
    itralgo->bstpostordermap=(void*)(NULL);
    itralgo->bstinordermap=(void*)(NULL);
    itralgo->bstbreadthmap=(void*)(NULL);
    itralgo->bstpreorderfold=(void*)(NULL);
    itralgo->bstpostorderfold=(void*)(NULL);
    itralgo->bstinorderfold=(void*)(NULL);
    itralgo->bstbreadthfold=(void*)(NULL);
    free(itralgo);
}
void ItrDestruct(BSTNode* tree){
    ItrClear(tree);
    free(tree);
}

BSTNode* ItrClone(BSTNode* tree){
    StackType* type =ConstructStackVecType();
    DataType* prt=ConstructVoidDataType();
    StackObject* stack1= stkConstruct(type);
    StackObject* stack2= stkConstruct(type);
    DataObject* pointer1=adtConstruct(prt);
    DataObject* pointer2=adtConstruct(prt);
    DataObject* pointer3=NULL;
    DataObject* pointer4=NULL;
    BSTNode* curr1=tree;
    BSTNode* curr2=tree;
    BSTNode* ret=NULL;
    BSTNode* last=NULL;
    while(stkSize(stack1)!=0  || curr1!=NULL){
        if(curr1!=NULL){
            curr2=newNode(curr1->info);
            adtSetValue(pointer1,curr1);
            stkPush(stack1,pointer1);
            adtSetValue(pointer2,curr2);
            stkPush(stack2,pointer2);
            curr1=curr1->sx;
            curr2=NULL;
        }
        else{
            pointer3=stkTop(stack1);
            curr1=adtGetValue(pointer3);
            pointer4=stkTop(stack2);
            curr2=adtGetValue(pointer4);
            if(curr1->dx!=NULL && last!=curr1->dx){
                curr2->sx=ret;
                curr1=curr1->dx;
                curr2=NULL;
            }
            else
            {
                if(curr1->dx==NULL){curr2->sx=ret;}
                else {curr2->dx=ret;}
                last=curr1;
                stkPop(stack1);
                stkPop(stack2);
                curr1=NULL;
            }
            ret=curr2;
        }
    }
    DestructVoidDataType(prt);
    stkDestruct(stack1);
    stkDestruct(stack2);
    DestructStackVecType(type);
    return ret;
}

BSTNode* ItrInsert(BSTNode* tree,DataObject* elem){
    BSTNode *padre=NULL;
    BSTNode *curr=tree;
    BSTNode *new=NULL;
    while(curr!=NULL)
    {
        padre=curr;
        if(adtCompare(elem,curr->info)==0)return NULL;
        else if(adtCompare(elem,curr->info)==-1)curr=curr->sx;
        else curr=curr->dx;


    }
    new =(BSTNode*)malloc(sizeof(BSTNode));
    new->info=adtClone(elem);
    new->dx=NULL;
    new->sx=NULL;

    if(padre==NULL)tree=new;
    else
    {
        if(adtCompare(elem,padre->info)==-1)padre->sx=new;
        else padre->dx=new;
    }
    return tree;
}

uint ItrExists(BSTNode* tree,DataObject* elem){
    BSTNode* curr=tree;
    while(curr!=NULL){
        if(adtCompare(elem,curr->info)==1) curr=curr->sx;
        else if(adtCompare(elem,curr->info)==2)curr=curr->dx;
        else return 0;
    }
    return 1;
}

uint ItrEqual(BSTNode* tree1,BSTNode* tree2){
    ITRObject *curr1=itrConstruct(ConstructBSTInOrderIterator(),tree1);
    ITRObject *curr2=itrConstruct(ConstructBSTInOrderIterator(),tree2);
    while(!itrTerminated(curr1) && !itrTerminated(curr2))
    {
        BSTNode* temp1=itrElement(curr1);
        BSTNode* temp2=itrElement(curr2);
        if(adtCompare(temp1->info,temp2->info)==0)
        {
            itrSuccessor(curr1);
            itrSuccessor(curr2);
        }else
        {
            return false;
        }
    }

    return true;
}

void ItrRemove(BSTNode** tree,DataObject* elem){
    
    BSTNode *padre=NULL;
    BSTNode *curr=(*tree);
    BSTNode *temp=NULL;
    while(curr!=NULL && adtCompare(curr->info,elem)!=0)
    {
        padre=curr;
        if(adtCompare(curr->info,elem)==1)
        {
            curr=curr->sx;
        }else
        {
            curr=curr->dx;
        }
    }
    if(curr!= NULL)
    {
        temp=ItrCancRadice(curr);
        if(padre==NULL)
        {
            (*tree)=temp;
        }else if(curr==padre->sx)
        {
            padre->sx=temp;
        }else
        {
            padre->dx=temp;
        }
    }
}

BSTNode* ItrGetMin(BSTNode* tree){
    BSTNode* curr=tree;
    while(curr->sx!=NULL) curr=curr->sx;
    return curr;
}
DataObject* ItrGetNRemoveMin(BSTNode** tree){
    BSTNode* curr=(*tree);
    BSTNode* padre=NULL;
    while(curr->sx!=NULL){padre=curr; curr=curr->sx;}
    DataObject* temp=adtClone(curr->info);
    padre->sx=ItrCancRadice(curr);
    return temp;
}
void ItrRemoveMin(BSTNode** tree){
    BSTNode* curr=(*tree);
    BSTNode* padre=NULL;
    while(curr->sx!=NULL){padre=curr; curr=curr->sx;}
    DataObject* temp=adtClone(curr->info);
    padre->sx=ItrCancRadice(curr);
}

BSTNode* ItrGetMax(BSTNode* tree){
    BSTNode* curr=tree;
    while(curr->dx!=NULL) curr=curr->dx;
    return curr;
}
DataObject* ItrGetNRemoveMax(BSTNode** tree){
    BSTNode* curr=(*tree);
    BSTNode* padre=NULL;
    while(curr->dx!=NULL){padre=curr; curr=curr->dx;}
    DataObject* temp=adtClone(curr->info);
    padre->dx=ItrCancRadice(curr);
    return temp;
}

void ItrRemoveMax(BSTNode** tree){
    BSTNode* curr=(*tree);
    BSTNode* padre=NULL;
    while(curr->dx!=NULL){padre=curr; curr=curr->dx;}
    DataObject* temp=adtClone(curr->info);
    padre->dx=ItrCancRadice(curr);
}

BSTNode* ItrGetPredecessor(BSTNode* tree,DataObject* elem){
    BSTNode *curr = tree;
    BSTNode *padre = NULL;
    BSTNode *temp = NULL;
    while (curr != NULL && adtCompare(curr->info, elem) != 0) {
        if (adtCompare(curr->info, elem) == 2) curr = curr->sx;
        else if (adtCompare(curr->info, elem) == 1) {
            temp = curr;
            curr = curr->dx;
        }
    }
    if (curr != NULL && curr->sx != NULL)temp = ItrGetMax(curr->sx);
    return temp;
}

DataObject* ItrGetNRemovePredecessor(BSTNode** tree,DataObject* elem){
    BSTNode *curr = (*tree);
    BSTNode *temp = NULL;
    while (curr != NULL && adtCompare(curr->info, elem) != 0) {
        if (adtCompare(curr->info, elem) == 2) curr = curr->sx;
        else if (adtCompare(curr->info, elem) == 1) {
            temp = curr;
            curr = curr->dx;
        }
    }
    if (curr != NULL && curr->sx != NULL)temp = ItrGetMax(curr->sx);
    DataObject* ris=NULL;
    if(temp!=NULL) {
        ris=adtClone(temp->info);
        ItrRemove(tree, temp->info);
    }
    return ris;
}

DataObject* ItrRemovePredecessor(BSTNode** tree,DataObject* elem){
    BSTNode *curr = (*tree);
    BSTNode *temp = NULL;
    while (curr != NULL && adtCompare(curr->info, elem) != 0) {
        if (adtCompare(curr->info, elem) == 2) curr = curr->sx;
        else if (adtCompare(curr->info, elem) == 1) {
            temp = curr;
            curr = curr->dx;
        }
    }
    if (curr != NULL && curr->sx != NULL)temp = ItrGetMax(curr->sx);
    if(temp!=NULL) {
        ItrRemove(tree, temp->info);
    }
    else return NULL;
}

BSTNode* ItrGetSuccessor(BSTNode* tree,DataObject* elem) {
    BSTNode *curr = tree;
    BSTNode *padre = NULL;
    BSTNode *temp = NULL;
    while (curr != NULL && adtCompare(curr->info, elem) != 0) {
        if (adtCompare(curr->info, elem) == 1) curr = curr->dx;
        else if (adtCompare(curr->info, elem) == 2) {
            temp = curr;
            curr = curr->sx;
        }
    }
    if (curr != NULL && curr->dx != NULL)temp = ItrGetMin(curr->dx);
    return temp;
}

DataObject* ItrGetNRemoveSuccessor(BSTNode** tree,DataObject* elem){
    BSTNode *curr = (*tree);
    BSTNode *padre = NULL;
    BSTNode *temp = (*tree);
    while (curr != NULL && adtCompare(curr->info, elem)!=0) {
        if (adtCompare(curr->info, elem) == 1){
            padre=curr;
            curr=curr->dx;
        }
        else if (adtCompare(curr->info, elem) == 2) {
            padre=curr;
            temp = curr;
            curr = curr->sx;
        }
    }
    if (curr != NULL && curr->dx != NULL)temp = ItrGetMin(curr->dx);
    DataObject* ris=NULL;
    if(temp!=NULL) {
        ris=adtClone(temp->info);
        ItrRemove(tree, temp->info);
    }
    return ris;
}

DataObject* ItrRemoveSuccessor(BSTNode** tree,DataObject* elem){
    BSTNode *curr = (*tree);
    BSTNode *padre = NULL;
    BSTNode *temp = (*tree);
    while (curr != NULL && adtCompare(curr->info, elem)!=0) {
        if (adtCompare(curr->info, elem) == 1){
            padre=curr;
            curr=curr->dx;
        }
        else if (adtCompare(curr->info, elem) == 2) {
            padre=curr;
            temp = curr;
            curr = curr->sx;
        }
    }
    if (curr != NULL && curr->dx != NULL)temp = ItrGetMin(curr->dx);
    if(temp!=NULL) {
        ItrRemove(tree, temp->info);
    }
    else return NULL;
}

void ItrPreOrderMap(BSTNode* tree,MapFun mapper){
    ITRType* preorder=ConstructBSTPreOrderIterator();
    ITRObject* iter=itrConstruct(preorder,tree);
    printf("Iteratore creato con successo");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);

    BSTNode* curr=NULL;
    curr=itrElement(iter);
    mapper(curr->info,NULL);
    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)mapper(curr->info,NULL);
    }

}

void ItrPreOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem){
    ITRType* preorder=ConstructBSTPreOrderIterator();
    ITRObject* iter=itrConstruct(preorder,tree);
    printf("Iteratore creato con successo");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);

    BSTNode* curr=NULL;
    curr=itrElement(iter);
    folder(curr->info,elem,NULL);
    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)folder(curr->info,elem,NULL);
    }

}

void ItrPostOrderMap(BSTNode* tree,MapFun mapper){
    ITRType* postorder=ConstructBSTPostOrderIterator();
    ITRObject* iter=itrConstruct(postorder,tree);
    printf("Iteratore creato con successo \n");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);

    BSTNode* curr=NULL;
    curr=itrElement(iter);
    mapper(curr->info,NULL);
    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)mapper(curr->info,NULL);
    }
    itrDestruct(iter);
    DestructBSTPostOrderIterator(postorder);

}

void ItrPostOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem){
    ITRType* postorder=ConstructBSTPostOrderIterator();
    ITRObject* iter=itrConstruct(postorder,tree);
    printf("Iteratore creato con successo \n");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);

    BSTNode* curr=NULL;
    curr=itrElement(iter);
    folder(curr->info,elem,NULL);
    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)folder(curr->info,elem,NULL);
    }

}

void ItrInOrderMap(BSTNode* tree,MapFun mapper){
    ITRType* inorder=ConstructBSTInOrderIterator();
    ITRObject* iter=itrConstruct(inorder,tree);
    printf("Iteratore creato con successo \n");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);

    BSTNode* curr=NULL;
    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)mapper(curr->info,NULL);
    }

}

void ItrInOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem){
    ITRType* inorder=ConstructBSTInOrderIterator();
    ITRObject* iter=itrConstruct(inorder,tree);
    printf("Iteratore creato con successo \n");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);

    BSTNode* curr=NULL;
    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)folder(curr->info,elem,NULL);
    }
}

void ItrBreadthMap(BSTNode* tree,MapFun mapper){
    ITRType* breadthorder=ConstructBSTBreadthOrderIterator();
    ITRObject* iter=itrConstruct(breadthorder,tree);
    printf("Iteratore creato con successo \n");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);
    DataObject* pointer1=adtConstruct(pnt);
    BSTNode* curr=NULL;

    adtSetValue(pointer1,itrElement(iter));
    curr=adtGetValue(pointer1);
    mapper(curr->info,NULL);

    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)mapper(curr->info,NULL);
    }

}

void ItrBreadthFold(BSTNode* tree,FoldFun folder,DataObject* elem){
    ITRType* breadthorder=ConstructBSTBreadthOrderIterator();
    ITRObject* iter=itrConstruct(breadthorder,tree);
    printf("Iteratore creato con successo \n");
    DataType* pnt=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(pnt);
    DataObject* pointer1=adtConstruct(pnt);
    BSTNode* curr=NULL;

    adtSetValue(pointer1,itrElement(iter));
    curr=adtGetValue(pointer1);
    folder(curr->info,elem,NULL);

    while(!itrTerminated(iter)){
        pointer=itrSuccessor(iter);
        curr=adtGetValue(pointer);
        if(curr!=NULL)folder(curr->info,elem,NULL);
    }
}

//FUNZIONI AGGIUNTIVE

BSTNode* ItrCancRadice(BSTNode* tree){
        BSTNode *temp = NULL;
        if (tree != NULL) {
            if (tree->sx != NULL && tree->dx != NULL) {
                temp = tree;
                tree = ItrStaccaMinimo(tree, tree->dx);

            } else {
                temp = tree;
                if (tree->dx != NULL) {
                    tree = tree->dx;
                } else {
                    tree = tree->sx;
                }
            }
        }
        if (temp != NULL) {
            adtDestruct(temp->info);
            free(temp);
        }
    return tree;
}

BSTNode* ItrStaccaMinimo(BSTNode* figlio,BSTNode* padre){
    if(figlio!=NULL){
        if(figlio->sx!=NULL) return ItrStaccaMinimo(figlio->sx,figlio);
        else{
            if(figlio==padre->sx) padre->sx=figlio->dx;
            else padre->dx=figlio->dx;
        }
    }
    return figlio;
}

void ItrClear(BSTNode* tree)
{
    ITRType* type=ConstructBSTPostOrderIterator();
    ITRObject* iter=itrConstruct(type,tree);
    while(!itrTerminated(iter))
    {
        BSTNode *temp=itrElement(iter);
        adtDestruct(temp->info);
        free(temp);
        itrSuccessor(iter);
    }
    itrDestruct(iter);
    DestructBSTPostOrderIterator(type);
}

// ...
