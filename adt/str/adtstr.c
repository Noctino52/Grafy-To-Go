
#include "adtstr.h"

/* ************************************************************************** */
DataType* ConstructStringDataType(){

DataType* stringdatatype=(DataType*)malloc(sizeof(DataType));
stringdatatype->adtConstruct=(void*)(&CreateString);
stringdatatype->adtDestruct=(void*)(&DestructString);
stringdatatype->adtGetValue=(void*)(&GetValueStr);
stringdatatype->adtSetValue=(void*)(&SetValueStr);
stringdatatype->adtRandomValue=(void*)(&RandomValueStr);
stringdatatype->adtReadFromKeyBoard=(void*)(&ReadFromKeyBoardStr);
stringdatatype->adtWriteToMonitor=(void*)(&WriteToMonitorStr);
stringdatatype->adtClone=(void*)(&CloneStr);
stringdatatype->adtCompare=(void*)(&CompareStr);
return stringdatatype;
}

void DestructStringDataType(DataType* type){

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

char** CreateString(){
char** var=(char**)malloc(sizeof(char*));
(*(var))=(char*)malloc((sizeof(char*)));
return var;
}

void DestructString(char** var){
free(*(var));
free(var);
}

char** GetValueStr(char** var){
return var;
}

void SetValueStr(char** var,char** dato){
(*(var))=(char*)realloc((*(var)),(sizeof(char)*(strlen((*(dato)))+1)));
strcpy((*(var)),(*(dato)));
}


void RandomValueStr(char** var){
int length=MaxStrLen;

char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";    
char *randomString;
int n;
if (length) {
    randomString = malloc( sizeof(char)*(length +1));
    if (randomString) {        
        for (n = 0;n < length;n++) {        
            int key = rand() % (int) (sizeof(charset) -1);
            randomString[n] = charset[key];
        }
        randomString[length] = '\0';
    }
}
(*(var))=(char*)realloc((*(var)),sizeof(char)*(strlen((randomString))+1));
strcpy( (*(var)),randomString);
free(randomString);
}

void ReadFromKeyBoardStr(char** var){
printf("Inserisci il valore: \n");
scanf("%s",*(var));
}

void WriteToMonitorStr(char** var){
printf("Valore: %s \n",(*(var)));
}

char** CloneStr(char** var){
char** clone=(char**)malloc(sizeof(char*));
(*(clone))=(char*)malloc((sizeof(char)*(strlen(((*(var))))+1)));
strcpy((*(clone)),(*(var)));
return clone;
}

uint CompareStr(char** var1, char** var2){
if((strcmp((*(var1)),(*(var2)))<0)) return 1;
else if((strcmp((*(var1)),(*(var2)))>0)) return 2;
else return 0;
}


// ...
