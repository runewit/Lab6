#include <stdio.h>
#include <stdlib.h>

typedef struct branch{
	struct branch *before;
	int number;
	struct branch *after1;
	struct branch *after2;
}tb;

typedef struct tree{
	tb *counter
	int count;
	tb *bottom;
	tb *top;
}ttree;

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
	
	if(tree->couner==NULL && tree->top == NULL){// && tree->bottom == NULL){
		//tree->bottom = slot;
		tree->top = slot;
		tree->counter = slot;
	}else if(tree->counter != NULL && tree->counter->after1 == NULL){
		slot->before = tree->counter;
		tree->counter->before->after1 = slot;
		//tree->bottom = slot;
	}else if(tree->counter != NULL && tree->counter->after1 != NULL){
		slot->before = tree->counter;
		tree->countert->before->after2 = slot;
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
	until(tree->counter->after1->after1 == NULL){
		puts(tree->counter->number);
	}
	puts(tree->counter->after1->number);
	puts(tree->counter->after2->number);
	until(tree->counter == tree->top){
		tree->counter = tree->counter->before->after2;
		puts(tree->counter->number);
		until(tree->counter->after1->after1 == NULL){
			tree->counter = tree->counter->after1;
			puts(tree->counter->number)
		}
		puts(tree->counter->after1->number);
		puts(tree->counter->after2->number);
		tree->counter = tree->counter->before;
	}
}

void postorder(ttree *tree){}

void inorder(ttree *tree){}

void delete(ttree* q){
	
	free(q);
}