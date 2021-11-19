

#include "bstitrbreadth.h"

#include "../queue/vec/queuevec.h"
#include "../stack/vec/stackvec.h"
#include "../bst/itr/bstitr.h"
#include "../adt/pointer/adtpointer.h"

/* ************************************************************************** */
ITRType* ConstructBSTBreadthOrderIterator(){
    ITRType* Breadthiter =(ITRType*)malloc(sizeof(ITRType));
    Breadthiter->itrconstruct=(void*)(&BreadthOrderConstruct);
    Breadthiter->itrdestruct=(void*)(&BreadthOrderDestruct);
    Breadthiter->itrterminated=(void*)(&BreadthOrderTerminated);
    Breadthiter->itrelement=(void*)(&BreadthOrderElement);
    Breadthiter->itrsuccessor=(void*)(&BreadthOrderSuccessor);
    return Breadthiter;
}

void DestructBSTBreadthOrderIterator(ITRType* Breadthiter){
    Breadthiter->itrconstruct=(void*)(NULL);
    Breadthiter->itrdestruct=(void*)(NULL);
    Breadthiter->itrterminated=(void*)(NULL);
    Breadthiter->itrelement=(void*)(NULL);
    Breadthiter->itrsuccessor=(void*)(NULL);
    free(Breadthiter);
}


BSTBreadthOrderIterator* BreadthOrderConstruct(BSTNode* t){
    BSTBreadthOrderIterator* iter=(BSTBreadthOrderIterator*)malloc(sizeof(BSTBreadthOrderIterator));
    QueueType* tipo_queue=ConstructQueueVecType();
    iter->curr=ItrClone(t);
    iter->queue=queConstruct(tipo_queue);
    DataType* ptr=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(ptr);
    iter->pointer=ptr;
    iter->height=0;
    return iter;
}

void BreadthOrderDestruct(BSTBreadthOrderIterator* iter){
    assert(iter);
    ItrDestruct(iter->curr);
    queDestruct(iter->queue);
    free(iter);
}

uint BreadthOrderTerminated(BSTBreadthOrderIterator* iter){
    if(iter->curr!=NULL)return 0;
    else return 1;
}

BSTNode* BreadthOrderElement(BSTBreadthOrderIterator* iter){
    assert(iter);
    return iter->curr;
}

void BreadthOrderSuccessor(BSTBreadthOrderIterator* iter){
    BSTNode * last=iter->curr;

    while (iter->curr!=NULL || !queEmpty(iter->queue))
    {
        if(iter->curr!=NULL)
        {
            if(iter->curr->sx!=NULL)
            {

                DataObject *wDataObj =adtConstruct(iter->pointer);
                adtSetValue(wDataObj,iter->curr->sx);
                queEnqueue(iter->queue,wDataObj);

            }
            if(iter->curr->dx!=NULL)
            {
                DataObject *wDataObj2 =adtConstruct(iter->pointer);
                adtSetValue(wDataObj2,iter->curr->dx);
                queEnqueue(iter->queue,wDataObj2);
            }
            iter->curr=NULL;
        }else
        {

            DataObject *wDataNode=queHeadNDequeue(iter->queue);
            iter->curr=adtGetValue(wDataNode);
            last=iter->curr;
            break;
        }


    }
}



// ...
