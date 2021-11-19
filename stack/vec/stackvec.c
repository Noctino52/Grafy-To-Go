
#include "stackvec.h"

/* ************************************************************************** */

StackType* ConstructStackVecType(){

StackType* stackvecdatatype=(StackType*)malloc(sizeof(StackType));
stackvecdatatype->stkConstruct=(void*)(&stkConstructVec);
stackvecdatatype->stkDestruct=(void*)(&stkDestructVec);
stackvecdatatype->stkPush=(void*)(&stkPushVec);
stackvecdatatype->stkSize=(void*)(&stkSizeVec);
stackvecdatatype->stkClear=(void*)(&stkClearVec);
stackvecdatatype->stkTopNPop=(void*)(&stkTopNPopVec);
stackvecdatatype->stkTop=(void*)(&stkTopVec);
stackvecdatatype->stkPop=(void*)(&stkPopVec);
stackvecdatatype->stkEmpty=(void*)(&stkEmptyVec);
stackvecdatatype->stkClone=(void*)(&stkCloneVec);
stackvecdatatype->stkEqual=(void*)(&stkEqualVec);
stackvecdatatype->stkExists=(void*)(&stkExistsVec);
stackvecdatatype->stkMap=(void*)(&stkMapVec);
stackvecdatatype->stkFold=(void*)(&stkFoldVec);
return stackvecdatatype;

}

void DestructStackVecType(StackType* stackvecdatatype){
stackvecdatatype->stkConstruct=(void*)(NULL);
stackvecdatatype->stkDestruct=(void*)(NULL);
stackvecdatatype->stkPush=(void*)(NULL);
stackvecdatatype->stkSize=(void*)(NULL);
stackvecdatatype->stkTop=(void*)(NULL);
stackvecdatatype->stkClear=(void*)(NULL);
stackvecdatatype->stkTopNPop=(void*)(NULL);
stackvecdatatype->stkEqual=(void*)(NULL);
stackvecdatatype->stkExists=(void*)(NULL);
stackvecdatatype->stkMap=(void*)(NULL);
stackvecdatatype->stkFold=(void*)(NULL);
free(stackvecdatatype);
}

/* ************************************************************************** */
StackVec* stkConstructVec(){
	StackVec* stack=(StackVec*)malloc(sizeof(StackVec));
	stack->dim=0;
	stack->key=(DataObject**)malloc(sizeof(DataObject**));
	stack->top=0;
	return stack;
}


int stkSizeVec(StackVec* stack)
{
    assert(stack!=NULL);
    return stack->top;
}

void stkReallocVec(StackVec* stack,uint nuova_dim)
{
      assert(stack!=NULL);
      if(stack->dim==0){
         stack->dim=2;
         stack->key=(DataObject**)realloc(stack->key,(sizeof(DataObject*)*2));        
      }
      else{
         stack->dim=nuova_dim/sizeof(DataObject*);
         stack->key=(DataObject**)realloc(stack->key,(sizeof(DataObject*)*stack->dim));
      }

}

void stkPushVec(StackVec* stack,DataObject* key){
        assert(stack!=NULL && key!=NULL);
	if(stack->dim==0 || stack->dim < stack->top+1) stkReallocVec(stack,stack->dim*(sizeof(DataObject*)*2));
        stack->key[stack->top]=adtConstruct(key->op);
        adtSetValue(stack->key[stack->top],key->dato);
        stack->top++;
}

void stkDestructVec(StackVec* stack){

  assert(stack!=NULL);

  while(stack->top!=0)adtDestruct(stack->key[--stack->top]);
  free(stack->key);
  free(stack);
}

DataObject* stkTopVec(StackVec* stack){
  assert(stack!=NULL && stack->top!=0);
  return stack->key[stack->top-1];
}

void stkPopVec(StackVec* stack){
  assert(stack!=NULL && stack->top!=0 && stack->key[stack->top-1]!=NULL);

  adtDestruct(stack->key[--stack->top]);
  if(stack->top==0){
     stack->dim=0;
     stack->key=(DataObject**)realloc(stack->key,sizeof(DataObject**));
  }
  if(stack->dim/2 == stack->top) stkReallocVec(stack,(stack->dim/2)*(sizeof(DataObject*)));
}

DataObject* stkTopNPopVec(StackVec* stack){

DataObject* temp=adtClone(stack->key[stack->top-1]);
stkPopVec(stack);
return temp;
}

uint stkEmptyVec(StackVec* stack){
  assert(stack!=NULL);
  if(stack->top==0) return 0;
  else return 1;
}

StackVec* stkCloneVec(StackVec* stack){
   assert(stack!=NULL);

   StackVec* clone=stkConstructVec();
   uint i;
   for(i=0;i<stack->top;i++){
     stkPushVec(clone,stack->key[i]);
   }
   return clone;
}
uint stkEqualVec(StackVec* stack1,StackVec* stack2){
   assert(stack1!=NULL && stack1->key!=NULL && stack2!=NULL && stack2->key!=NULL );

   if(stack1->dim != stack2->dim || stack1->top != stack2->top) return 0;
   uint i= stack1->top-1;
   while(i!=-1){
        if((adtCompare(stack1->key[i],stack2->key[i]))==0) return 0;
        i--;
   }
   return 1;

}

uint stkExistsVec(StackVec* stack, DataObject* elem){

   uint i= stack->top-1;
   while(i!=-1){
        if(adtCompare(stack->key[i],elem)) return 1;
        i--;
   }
   return 0;

}

void stkMapVec(StackVec* stack,MapFun mapper,void* _){
   assert(stack!=NULL && stack->key!=NULL);
   
   uint i;
   for(i=0;i<stack->top;i++) mapper(stack->key[i],NULL);

}

void stkFoldVec(StackVec* stack,FoldFun folder,void* elem,void* _){
   assert(stack!=NULL && stack->key!=NULL && elem!=NULL);
   uint i;
   for(i=0;i<stack->top;i++) folder(stack->key[i],elem,NULL);

}

void stkClearVec(StackVec* stack){
  assert(stack!=NULL && stack->key!=NULL);
  uint i;
  for(i=0;i<stack->top;i++) adtDestruct(stack->key[i]);
}

// ...
