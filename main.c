#include <string.h>
#include "tree.c"

int main(){
	int number;
	ttree w;
	
	w=*create();
	
	if(1==1){
		printf("enter another number:");
		scanf("%i", number);
		if(number != -1){
			push(&w,number);
			preorder(&w);
		}else{
			delete(&w);
			return(0);
		}	
	}
}