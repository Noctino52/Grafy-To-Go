
#ifndef BSTITRPOSTORD_H
#define BSTITRPOSTORD_H

/* ************************************************************************** */

#include "../itr/itr.h"

#include "../stack/stack.h"

#include "bst.h"

/* ************************************************************************** */

typedef struct BSTPostOrderIterator
{
    BSTNode* curr;
    StackObject* stack;
    DataType* pointer;


} BSTPostOrderIterator;

/* ************************************************************************** */
ITRType* ConstructBSTPostOrderIterator();
void DestructBSTPostOrderIterator(ITRType* iter);

/* ************************************************************************** */
BSTPostOrderIterator* PostOrderConstruct();
void PostOrderDestruct(BSTPostOrderIterator* iter);
uint PostOrderTerminated(BSTPostOrderIterator* iter);
BSTNode* PostOrderElement(BSTPostOrderIterator* iter);
void PostOrderSuccessor(BSTPostOrderIterator* iter);
/* ************************************************************************** */

#endif
