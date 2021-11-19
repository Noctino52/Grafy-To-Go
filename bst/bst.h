
#ifndef BST_H
#define BST_H

/* ************************************************************************** */

#include "../utility.h"

#include "../adt/adt.h"
#include "../queue/queue.h"
#include "../queue/vec/queuevec.h"
/* ************************************************************************** */

typedef struct BSTNode BSTNode;
struct BSTNode
{
  BSTNode* sx;
  BSTNode* dx;
  DataObject* info;
};

/* ************************************************************************** */

typedef void (*BSTDestruct)(BSTNode*);

typedef BSTNode* (*BSTClone)(BSTNode*);

typedef uint (*BSTEqual)(BSTNode*,BSTNode*);

typedef uint (*BSTExists) (BSTNode*,DataObject*);

typedef BSTNode* (*BSTInsert)(BSTNode*,DataObject*);
typedef void (*BSTRemove)(BSTNode**,DataObject*);

typedef BSTNode* (*BSTGetMin)(BSTNode*);
typedef DataObject* (*BSTGetNRemoveMin)(BSTNode**);
typedef void (*BSTRemoveMin)(BSTNode**);
typedef BSTNode* (*BSTGetMax)(BSTNode*);
typedef DataObject* (*BSTGetNRemoveMax)(BSTNode**);
typedef void (*BSTRemoveMax)(BSTNode**);

typedef BSTNode* (*BSTGetPredecessor)(BSTNode*,DataObject* );
typedef DataObject* (*BSTGetNRemovePredecessor)(BSTNode**,DataObject*);
typedef DataObject* (*BSTRemovePredecessor)(BSTNode**,DataObject*);
typedef BSTNode* (*BSTGetSuccessor)(BSTNode*,DataObject*);
typedef DataObject* (*BSTGetNRemoveSuccessor)(BSTNode**,DataObject*);
typedef DataObject* (*BSTRemoveSuccessor)(BSTNode**,DataObject*);

typedef void (*BSTPreOrderMap)(BSTNode*,MapFun);
typedef void (*BSTInOrderMap)(BSTNode*,MapFun);
typedef void (*BSTPostOrderMap)(BSTNode*,MapFun);
typedef void (*BSTBreadthMap)(BSTNode*,MapFun);
typedef void (*BSTPreOrderFold)(BSTNode*,FoldFun,DataObject* elem);
typedef void (*BSTInOrderFold)(BSTNode*,FoldFun,DataObject* elem);
typedef void (*BSTPostOrderFold)(BSTNode*,FoldFun,DataObject* elem);
typedef void (*BSTBreadthFold)(BSTNode*,FoldFun,DataObject* elem);

/* ************************************************************************** */

typedef struct BSTType
{
  BSTDestruct bstdestruct;
  BSTClone bstclone;
  BSTEqual bstequal;
  BSTExists bstexists;
  BSTInsert bstinsert;
  BSTRemove bstremove;
  BSTGetMin bstgetmin;
  BSTGetNRemoveMin bstgetnremovemin;
  BSTRemoveMin bstremovemin;
  BSTGetMax bstgetmax;
  BSTGetNRemoveMax bstgetnremovemax;
  BSTRemoveMax bstremovemax;
  BSTGetPredecessor bstgetpredecessor;
  BSTGetNRemovePredecessor bstgetnremovepredecessor;
  BSTRemovePredecessor bstremovepredecessor;
  BSTGetSuccessor bstgetsuccessor;
  BSTGetNRemoveSuccessor bstgetnremovesuccessor;
  BSTRemoveSuccessor bstremovesuccessor;
  BSTPreOrderMap bstpreordermap;
  BSTInOrderMap bstinordermap;
  BSTPostOrderMap bstpostordermap;
  BSTBreadthMap bstbreadthmap;
  BSTPreOrderFold bstpreorderfold;
  BSTInOrderFold bstinorderfold;
  BSTPostOrderFold bstpostorderfold;
  BSTBreadthFold bstbreadthfold;

} BSTType;

typedef struct BSTObject
{
  BSTNode* root;
  BSTType* type;
  int dim;

} BSTObject;

/* ************************************************************************** */

BSTObject* bstConstruct(BSTType* tipo);
void bstDestruct(BSTObject* tree);

uint bstEmpty(BSTObject* tree);

int bstSize(BSTObject* tree);

void bstClear(BSTObject* tree);

BSTObject* bstClone(BSTObject* tree);

uint bstEqual(BSTObject* tree1,BSTObject* tree2);

uint bstExists(BSTObject* tree,DataObject* elem);

void bstInsert(BSTObject* tree,DataObject* elem);
void bstRemove(BSTObject* tree,DataObject* elem);

DataObject* bstGetMin(BSTObject* tree);
DataObject* bstGetNRemoveMin(BSTObject* tree);
void bstRemoveMin(BSTObject* tree);
DataObject* bstGetMax(BSTObject* tree);
DataObject* bstGetNRemoveMax(BSTObject* tree);
void bstRemoveMax(BSTObject* tree);

DataObject* bstGetPredecessor(BSTObject* tree,DataObject* elem);
DataObject* bstGetNRemovePredecessor(BSTObject* tree,DataObject* elem);
void bstRemovePredecessor(BSTObject* tree,DataObject* elem);
DataObject* bstGetSuccessor(BSTObject* tree,DataObject* elem);
DataObject* bstGetNRemoveSuccessor(BSTObject* tree,DataObject* elem);
void bstRemoveSuccessor(BSTObject* tree,DataObject* elem);

void bstPreOrderMap(BSTObject* tree,MapFun mapper);
void bstInOrderMap(BSTObject*,MapFun mapper);
void bstPostOrderMap(BSTObject* tree,MapFun mapper);
void bstBreadthMap(BSTObject* tree,MapFun mapper);
void bstPreOrderFold(BSTObject* tree,FoldFun folder,DataObject* elem);
void bstInOrderFold(BSTObject* tree,FoldFun folder,DataObject* elem);
void bstPostOrderFold(BSTObject* tree,FoldFun folder,DataObject* elem);
void bstBreadthFold(BSTObject* tree,FoldFun folder,DataObject* elem);

//FUNZIONI AGGIUNTIVE
BSTNode* newNode(DataObject* key);
void printfTreeUtil(BSTNode* root, int space,int count);

/* ************************************************************************** */

#endif
