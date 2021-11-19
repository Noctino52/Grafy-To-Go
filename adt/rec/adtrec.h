
#ifndef ADTREC_H
#define ADTREC_H

/* ************************************************************************** */

#include "../adt.h"

typedef struct Persona{
char* nome;
char* cognome;
int eta;
} Persona;

/* ************************************************************************** */

DataType* ConstructPersonaDataType();
void DestructPersonaDataType(DataType* type);

/* ************************************************************************** */
Persona* CreatePersona();
void DestructPersona(Persona* var);
Persona* GetValuePersona(Persona* var);
void SetValuePersona(Persona* var,Persona* valori);
void RandomValuePersona(Persona* var);
void ReadFromKeyBoardPersona(Persona* var);
void WriteToMonitorPersona(Persona* var);
Persona* ClonePersona(Persona* var);
uint ComparePersona(Persona* var1, Persona* var2);


#endif
