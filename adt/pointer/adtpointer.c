
#include "adtpointer.h"

/* ************************************************************************** */
DataType* ConstructVoidDataType(){

    DataType* voiddatatype=(DataType*)malloc(sizeof(DataType));
    voiddatatype->adtConstruct=(void*)(&CreateVoid);
    voiddatatype->adtDestruct=(void*)(&DestructVoid);
    voiddatatype->adtGetValue=(void*)(&GetValueVoid);
    voiddatatype->adtSetValue=(void*)(&SetValueVoid);
    voiddatatype->adtRandomValue=(void*)(&RandomValueVoid);
    voiddatatype->adtReadFromKeyBoard=(void*)(&ReadFromKeyBoardVoid);
    voiddatatype->adtWriteToMonitor=(void*)(&WriteToMonitorVoid);
    voiddatatype->adtClone=(void*)(&CloneVoid);
    voiddatatype->adtCompare=(void*)(&CompareVoid);
    return voiddatatype;
}

void DestructVoidDataType(DataType* type){

    type->adtConstruct=(void*)(NULL);
    type->adtDestruct=(void*)(NULL);
    type->adtGetValue=(void*)(NULL);
    type->adtSetValue=(void*)(NULL);
    type->adtRandomValue=(void*)(NULL);
    type->adtReadFromKeyBoard=(void*)(NULL);
    type->adtWriteToMonitor=(void*)(NULL);
    type->adtClone=(void*)(NULL);
    type->adtCompare=(void*)(NULL);
    free(type);

}

void* CreateVoid(){
    void *var=NULL;
    return var;
}

void DestructVoid(void* var){

}

void* GetValueVoid(void* var){
    return var;
}

void* SetValueVoid(void* var,void* dato){
    var=dato;
    return var;
}

void RandomValueVoid(void* var){
    var=(void*)malloc(sizeof(void*)*rand()%250);
}

void ReadFromKeyBoardVoid(void* var){
    printf("Inserisci il valore: \n");
    scanf("%p",&var);
}

void WriteToMonitorVoid(void* var){
    printf("%p \n",var);
}

void* CloneVoid(void* var){
    void* clone=NULL;
    clone=var;
    return clone;
}

uint CompareVoid(void* var1, void* var2){
    if(var1==var2) return 0;
    else if(var1>var2) return 1;
    else return 2;
}

// ...
