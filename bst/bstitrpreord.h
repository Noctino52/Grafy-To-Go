
#ifndef BSTITRPREORD_H
#define BSTITRPREORD_H

/* ************************************************************************** */

#include "../itr/itr.h"

#include "../stack/stack.h"

#include "bst.h"

/* ************************************************************************** */
typedef struct BSTPreOrderIterator
{
  BSTNode* curr;
  StackObject* stack;
  DataType* pointer;

} BSTPreOrderIterator;

/* ************************************************************************** */
ITRType* ConstructBSTPreOrderIterator();
void DestructBSTPreOrderIterator(ITRType* iter);

/* ************************************************************************** */
BSTPreOrderIterator* PreOrderConstruct();
void PreOrderDestruct(BSTPreOrderIterator* iter);
uint PreOrderTerminated(BSTPreOrderIterator* iter);
BSTNode* PreOrderElement(BSTPreOrderIterator* iter);
void PreOrderSuccessor(BSTPreOrderIterator* iter);
#endif
