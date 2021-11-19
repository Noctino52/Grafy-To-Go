

#include "bstitrinord.h"

#include "../stack/vec/stackvec.h"
#include "../bst/itr/bstitr.h"
#include "../adt/pointer/adtpointer.h"

/* ************************************************************************** */

/* ************************************************************************** */
ITRType* ConstructBSTInOrderIterator(){
    ITRType* Initer =(ITRType*)malloc(sizeof(ITRType));
    Initer->itrconstruct=(void*)(&InOrderConstruct);
    Initer->itrdestruct=(void*)(&InOrderDestruct);
    Initer->itrterminated=(void*)(&InOrderTerminated);
    Initer->itrelement=(void*)(&InOrderElement);
    Initer->itrsuccessor=(void*)(&InOrderSuccessor);
    return Initer;
}

void DestructBSTInOrderIterator(ITRType* Initer){
    Initer->itrconstruct=(void*)(NULL);
    Initer->itrdestruct=(void*)(NULL);
    Initer->itrterminated=(void*)(NULL);
    Initer->itrelement=(void*)(NULL);
    Initer->itrsuccessor=(void*)(NULL);
    free(Initer);
}


BSTInOrderIterator* InOrderConstruct(BSTNode* t){
    BSTInOrderIterator* iter=(BSTInOrderIterator*)malloc(sizeof(BSTInOrderIterator));
    StackType* tipo_stack=ConstructStackVecType();
    iter->curr=ItrClone(t);
    iter->stack=stkConstruct(tipo_stack);
    DataType* ptr=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(ptr);
    iter->pointer=pointer->op;

    while(iter->curr->sx!=NULL){
        adtSetValue(pointer,iter->curr);
        stkPush(iter->stack,pointer);
        iter->curr=iter->curr->sx;
    }
    iter->nextDX=iter->curr;
    return iter;
}

void InOrderDestruct(BSTInOrderIterator* iter){
    assert(iter);
    ItrDestruct(iter->curr);
    stkDestruct(iter->stack);
    free(iter);
}

uint InOrderTerminated(BSTInOrderIterator* iter){
    if(iter->curr!=NULL)return 0;
    else return 1;
}

BSTNode* InOrderElement(BSTInOrderIterator* iter){
    assert(iter);
    return iter->curr;
}

void InOrderSuccessor(BSTInOrderIterator* iter){

    iter->curr =iter->nextDX;

    while (stkEmpty(iter->stack) || iter->curr != NULL)
    {

        if(iter->curr!=NULL)
        {
            DataObject *wDataObj =adtConstruct(ConstructVoidDataType());
            adtSetValue(wDataObj,iter->curr);
            stkPush(iter->stack,wDataObj);
            iter->curr=iter->curr->sx;
        }else
        {
            DataObject *wNodeStack=stkTop(iter->stack);
            iter->curr=adtGetValue(wNodeStack);
            iter->nextDX=iter->curr->dx;
            stkPop(iter->stack);
            break;
        }

    }
}
// ...
