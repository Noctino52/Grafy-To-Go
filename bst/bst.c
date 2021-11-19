

#include "bst.h"

/* ************************************************************************** */
BSTObject* bstConstruct(BSTType* tipo){

BSTObject* newTree=(BSTObject*)malloc(sizeof(BSTObject));
newTree->type=tipo;
newTree->root=NULL;
newTree->dim=0;

return newTree;
}

void bstDestruct(BSTObject* tree){
if(tree->root!=NULL)tree->type->bstdestruct(tree->root);
free(tree);
}

uint bstEmpty(BSTObject* tree){
if(!tree->root)return 0;
else return 1;
}

int bstSize(BSTObject* tree){
return tree->dim;
}

void bstClear(BSTObject* tree){
assert(!(tree->root));
tree->type->bstdestruct(tree->root);
}

BSTObject* bstClone(BSTObject* tree){
if(tree->root==NULL){
   BSTObject* newTree=(BSTObject*)malloc(sizeof(BSTObject));
   newTree->type=tree->type;
   newTree->root=NULL;
   newTree->dim=0;
   return newTree;
   }
else{ 
BSTObject* clone=bstConstruct(tree->type);
clone->root=clone->type->bstclone(tree->root);
clone->dim=tree->dim;
return clone;
}
}

uint bstEqual(BSTObject* tree1,BSTObject* tree2){
if(tree1->dim!=tree2->dim || tree1->root==tree2->root || tree1->type!=tree2->type) return 0;
else return tree1->type->bstequal(tree1->root,tree2->root);
}

uint bstExists(BSTObject* tree,DataObject* elem){
if(tree->type->bstexists(tree->root,elem)) return 1;
else return 0;
}

void bstInsert(BSTObject* tree,DataObject* elem){
if(tree->type->bstexists(tree->root,elem)==0) return;
tree->root=tree->type->bstinsert(tree->root,elem);
tree->dim++;
}

void bstRemove(BSTObject* tree,DataObject* elem){
assert((tree->root));
tree->type->bstremove(&tree->root,elem);
}

DataObject* bstGetMin(BSTObject* tree){
assert((tree->root));
BSTNode* temp=tree->type->bstgetmin(tree->root);
return temp->info;
}

DataObject* bstGetNRemoveMin(BSTObject* tree){
assert((tree->root));
DataObject* temp=NULL;
temp=tree->type->bstgetnremovemin(&(tree->root));
tree->dim--;
return temp;
}

void bstRemoveMin(BSTObject* tree){
assert((tree->root));
tree->type->bstremovemin(&(tree->root));
tree->dim--;
}

DataObject* bstGetMax(BSTObject* tree){
    assert((tree->root));
    BSTNode* temp=tree->type->bstgetmax(tree->root);
    return temp->info;

}

DataObject* bstGetNRemoveMax(BSTObject* tree){
    assert((tree->root));
    DataObject* temp=NULL;
    BSTNode* ret=NULL;
    temp=tree->type->bstgetnremovemax(&(tree->root));
    tree->dim--;
    return temp;

}

void bstRemoveMax(BSTObject* tree){
    assert((tree->root));
    tree->type->bstremovemax(&(tree->root));
    tree->dim--;
}

DataObject* bstGetPredecessor(BSTObject* tree,DataObject* elem){
assert((tree->root));
BSTNode* temp_nodo=tree->type->bstgetpredecessor(tree->root,elem);
if(temp_nodo==NULL)return adtConstruct(tree->root->info->op);
DataObject* temp=adtClone(temp_nodo->info);
return temp;
}

DataObject* bstGetNRemovePredecessor(BSTObject* tree,DataObject* elem){
    assert(tree->root);
    DataObject* temp=tree->type->bstgetnremovepredecessor(&tree->root,elem);
    if(temp==NULL)return adtConstruct(tree->root->info->op);
    tree->dim--;
    return temp;
}



void bstRemovePredecessor(BSTObject* tree,DataObject* elem){
assert(tree->root);
    DataObject* temp=tree->type->bstgetnremovepredecessor(&tree->root,elem);
    if(temp==NULL) return;
    tree->dim--;
}

DataObject* bstGetSuccessor(BSTObject* tree,DataObject* elem){
    assert((tree->root));
    BSTNode* temp_nodo=tree->type->bstgetsuccessor(tree->root,elem);
    if(temp_nodo==NULL)return adtConstruct(tree->root->info->op);
    DataObject* temp=adtClone(temp_nodo->info);
    return temp;
}

DataObject* bstGetNRemoveSuccessor(BSTObject* tree,DataObject* elem){
    DataObject* temp=tree->type->bstgetnremovesuccessor(&tree->root,elem);
    if(temp==NULL)return adtConstruct(tree->root->info->op);
    tree->dim--;
    return temp;
}

void bstRemoveSuccessor(BSTObject* tree,DataObject* elem){
    assert(tree->root);
    DataObject* temp=tree->type->bstremovesuccessor(&tree->root,elem);
    if(temp==NULL) return;
    tree->dim--;
}

void bstPreOrderMap(BSTObject* tree,MapFun mapper){
assert((tree->root));
tree->type->bstpreordermap(tree->root,mapper);
}
void bstPostOrderMap(BSTObject* tree,MapFun mapper){
assert((tree->root));
tree->type->bstpostordermap(tree->root,mapper);
}

void bstInOrderMap(BSTObject* tree,MapFun mapper){
assert((tree->root));
tree->type->bstinordermap(tree->root,mapper);
}

void bstBreadthMap(BSTObject* tree,MapFun mapper){
assert((tree->root));
tree->type->bstbreadthmap(tree->root,mapper);
}

void bstPreOrderFold(BSTObject* tree,FoldFun folder,DataObject* elem){
assert((tree->root));
tree->type->bstpreorderfold(tree->root,folder,elem);
}

void bstPostOrderFold(BSTObject* tree,FoldFun folder,DataObject* elem){
assert((tree->root));
tree->type->bstpostorderfold(tree->root,folder,elem);
}

void bstInOrderFold(BSTObject* tree,FoldFun folder,DataObject* elem){
assert((tree->root));
tree->type->bstinorderfold(tree->root,folder,elem);
}

void bstBreadthFold(BSTObject* tree,FoldFun folder,DataObject* elem){

    assert((tree->root));
    tree->type->bstbreadthfold(tree->root,folder,elem);

}

BSTNode* newNode(DataObject* key)
{
	BSTNode* node =(BSTNode*)malloc(sizeof(BSTNode));
	node->info =adtClone(key);
	node->sx =NULL;
	node->dx =NULL;
	return node;
}

void printfTreeUtil(BSTNode* root, int space,int count) 
{ 
    if (root == NULL) return; 
  
    space += count; 
  

    printfTreeUtil(root->dx, space,count); 
  

    printf("\n"); 
    for (int i = count; i < space; i++) 
        printf(" "); 
    adtWriteToMonitor(root->info); 
    printfTreeUtil(root->sx, space,count); 
}


// ...
