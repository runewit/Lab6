#include <string.h>
#include "tree.c"

int main(void){
	int number;
	ttree tree;
	
	tree=create();
	
	if(1==1){
		printf("enter another number:");
		scanf("%i", number);
		if(number != -1){
			push(tree,number);
			preorder(tree);
		}else{
			delete(tree);
			return(0);
		}	
	}
}