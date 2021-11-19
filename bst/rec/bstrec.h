
#ifndef BSTREC_H
#define BSTREC_H

/* ************************************************************************** */

#include "../bst.h"
#include "../queue/queue.h"
/* ************************************************************************** */

BSTType* ConstructBSTRecursive();
void DestructBSTRecursive(BSTType* tipo);

/* ************************************************************************** */

void RicDestruct(BSTNode* tree);

BSTNode* RicClone(BSTNode* tree);

uint RicEqual(BSTNode* tree1,BSTNode* tree2);

uint RicExists(BSTNode* tree,DataObject* elem);

BSTNode* RicInsert(BSTNode* tree,DataObject* elem);
void RicRemove(BSTNode** tree,DataObject* elem);

BSTNode* RicGetMin(BSTNode* tree);
DataObject* RicGetNRemoveMin(BSTNode** tree);
void RicRemoveMin(BSTNode** tree);
BSTNode* RicGetMax(BSTNode* tree);
DataObject* RicGetNRemoveMax(BSTNode** tree);
void RicRemoveMax(BSTNode** tree);

BSTNode* RicGetPredecessor(BSTNode* tree,DataObject* elem);
DataObject* RicGetNRemovePredecessor(BSTNode** tree,DataObject* elem);
DataObject* RicRemovePredecessor(BSTNode** tree,DataObject* elem);
BSTNode* RicGetSuccessor(BSTNode* tree,DataObject* elem);
DataObject* RicGetNRemoveSuccessor(BSTNode** tree,DataObject* elem);
DataObject* RicRemoveSuccessor(BSTNode** tree,DataObject*);

void RicPreOrderMap(BSTNode* tree,MapFun mapper);
void RicInOrderMap(BSTNode* tree,MapFun mapper);
void RicPostOrderMap(BSTNode* tree,MapFun mapper);
void RicBreadthMap(BSTNode* tree,MapFun mapper);
void RicPreOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem);
void RicInOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem);
void RicPostOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem);
void RicBreadthFold(BSTNode* tree,FoldFun folder,DataObject* elem);

//funzioni facoltative
BSTNode* RicCancRadice(BSTNode* tree);
BSTNode* RicStaccaMinimo(BSTNode* figlio,BSTNode* padre);
#endif
