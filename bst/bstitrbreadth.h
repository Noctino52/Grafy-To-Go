
#ifndef BSTITRBREADTH_H
#define BSTITRBREADTH_H

/* ************************************************************************** */

#include "../itr/itr.h"

#include "../queue/queue.h"

#include "bst.h"

/* ************************************************************************** */

typedef struct BSTBreadthIterator
{
    QueueObject *queue;
    BSTNode *curr;
    int height;
    DataType* pointer;
} BSTBreadthOrderIterator;

/* ************************************************************************** */

ITRType* ConstructBSTBreadthOrderIterator();
void DestructBSTBreadthOrderIterator(ITRType* iter);

/* ************************************************************************** */
BSTBreadthOrderIterator* BreadthOrderConstruct();
void BreadthOrderDestruct(BSTBreadthOrderIterator* iter);
uint BreadthOrderTerminated(BSTBreadthOrderIterator* iter);
BSTNode* BreadthOrderElement(BSTBreadthOrderIterator* iter);
void BreadthOrderSuccessor(BSTBreadthOrderIterator* iter);
#endif
