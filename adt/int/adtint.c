
#include "adtint.h"

/* ************************************************************************** */
DataType* ConstructIntDataType(){

    DataType* intdatatype=(DataType*)malloc(sizeof(DataType));
    intdatatype->adtConstruct=(void*)(&CreateInteger);
    intdatatype->adtDestruct=(void*)(&DestructInteger);
    intdatatype->adtGetValue=(void*)(&GetValueInt);
    intdatatype->adtSetValue=(void*)(&SetValueInt);
    intdatatype->adtRandomValue=(void*)(&RandomValueInt);
    intdatatype->adtReadFromKeyBoard=(void*)(&ReadFromKeyBoardInt);
    intdatatype->adtWriteToMonitor=(void*)(&WriteToMonitorInt);
    intdatatype->adtClone=(void*)(&CloneInt);
    intdatatype->adtCompare=(void*)(&CompareInt);
    return intdatatype;
}

void DestructIntDataType(DataType* type){

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

long long int* CreateInteger(){
    long long int *var=(long long int*)malloc(sizeof(long long int));
    return var;
}

void DestructInteger(long long int* var){
    free(var);
}

long long int* GetValueInt(long long int* var){

    return var;
}

long long int* SetValueInt(long long int* var,long long int* dato){
    (*(var))=(*(dato));
    return var;
}

void RandomValueInt(long long int* var){
    (*(var))=rand()%250;
}

void ReadFromKeyBoardInt(long long int* var){
    printf("Inserisci il valore: \n");
    scanf("%lld",&(*(var)));
}

void WriteToMonitorInt(long long int* var){
    printf("%lld \n",(*(var)));
}

long long int* CloneInt(long long int* var){
    long long int* clone=(long long int*)malloc(sizeof(long long int));
    *(clone)=*(var);
    return clone;
}

uint CompareInt(long long int* var1, long long int* var2){
    if(((*(var1))==(*(var2)))) return 0;
    else if((*(var1))<(*(var2))) return 1;
    else return 2;
}

// ...
