
#ifndef BSTITR_H
#define BSTITR_H

/* ************************************************************************** */

#include "../bst.h"

/* ************************************************************************** */

BSTType* ConstructBSTIterative();
void DestructBSTIterative(BSTType*);

/* ************************************************************************** */

void ItrDestruct(BSTNode* tree);

BSTNode* ItrClone(BSTNode* tree);

uint ItrEqual(BSTNode* tree1,BSTNode* tree2);

uint ItrExists(BSTNode* tree,DataObject* elem);

BSTNode* ItrInsert(BSTNode* tree,DataObject* elem);
void ItrRemove(BSTNode** tree,DataObject* elem);

BSTNode* ItrGetMin(BSTNode* tree);
DataObject* ItrGetNRemoveMin(BSTNode** tree);
void ItrRemoveMin(BSTNode** tree);
BSTNode* ItrGetMax(BSTNode* tree);
DataObject* ItrGetNRemoveMax(BSTNode** tree);
void ItrRemoveMax(BSTNode** tree);

BSTNode* ItrGetPredecessor(BSTNode* tree,DataObject* elem);
DataObject* ItrGetNRemovePredecessor(BSTNode** tree,DataObject* elem);
DataObject* ItrRemovePredecessor(BSTNode** tree,DataObject* elem);
BSTNode* ItrGetSuccessor(BSTNode* tree,DataObject* elem);
DataObject* ItrGetNRemoveSuccessor(BSTNode** tree,DataObject* elem);
DataObject* ItrRemoveSuccessor(BSTNode** tree,DataObject*);

void ItrPreOrderMap(BSTNode* tree,MapFun mapper);
void ItrInOrderMap(BSTNode* tree,MapFun mapper);
void ItrPostOrderMap(BSTNode* tree,MapFun mapper);
void ItrBreadthMap(BSTNode* tree,MapFun mapper);
void ItrPreOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem);
void ItrInOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem);
void ItrPostOrderFold(BSTNode* tree,FoldFun folder,DataObject* elem);
void ItrBreadthFold(BSTNode* tree,FoldFun folder,DataObject* elem);

//FUNZIONI AGGIUNTIVE

BSTNode* ItrCancRadice(BSTNode* tree);
void ItrClear(BSTNode* wBSTObject);
BSTNode* ItrStaccaMinimo(BSTNode* figlio,BSTNode* padre);

#endif
