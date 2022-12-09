#include <stdio.h>
#include <stdlib.h>

// Define Tree Node
typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode *left, *right;
} TreeNode;


// Define search()
TreeNode* search(TreeNode *p, element data){
	if(p==NULL) return NULL;
	if(data == p->data) return p;
	else if(data < p->data) return search(p->left, data);
	else return search(p->right, data);
}

// Define new_node()
TreeNode* new_node(element data){
	TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}

// Define insert_node()
TreeNode* insert_node(TreeNode *p,  element data){
	if(p==NULL) return new_node(data);

	if(data < p->data) p->left = insert_node(p->left, data);
	else if(data > p->data) p->right = insert_node(p->right, data);
	return p;
}

// Define min_value_node()
TreeNode* min_value_node(TreeNode *p){
	TreeNode *tmp = p;
	while(tmp->left) tmp = tmp->left;
	return tmp;
}

// Define delete_node()
TreeNode* delete_node(TreeNode *p, element data){
	if(p==NULL) return p;

	if(data < p->data) p->left = delete_node(p->left, data);
	else if(data > p->data) p->right = delete_node(p->right, data);
	else{
		if(p->left == NULL){
			TreeNode *tmp = p->right;
			free(p);
			return tmp;
		}
		else if(p->right == NULL){
			TreeNode *tmp = p->left;
			free(p);
			return tmp;
		}
		
		TreeNode *tmp = min_value_node(p->right);

		p->data = tmp->data;
		p->right = delete_node(p->right, tmp->data);
	}
	return p;
}

// Define inorder()
void inorder(TreeNode *p){
	if(p){
		inorder(p->left);
		printf("%d -> ", p->data);
		inorder(p->right);
	}
}



// main
int main(){
	TreeNode *root = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	root = insert_node(root, 55);
	inorder(root);
	root = delete_node(root, 55);

	printf("\n이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if(search(root, 30) != NULL) printf("이진 탐색 트리에서 30을 발견함\n");
	else printf("이진 탐색 트리에서 30을 발견못함\n");

	return 0;
}

