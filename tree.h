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

void push(ttree *tree, int value);
void preorder(ttree *tree);
void postorder(ttree *tree);
void inorder(ttree *tree);
void delete(ttree* q);