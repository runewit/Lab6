#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

ttree* create(){
	ttree *q = calloc(1, sizeof(ttree));
	q->counter=NULL;
	q->count=0;
	//q->bottom=NULL;
	q->top=NULL;
	return q;
}

void push(ttree *tree, int value){
	tb *slot=calloc(1, sizeof(tb));
	
	slot->number = value;
	
	if(tree->counter==NULL && tree->top == NULL){// && tree->bottom == NULL){
		//tree->bottom = slot;
		tree->top = slot;
		tree->counter = slot;
	}else if(tree->counter != NULL && tree->counter->after1 == NULL){
		slot->before = tree->counter;
		tree->counter->before->after1 = slot;
		//tree->bottom = slot;
	}else if(tree->counter != NULL && tree->counter->after1 != NULL){
		slot->before = tree->counter;
		tree->counter->before->after2 = slot;
		//tree->bottom = slot;
	}else{
		if(tree->counter->before != NULL){
			tree->counter = tree->counter->before;
			if(tree->counter->after2->after1 == NULL){
				tree->counter = tree->counter->after2;
				slot->before = tree->counter;
				tree->counter->after1 = slot; //repeat back to else unless tree->counter->before == NULL
			}
		}
	}
	tree->count++;
}

void preorder(ttree *tree){
	if(tree->counter->after1->after1 != NULL){
		tree->counter = tree->counter->after1;
		puts(tree->counter->number);
	}
	puts(tree->counter->after1->number);
	puts(tree->counter->after2->number);
	if(tree->counter != tree->top){
		tree->counter = tree->counter->before->after2;
		puts(tree->counter->number);
			if(tree->counter->after1->after1 != NULL){
			tree->counter = tree->counter->after1;
			puts(tree->counter->number);
		}
		puts(tree->counter->after1->number);
		puts(tree->counter->after2->number);
		tree->counter = tree->counter->before;
	}
}

void postorder(ttree *tree){}

void inorder(ttree *tree){}

void delete(ttree* tree){	
	if(tree->counter->after1->after1 != NULL){
		tree->counter = tree->counter->after1;
	}
	free(tree->counter->after1);
	free(tree->counter->after2);
	if(tree->counter != tree->top){
		tree->counter = tree->counter->before->after2;
		if(tree->counter->after1->after1 != NULL){
			tree->counter = tree->counter->after1;
		}
		free(tree->counter->after1);
		free(tree->counter->after2);
		tree->counter = tree->counter->before;
	}

}