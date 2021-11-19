
#include "stack.h"

/* ************************************************************************** */
StackObject* stkConstruct(StackType* tipo){
	StackObject* stack=(StackObject*)malloc(sizeof(StackObject));
        stack->type=tipo;
        stack->stack=stack->type->stkConstruct();
        return stack;
}

void stkDestruct(StackObject* stack){
stack->type->stkDestruct(stack->stack);
stack->type=NULL;
free(stack);
}

DataObject* stkTop(StackObject* stack){
return stack->type->stkTop(stack->stack);
}

void stkPop(StackObject* stack){
stack->type->stkPop(stack->stack);
}

void stkPush(StackObject* stack,DataObject* elem){
stack->type->stkPush(stack->stack,elem);
}

DataObject* stkTopNPop(StackObject* stack){
DataObject* temp=stack->type->stkTop(stack->stack);
stack->type->stkPop(stack->stack);
return temp;
}

StackObject* stkClone(StackObject* stack){

StackObject* clone=(StackObject*)malloc(sizeof(StackObject));
clone->type=stack->type;
clone->stack=stack->type->stkClone(stack->stack);
return clone;
}

uint stkEqual(StackObject* stack1,StackObject* stack2){

return stack1->type->stkEqual(stack1->stack,stack2->stack);

}

int stkSize(StackObject* stack){
return stack->type->stkSize(stack->stack);
}

uint stkExists(StackObject* stack,DataObject* elem){
return stack->type->stkExists(stack->stack,elem);
}



void stkMap(StackObject* stack,MapFun mapper,void* _){
stack->type->stkMap(stack->stack,mapper,NULL);
}

void stkFold(StackObject* stack,FoldFun folder,void* elem,void*_){
stack->type->stkFold(stack->stack,folder,elem,NULL);
}

void stkClear(StackObject* stack){
stack->stack=stack->type->stkClear(stack->stack);
}
uint stkEmpty(StackObject* stack){
return stack->type->stkEmpty(stack->stack);
}

// ...
