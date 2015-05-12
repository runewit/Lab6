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
	ttree*q=calloc(1, sizeof(ttree));
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
		tree->bottom = slot;
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

int pop(ttree *tree){
	int pid;
	
	if(tree->bottom == NULL && tree->top == NULL){
		printf("tree is empty\n");
		return -1;
	}else if(tree->bottom == tree->top){
		pid=tree->bottom->number;
		free(tree->bottom);
		tree->bottom = NULL;
		tree->top = NULL;
		printf("popped top item out\n");
	}else{
		pid=tree->bottom->number;
		printf("set pid\n");
		tree->bottom = tree->bottom->after;
		printf("set new bottom\n");
		free(tree->bottom->before);
		printf("freed old bottom\n");
		tree->bottom->before = NULL;
		printf("set new bottom's before reference to null\n");
	}
	return pid;
}


void delete(ttree* q){
	while(pop(q) != -1);
	free(q);
}