

#include "itr.h"
#include "../adt/pointer/adtpointer.h"

/* ************************************************************************** */
ITRObject* itrConstruct(ITRType* tipo,void* dato){
ITRObject* iter=(ITRObject*)malloc(sizeof(ITRObject));
iter->type=tipo;
iter->dato=iter->type->itrconstruct(dato);
}

void itrDestruct(ITRObject* iter){
iter->type->itrdestruct(iter->dato);
iter->type=NULL;
free(iter);
}

uint itrTerminated(ITRObject* iter){
assert(iter!=NULL && iter->dato!=NULL);
if(iter->type->itrterminated(iter->dato)) return 1;
else return 0;
}

void* itrElement(ITRObject* iter){
assert(!iter->type->itrterminated(iter->dato));
return iter->type->itrelement(iter->dato);
}

void* itrSuccessor(ITRObject* iter){
assert(!(iter->type->itrterminated(iter->dato)));
DataType* ptr=ConstructVoidDataType();
DataObject* temp= adtConstruct(ptr);

iter->type->itrsuccessor(iter->dato);
adtSetValue(temp,iter->type->itrelement(iter->dato));
return temp;
}

// ...
