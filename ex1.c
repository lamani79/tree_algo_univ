#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *right;
	struct node *left;
} node;

node *new_node(int data){
	node *new_node = malloc(sizeof(node));
	if(new_node){
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->data = data;
		
	}
	else{
		printf("error when creating new node");
	}
	return new_node;
}

void display_tree(node *root){
		if(root == NULL){
			return;
		}
		printf("%d\n",root->data);
		display_tree(root->left);
		display_tree(root->right);

	}

bool node_exist(node *root,int value){
	if(root == NULL) return false;
	if(root->data == value) return true;
	return node_exist(root->left,value) || node_exist(root->right,value);
}

int node_height(node *root){
	if(root == NULL) return -1;
	int left = node_height(root->left);
	int right = node_height(root->right);
	return (left > right) ? (left + 1) : (right + 1);
}
int tree_num_nodes(node *root){
	// this function return the number of the nodes in a given tree
	if(root == NULL) return 0;
	int left = tree_num_nodes(root->left);
	int right =  tree_num_nodes(root->right);
	if(right > left) printf("right is bigger so tree is not complete\n");
	return (left + right)+ 1;
}
bool full_binary_tree(node *root){
	if (root == NULL) return true;
	if(root->left == NULL && root->right == NULL) return true;
	if(root->left != NULL && root->right != NULL) return (full_binary_tree(root->left) && full_binary_tree(root->right));
	return false;
}
bool perfect_binary_tree(node *root,int depth,int level){

	if(root == NULL) return true;

	// check if root is a leaf node (node that doesn't have any childe);
	if(root->left == NULL && root->right == NULL){
		// false in all case exept when the node is a leaf node
		return (depth == (level + 1));
	}
	// if it's not a leaf node (internal node) and have at lease one node only
	// one node only and not null in left and right at all because the first condition remove this case;

	if(root->left == NULL || root->right == NULL){
		return false;
	}

	return (perfect_binary_tree(root->left,depth,level+1) && perfect_binary_tree(root->right,depth,left+1));
}



void main(){
	node *mama = new_node(1969);                                
	node *amira = new_node(2000);
	node *tamer = new_node(2006);
	node *mchicho = new_node(2021);
	node *mesmous = new_node(2022);
	node *yasser = new_node(2002);
	node *kaka = new_node(1999);
	node *mimi = new_node(2051);
	node *jiji = new_node(111);

	mama->left = tamer;
	mama->right = amira;

	tamer->left = kaka;
	tamer->right = jiji;

	amira->left = mesmous;
	amira->right = mchicho;


				//       mama
				// /		  \
			 //   tamer	 	 amira
			 //  /    \           /    \
			 //               mesmous   mchicho
	//		  /      \           /
		//   kaka     jiji       mimi


	
	printf("%d",full_binary_tree(mama));

	printf("\ndone!\n");


}