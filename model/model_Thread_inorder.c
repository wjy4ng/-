#include <stdio.h>
#define TRUE 1
#define FALSE 0

// Define Tree Node
typedef struct TreeNode{
	char data;
	struct TreeNode *left, *right;
	int is_thread;
} TreeNode;

//		G
//	C		F
// A B	   D E

TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode *root = &n7;


// Define find_successor()
TreeNode* find_successor(TreeNode *p){
	TreeNode *q = p->right;

	if(q==NULL || p->is_thread==TRUE) return q;
	while(q->left) q=q->left;
	return q;
}

// Define thread_inorder()
void thread_inorder(TreeNode *p){
	TreeNode *q = p;
	while(q->left) q = q->left;
	do{
		printf("%c -> ", q->data);
		q = find_successor(q);
	} while(q);
}



// main
int main(){
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(root);
	printf("\n");
	return 0;
}

