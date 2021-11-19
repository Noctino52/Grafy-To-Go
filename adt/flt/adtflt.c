
#include "adtflt.h"

/* ************************************************************************** */

/* ************************************************************************** */
DataType* ConstructFloatDataType(){

DataType* floatdatatype=(DataType*)malloc(sizeof(DataType));
floatdatatype->adtConstruct=(void*)(&CreateFloat);
floatdatatype->adtDestruct=(void*)(&DestructFloat);
floatdatatype->adtGetValue=(void*)(&GetValueFlt);
floatdatatype->adtSetValue=(void*)(&SetValueFlt);
floatdatatype->adtRandomValue=(void*)(&RandomValueFlt);
floatdatatype->adtReadFromKeyBoard=(void*)(&ReadFromKeyBoardFlt);
floatdatatype->adtWriteToMonitor=(void*)(&WriteToMonitorFlt);
floatdatatype->adtClone=(void*)(&CloneFlt);
floatdatatype->adtCompare=(void*)(&CompareFlt);
return floatdatatype;
}

void DestructFloatDataType(DataType* type){

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

float* CreateFloat(){
float* var=(float*)malloc(sizeof(int));
return var;
}

void DestructFloat(float* var){
free(var);
}

float* GetValueFlt(float* var){
return var;
}

void SetValueFlt(float* var,float* dato){
(*(var))=(*(dato));
}

void RandomValueFlt(float* var){
    float scale = rand() / (float) RAND_MAX;
    (*(var))=-MaxFltAbsRndVal + scale * (MaxFltAbsRndVal+MaxFltAbsRndVal); 
}

void ReadFromKeyBoardFlt(float* var){
printf("Inserisci il valore: \n");
scanf("%f",&(*(var)));
}

void WriteToMonitorFlt(float* var){
printf("%f \n",(*(var)));
}

float* CloneFlt(float* var){
float* clone=(float*)malloc(sizeof(float*));
*(clone)=*(var);
return clone;
}

uint CompareFlt(float* var1, float* var2){
if((*(var1))==(*(var2))) return 0;
else if((*(var1))<(*(var2))) return 1;
else return 2;
}

// ...
