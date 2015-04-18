//============================================================================
// Name        : BiTree.cpp
// Author      : codekiller
// Version     :
// Copyright   : zz-twi
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

typedef int data;

typedef struct _BitNode {
	data key;
	struct _BitNode * lchild;
	struct _BitNode * rchild;
}* BiTree, BitNode;

void print(data da){
	cout<<da<<" ";
}

bool searchBiNode(BiTree T,data key,BiTree parent,BiTree &result){
	/*
	 * param result:last no-null Node,null means Empty Tree
	 * param parent:init value NULL,null means Empty Tree
	 *
	 */
if(!T){
	result=parent;
	return false;
}
if(T->key==key){
	result=T;
	return true;

}
else if(key>T->key){
	return searchBiNode(T->rchild,key,T,result);
}
else
	return searchBiNode(T->lchild,key,T,result);

}

bool insertNode(BiTree &T,data key){
	BiTree result=NULL,tempnode=(BiTree)malloc(sizeof(BitNode));
	tempnode->key=key;
	tempnode->lchild=NULL;
	tempnode->rchild=NULL;
	if(!searchBiNode(T,key,NULL,result)){
		if(!result)
			T=tempnode;
		else{
			if(key>result->key){
				result->rchild=tempnode;
			}
			else
				result->lchild=tempnode;
		}
		return true;
	}
	else
		free(tempnode);
	return false;

}

BiTree createBSTree() {
	BiTree root = NULL;
//	(BiTree) malloc(sizeof(BitNode));
//	root->lchild=NULL;
//	root->rchild=NULL;
//	root->key=0;
//  you should not init a new node!
	data temp = 0;

	while (cin >> temp) {
			if ((char) temp == '.') {
					break;
				}
			if(!insertNode(root,temp))
			{
				cout << "Node key already exsited!!  Retry!" << endl;
				continue;
			}
	}
	return root;
}

void traverBiTree(BiTree T,void (*display)(data)){
	if(T==NULL){
		return ;
	}

	traverBiTree(T->lchild,display);
	display(T->key);
	traverBiTree(T->rchild,display);
return ;
}

int main() {

	BiTree tree= createBSTree();
	traverBiTree(tree,print);
	cout<<endl;
	cout<<insertNode(tree,12)<<endl;;
	traverBiTree(tree,print);
	return 0;
}
