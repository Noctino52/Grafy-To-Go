
#include "adt.h"

/* ************************************************************************** */
DataObject* adtConstruct(DataType* type){
DataObject* object=(DataObject*)malloc(sizeof(DataObject));
object->op=type;
object->dato=object->op->adtConstruct();
return object;
}

void adtDestruct(DataObject* object){

object->op->adtDestruct(object->dato);
object->op=NULL;
free(object);
}

void* adtGetValue(DataObject* object){
return object->op->adtGetValue(object->dato);
}

void adtSetValue(DataObject* object,void* dato){
object->dato=object->op->adtSetValue(object->dato,dato);
}

void adtRandomValue(DataObject* object){
object->op->adtRandomValue(object->dato);
}

void adtReadFromKeyboard(DataObject* object){
object->op->adtReadFromKeyBoard(object->dato);
}

void adtWriteToMonitor(DataObject* object){

object->op->adtWriteToMonitor(object->dato);
}

DataObject* adtClone(DataObject* object){
DataObject* clone=(DataObject*)malloc(sizeof(DataObject));
clone->op=object->op;
clone->dato=object->op->adtClone(object->dato);
return clone;
}

uint adtCompare(DataObject* object1,DataObject* object2){
if(object2->op!=object1->op)return 1;
return object2->op->adtCompare(object1->dato,object2->dato);
}

// ...
