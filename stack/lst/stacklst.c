
#include "stacklst.h"

/* ************************************************************************** */

StackType* ConstructStackLstType(){

StackType* stacklstdatatype=(StackType*)malloc(sizeof(StackType));
stacklstdatatype->stkConstruct=(void*)(&stkConstructLst);
stacklstdatatype->stkDestruct=(void*)(&stkDestructLst);
stacklstdatatype->stkPush=(void*)(&stkPushLst);
stacklstdatatype->stkSize=(void*)(&stkSizeLst);
stacklstdatatype->stkClear=(void*)(&stkClearLst);
stacklstdatatype->stkTopNPop=(void*)(&stkTopNPopLst);
stacklstdatatype->stkTop=(void*)(&stkTopLst);
stacklstdatatype->stkPop=(void*)(&stkPopLst);
stacklstdatatype->stkEmpty=(void*)(&stkEmptyLst);
stacklstdatatype->stkClone=(void*)(&stkCloneLst);
stacklstdatatype->stkEqual=(void*)(&stkEqualLst);
stacklstdatatype->stkExists=(void*)(&stkExistsLst);
stacklstdatatype->stkMap=(void*)(&stkMapLst);
stacklstdatatype->stkFold=(void*)(&stkFoldLst);
return stacklstdatatype;
}

void DestructStackLstType(StackType* stacklstdatatype){
stacklstdatatype->stkConstruct=(void*)(NULL);
stacklstdatatype->stkDestruct=(void*)(NULL);
stacklstdatatype->stkPush=(void*)(NULL);
stacklstdatatype->stkSize=(void*)(NULL);
stacklstdatatype->stkTop=(void*)(NULL);
stacklstdatatype->stkClear=(void*)(NULL);
stacklstdatatype->stkTopNPop=(void*)(NULL);
stacklstdatatype->stkEqual=(void*)(NULL);
stacklstdatatype->stkExists=(void*)(NULL);
stacklstdatatype->stkMap=(void*)(NULL);
stacklstdatatype->stkFold=(void*)(NULL);
free(stacklstdatatype);
}


StackLst* stkConstructLst(){
   StackLst* stack=(StackLst*)malloc(sizeof(StackLst));
   stack->top=NULL;
   stack->key=NULL;
   stack->next=NULL;
   return stack;
}

void stkDestructLst(StackLst* stack){
   assert(stack!=NULL);
   StackLst* temp;
   temp=stack->top;
   if(!stkEmptyLst(stack)){
   do{
     adtDestruct(temp->key);
     free(temp);
     temp=temp->next;
   }while(temp->next==NULL);
}
   free(stack);
}


uint stkEmptyLst(StackLst* stack){
   assert(stack!=NULL);
   if(stack->top==NULL)return 1;
   else return 0;
}

DataObject* stkTopLst(StackLst* stack){
   assert(stack!=NULL);
   return stack->top->key;
}

void stkPushLst(StackLst* stack,DataObject* key){
   StackLst* temp=(StackLst*)malloc(sizeof(StackLst));
   temp->key=adtConstruct(key->op);
   adtSetValue(temp->key,key->dato);
   temp->next=stack->top;
   stack->top=temp;
}

void stkPopLst(StackLst* stack){
   assert(stack!=NULL && stack->top!=NULL);
   StackLst* temp;
   temp=stack->top;
   adtDestruct(temp->key);
   stack->top=stack->top->next;
   temp->next=NULL;
   free(temp);
}

DataObject* stkTopNPopLst(StackLst* stack){
   assert(stack!=NULL && stack->top!=NULL);
   StackLst* temp;
   temp=stack->top;
   DataObject* ret=adtClone(temp->key);
   adtDestruct(temp->key);
   stack->top=stack->top->next;
   temp->next=NULL;
   free(temp);
   return ret;
}

int stkSizeLst(StackLst* stack){
   assert(stack!=NULL);
   StackLst* temp=stack->top;
   int i=0;
   while(temp!=NULL){
        temp=temp->next;
        i++;
   }
   return i;
}

StackLst* stkCloneLst(StackLst* stack){
   assert(stack!=NULL);
   StackLst* clone=(StackLst*)malloc(sizeof(StackLst));
   StackLst* temp;
   uint i=0;
   int size=stkSizeLst(stack);
   DataObject** array_elementi=(DataObject**)malloc(sizeof(DataObject*)*size);
   temp=stack->top;
   while(temp!=NULL){
      array_elementi[i++]=adtClone(temp->key);
      temp=temp->next;
   }
   clone->top=NULL;
   clone->key=NULL;
   clone->next=NULL;
   temp=stack->top;
   while(i)stkPushLst(clone,array_elementi[--i]);
   for(i=size-1;i!=-1;i--)adtDestruct(array_elementi[i]);
   free(array_elementi);
   return clone;
}

void stkClearLst(StackLst* stack){  
if(!stkEmptyLst(stack)){
   StackLst* temp;
   temp=stack->top; 
   while(temp!=NULL){
     adtDestruct(temp->key);
     free(temp);
     temp=temp->next;
   }
}
}


uint stkEqualLst(StackLst* stack1,StackLst* stack2){
if((!stkEmptyLst(stack1)) && (!stkEmptyLst(stack2))){
   if(stkSizeLst(stack1)==stkSizeLst(stack2)){
   StackLst* temp1;
   temp1=stack1->top;
   StackLst* temp2;
   temp2=stack2->top;
   while(temp1!=NULL || temp2!=NULL){
     if(!(adtCompare(temp1->key,temp2->key)))return 0;
     temp1=temp1->next;
     temp2=temp2->next;
     }
   return 1;
   }
}
return 0;
}

uint stkExistsLst(StackLst* stack, DataObject* elem){
if(!stkEmptyLst(stack)){
   StackLst* temp;
   temp=stack->top;
   while(temp!=NULL){
      if(adtCompare(temp->key,elem))return 1;
      temp=temp->next;
   }
}
return 0;
}

void stkMapLst(StackLst* stack,MapFun mapper,void* _){
   assert(stack!=NULL);
   if(!stkEmptyLst(stack)){
   StackLst* temp;
   temp=stack->top;
   while(temp!=NULL){
      mapper(temp->key,NULL);
      temp=temp->next;
   }
}
}

void stkFoldLst(StackLst* stack,FoldFun folder,void* elem,void* _){
   assert(stack!=NULL );
   if(!stkEmptyLst(stack)){
   StackLst* temp;
   temp=stack->top;
   while(temp!=NULL){
      folder(temp->key,elem,NULL);
      temp=temp->next;
   }
}
}


// ...
