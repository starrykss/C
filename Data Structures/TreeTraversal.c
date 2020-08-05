// C program for different tree traversals 
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
typedef int element;
typedef struct node { 
	element data; 
	struct node *left; 
	struct node *right; 
} Node; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
Node *newNode(element data) { 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(Node* node) { 
	if (node == NULL) 
		return; 

	// first recur on left subtree 
	printPostorder(node->left); 

	// then recur on right subtree 
	printPostorder(node->right); 

	// now deal with the node 
	printf("%d ", node->data); 
} 

/* Given a binary tree, print its nodes in inorder*/
void printInorder(Node *node) { 
	if (node == NULL) 
		return; 

	/* first recur on left child */
	printInorder(node->left); 

	/* then print the data of node */
	printf("%d ", node->data); 

	/* now recur on right child */
	printInorder(node->right); 
} 

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(Node* node) { 
	if (node == NULL) 
		return; 

	/* first print data of node */
	printf("%d ", node->data); 

	/* then recur on left sutree */
	printPreorder(node->left); 

	/* now recur on right subtree */
	printPreorder(node->right); 
}	 

/* Driver program to test above functions*/
void main() { 
    /*
     *            G.1
     *          /      \
     *       D.2       I.3
     *      /  \      /   \
     *    B.4  E.5   H.6   M.7
     *    /                /  \
     *  A.8              J.9  N.10
     *                           \
     *                           Q.11
     */

	Node *root = newNode(1);                        // G 
	root->left			 = newNode(2);              // D
	root->right		 = newNode(3);                  // I
	root->left->left	 = newNode(4);              // B
	root->left->right = newNode(5);                 // E
    root->left->left->left = newNode(8);            // A
    root->right->left = newNode(6);                 // H
    root->right->right = newNode(7);                // M
    root->right->right->left = newNode(9);          // J
    root->right->right->right = newNode(10);        // N
    root->right->right->right->right = newNode(11); // Q

	printf("\nPreorder traversal of binary tree is \n"); 
	printPreorder(root); 

	printf("\nInorder traversal of binary tree is \n"); 
	printInorder(root); 

	printf("\nPostorder traversal of binary tree is \n"); 
	printPostorder(root); 
} 

// source from : https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/