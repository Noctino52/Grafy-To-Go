
#include "adtrec.h"

#define MAXNOME 30
#define MAXCOGNOME 50
#define MAXETA 120
/* ************************************************************************** */
DataType* ConstructPersonaDataType(){

DataType* personadatatype=(DataType*)malloc(sizeof(DataType));
personadatatype->adtConstruct=(void*)(&CreatePersona);
personadatatype->adtDestruct=(void*)(&DestructPersona);
personadatatype->adtGetValue=(void*)(&GetValuePersona);
personadatatype->adtSetValue=(void*)(&SetValuePersona);
personadatatype->adtRandomValue=(void*)(&RandomValuePersona);
personadatatype->adtReadFromKeyBoard=(void*)(&ReadFromKeyBoardPersona);
personadatatype->adtWriteToMonitor=(void*)(&WriteToMonitorPersona);
personadatatype->adtClone=(void*)(&ClonePersona);
personadatatype->adtCompare=(void*)(&ComparePersona);
return personadatatype;

}

void DestructPersonaDataType(DataType* type){

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

Persona* CreatePersona(){
Persona* persona=(Persona*)malloc(sizeof(Persona));
persona->nome=(char*)malloc(sizeof(char*));
persona->cognome=(char*)malloc(sizeof(char*));
persona->eta=0;
return persona;
}

void DestructPersona(Persona* var){
free(var->nome);
free(var->cognome);
var->eta=0;
free(var);
}

Persona* GetValuePersona(Persona* var){
return var;
}

void SetValuePersona(Persona* var,Persona* valori){

var->nome=(char*)realloc(var->nome,sizeof(char)*(strlen(valori->nome)+1));
strcpy(var->nome,valori->nome);

var->cognome=(char*)realloc(var->cognome,sizeof(char)*(strlen(valori->cognome)+1));
strcpy(var->cognome,valori->cognome);

var->eta=valori->eta;
}

void RandomValuePersona(Persona* var){
    char* words_nome[10];
    char* words_cognome[10];
    words_nome[0] = "Giuseppe";
    words_nome[1] = "Pasquale";
    words_nome[2] = "Antonio";
    words_nome[3] = "Ivan";
    words_nome[4] = "Giovanni";
    words_nome[5] = "Luigi";
    words_nome[6] = "Gianluca";
    words_nome[7] = "Giacinto";
    words_nome[8] = "Michele";
    words_nome[9] = "Luca";

    words_cognome[0] = "Esposito";
    words_cognome[1] = "Russo";
    words_cognome[2] = "Bianchi";
    words_cognome[3] = "Romano";
    words_cognome[4] = "Colombo";
    words_cognome[5] = "Rinaldi";
    words_cognome[6] = "Galli";
    words_cognome[7] = "Ferrara";
    words_cognome[8] = "Conte";
    words_cognome[9] = "Testa";

    int random;
    random = rand() % 9;
    var->nome=(char*)realloc(var->nome,(sizeof(char)*(strlen((words_nome[random]))+1)));
    strcpy(var->nome,words_nome[random]);

    random = rand() % 9;
    var->cognome=(char*)realloc(var->cognome,(sizeof(char)*(strlen((words_cognome[random]))+1)));
    strcpy(var->cognome,words_cognome[random]);

    var->eta=rand()%120;
}



void ReadFromKeyBoardPersona(Persona* var){
printf("Inserisci il nome: \n");
scanf("%s",var->nome);
printf("Inserisci il cognome: \n");
scanf("%s",var->cognome);
printf("Inserisci l'eta': \n");
scanf("%d",&(var->eta));
}

void WriteToMonitorPersona(Persona* var){
printf("----------------------------------\n");
printf("Nome: %s \n",var->nome);
printf("Cognome: %s \n",var->cognome);
printf("Eta': %d \n",var->eta);
printf("----------------------------------\n");
}

Persona* ClonePersona(Persona* var){
Persona* clone=CreatePersona();
clone->nome=(char*)realloc(clone->nome,(sizeof(char)*(strlen((var->nome))+1)));
clone->cognome=(char*)realloc(clone->cognome,(sizeof(char)*(strlen((var->cognome))+1)));
strcpy((clone->nome),(var->nome));
strcpy((clone->cognome),(var->cognome));
clone->eta=var->eta;
return clone;
}

uint ComparePersona(Persona* var1, Persona* var2){
if((strcmp(var1->nome,var2->nome)==0) && (strcmp(var1->cognome,var2->cognome)==0)){
    if((var1->eta==var2->eta)) return 0;
    else if((var1->eta<var2->eta))return 1;
    else return 2;
}

}

// ...
