
#ifndef BSTITRINORD_H
#define BSTITRINORD_H

/* ************************************************************************** */

#include "../itr/itr.h"

#include "../stack/stack.h"

#include "bst.h"

/* ************************************************************************** */

typedef struct BSTInOrderIterator
{
    BSTNode* curr;
    BSTNode* nextDX;
    StackObject* stack;
    DataType* pointer;

} BSTInOrderIterator;

/* ************************************************************************** */
ITRType* ConstructBSTInOrderIterator();
void DestructBSTInOrderIterator(ITRType* iter);

/* ************************************************************************** */
BSTInOrderIterator* InOrderConstruct();
void InOrderDestruct(BSTInOrderIterator* iter);
uint InOrderTerminated(BSTInOrderIterator* iter);
BSTNode* InOrderElement(BSTInOrderIterator* iter);
void InOrderSuccessor(BSTInOrderIterator* iter);
/* ************************************************************************** */

#endif
