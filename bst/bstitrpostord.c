
#include "bstitrpostord.h"

#include "../stack/vec/stackvec.h"
#include "../bst/itr/bstitr.h"
#include "../adt/pointer/adtpointer.h"
#include "../stack/lst/stacklst.h"
#include "../bst/rec/bstrec.h"

BSTNode* getMinLeaf(BSTPostOrderIterator *pBSTPostOrderIterator,BSTNode *pNode) {
    while (pNode != NULL) {

        if (pNode->dx == NULL && pNode->sx == NULL) {
            return pNode;
        }
        DataObject *wDataObj = adtConstruct(ConstructVoidDataType());
        adtSetValue(wDataObj, pNode);
        stkPush(pBSTPostOrderIterator->stack, wDataObj);
        if (pNode->sx != NULL) {
            pNode = pNode->sx;
        } else if (pNode->dx != NULL) {
            pNode = pNode->dx;
        }


    }
}
/* ************************************************************************** */
ITRType* ConstructBSTPostOrderIterator(){
    ITRType* Postiter =(ITRType*)malloc(sizeof(ITRType));
    Postiter->itrconstruct=(void*)(&PostOrderConstruct);
    Postiter->itrdestruct=(void*)(&PostOrderDestruct);
    Postiter->itrterminated=(void*)(&PostOrderTerminated);
    Postiter->itrelement=(void*)(&PostOrderElement);
    Postiter->itrsuccessor=(void*)(&PostOrderSuccessor);
    return Postiter;
}

void DestructBSTPostOrderIterator(ITRType* Postiter){
    Postiter->itrconstruct=(void*)(NULL);
    Postiter->itrdestruct=(void*)(NULL);
    Postiter->itrterminated=(void*)(NULL);
    Postiter->itrelement=(void*)(NULL);
    Postiter->itrsuccessor=(void*)(NULL);
    free(Postiter);
}
BSTPostOrderIterator* PostOrderConstruct(BSTNode* t){
    BSTPostOrderIterator* iter=(BSTPostOrderIterator*)malloc(sizeof(BSTPostOrderIterator));
    StackType* tipo_stack=ConstructStackVecType();
    iter->curr=ItrClone(t);
    iter->stack=stkConstruct(tipo_stack);
    DataType* ptr=ConstructVoidDataType();
    DataObject* pointer=adtConstruct(ptr);
    iter->pointer=pointer->op;

    while(iter->curr->sx!=NULL || iter->curr->dx!=NULL){
        adtSetValue(pointer,iter->curr);
        stkPush(iter->stack,pointer);
        if(iter->curr->sx!=NULL) iter->curr=iter->curr->sx;
        else if(iter->curr->dx!=NULL) iter->curr=iter->curr->dx;
    }
    adtDestruct(pointer);
    return iter;
}

void PostOrderDestruct(BSTPostOrderIterator* iter){
    DataObject* pointer=adtConstruct(iter->pointer);
    DataObject* pointer2=adtConstruct(iter->pointer);
    adtSetValue(pointer2,iter->curr);
    stkPush(iter->stack,pointer2);
    while(iter->curr!=NULL)
    {
        if (iter->curr->sx)
        {
            DataObject *wDataObj =adtConstruct(iter->pointer);
            adtSetValue(wDataObj,iter->curr->sx);
            stkPush(iter->stack,wDataObj);
        }
        if (iter->curr->dx)
        {
            DataObject *wDataObj =adtConstruct(iter->pointer);
            adtSetValue(wDataObj,iter->curr->dx);
            stkPush(iter->stack,wDataObj);
        }
        adtSetValue(pointer2,stkTop(iter->stack));
        iter->curr=adtGetValue(pointer2);
        adtDestruct(iter->curr->info);
        stkPop(iter->stack);
        DestructVoidDataType(iter->pointer);
        free(iter->curr);
        free(iter);
    }
}

uint PostOrderTerminated(BSTPostOrderIterator* iter){
    if(iter->curr!=NULL)return 0;
    else return 1;
}

BSTNode* PostOrderElement(BSTPostOrderIterator* iter){
    assert(iter);
    return iter->curr;
}

void PostOrderSuccessor(BSTPostOrderIterator* iter){
    
    BSTNode* wLast=iter->curr;
    DataObject* wNodeStack=NULL;
    DataObject* wNodeStack2=NULL;
    while(stkEmpty(iter->stack) || iter->curr!=NULL)
    {
        if(stkEmpty(iter->stack))
        {
            if(iter->curr!=NULL)
            {
                wNodeStack=stkTop(iter->stack);
                iter->curr=adtGetValue(wNodeStack);

                if(wLast==iter->curr->dx)
                {
                    stkPop(iter->stack);
                    wLast=iter->curr;
                    break;

                }else
                {

                    if(iter->curr->sx!=NULL && wLast!=iter->curr->sx)
                    {
                        iter->curr=getMinLeaf(iter,iter->curr->sx);
                        break;
                    }else
                    {
                        iter->curr=NULL;
                    }
                }
            }else
            {
                wNodeStack2=stkTop(iter->stack);
                iter->curr=adtGetValue(wNodeStack2);

                if(iter->curr->dx!=NULL && wLast!=iter->curr->dx)
                {
                    iter->curr=getMinLeaf(iter,iter->curr->dx);
                    break;
                }else
                {
                    stkPop(iter->stack);
                    break;
                }
            }

        }else
        {
            iter->curr=NULL;
        }
        wLast=iter->curr;

    }
}
// ...