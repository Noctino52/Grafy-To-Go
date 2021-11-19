
#ifndef ITR_H
#define ITR_H

/* ************************************************************************** */


#include "../utility.h"
#include "../bst.h"
/* ************************************************************************** */

typedef void* (*ITRConstruct)(void*);
typedef void  (*ITRDestruct)(void*);
typedef uint  (*ITRTerminated)(void*);
typedef BSTNode* (*ITRElement)(void*);
typedef void(*ITRSuccessor)(void*);

/* ************************************************************************** */
typedef struct ITRType
{

  ITRConstruct itrconstruct;
  ITRDestruct itrdestruct;
  ITRTerminated itrterminated;
  ITRElement itrelement;
  ITRSuccessor itrsuccessor;

} ITRType;

typedef struct ITRObject
{
  ITRType* type;
  void* dato;

} ITRObject;

/* ************************************************************************** */

ITRObject* itrConstruct(ITRType* tipo,void* nodo);
void itrDestruct(ITRObject* iter);
uint itrTerminated(ITRObject* iter);
void* itrElement(ITRObject* iter);
void* itrSuccessor(ITRObject* iter);

/* ************************************************************************** */

#endif
