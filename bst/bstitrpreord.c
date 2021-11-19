

#include "bstitrpreord.h"

#include "../stack/vec/stackvec.h"
#include "../bst/itr/bstitr.h"
#include "../adt/pointer/adtpointer.h"

/* ************************************************************************** */
ITRType* ConstructBSTPreOrderIterator(){
ITRType* Preiter =(ITRType*)malloc(sizeof(ITRType));
Preiter->itrconstruct=(void*)(&PreOrderConstruct);
Preiter->itrdestruct=(void*)(&PreOrderDestruct);
Preiter->itrterminated=(void*)(&PreOrderTerminated);
Preiter->itrelement=(void*)(&PreOrderElement);
Preiter->itrsuccessor=(void*)(&PreOrderSuccessor);
return Preiter;
}

void DestructBSTPreOrderIterator(ITRType* Preiter){
Preiter->itrconstruct=(void*)(NULL);
Preiter->itrdestruct=(void*)(NULL);
Preiter->itrterminated=(void*)(NULL);
Preiter->itrelement=(void*)(NULL);
Preiter->itrsuccessor=(void*)(NULL);
free(Preiter);
}

BSTPreOrderIterator* PreOrderConstruct(BSTNode* t){
BSTPreOrderIterator* iter=(BSTPreOrderIterator*)malloc(sizeof(BSTPreOrderIterator));
StackType* tipo_stack=ConstructStackVecType();
DataType* ptr=ConstructVoidDataType();

iter->curr=ItrClone(t);
iter->stack=stkConstruct(tipo_stack);
iter->pointer=ptr;

return iter;
}

void PreOrderDestruct(BSTPreOrderIterator* iter){
assert(iter);
ItrDestruct(iter->curr);
stkDestruct(iter->stack);
free(iter);
}

uint PreOrderTerminated(BSTPreOrderIterator* iter){
if(iter->curr!=NULL)return 0;
else return 1;
}

BSTNode* PreOrderElement(BSTPreOrderIterator* iter){
assert(iter);
return iter->curr;
}

void PreOrderSuccessor(BSTPreOrderIterator* iter){
assert(iter && iter->curr);
DataObject* pointer=adtConstruct(iter->pointer);
adtSetValue(pointer,iter->curr);
stkPush(iter->stack,pointer);
iter->curr=iter->curr->sx;
   while(iter->curr==NULL && stkEmpty(iter->stack)){
       pointer=stkTop(iter->stack);
       iter->curr=adtGetValue(pointer);
       iter->curr=iter->curr->dx;
       stkPop(iter->stack);
   }
}
// ...
