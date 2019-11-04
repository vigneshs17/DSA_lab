// C program to insert a node in AVL tree 
#include<stdio.h> 
#include<stdlib.h> 

// An AVL tree node 
struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 

//function to get maximum of two integers 
int max(int a, int b); 

//function to get the height of the tree 
int height(struct Node *N) { 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

//function to get maximum of two integers 
int max(int a, int b) { 
	return (a > b)? a : b; 
} 

struct Node* minValueNode(struct Node* node) { 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
}
// function that creates and returns a new node*/
struct Node* newNode(int key) { 
	struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially added at leaf 
	return(node); 
} 

//function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y) { 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	return x; 
} 

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct Node *leftRotate(struct Node *x) { 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	// Return new root 
	return y; 
} 

// get balance factor of node N 
int getBalance(struct Node *N) { 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* insert(struct Node* node, int key) { 
	//perform normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 

	//Update height of the ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	//Get the balance factor of this ancestor node to check whether this node became unbalanced 
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) { 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) { 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Recursive function to delete a node with given key 
// from subtree with given root. It returns root of 
// the modified subtree. 
struct Node* deleteNode(struct Node* root, int key) { 
    //standard BST delete function 
  
    if (root == NULL) 
        return root; 
  
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
    //if the key is found
    else { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) { 
            struct Node *temp = root->left ? root->left : 
                                             root->right; 
  
            // No child case 
            if (temp == NULL) { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct Node* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->key = temp->key; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    //update height of the current node 
    root->height = 1 + max(height(root->left), height(root->right)); 
  
    //get the balance factor of this node to check if the node is unbalanced 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0) { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
}

//function to print preorder traversal 
void preOrder(struct Node *root) { 
	if(root != NULL) { 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

int main() {
    struct Node *root = NULL; 
    int data, ch;
    while(1) {
        printf("1. Insert a new node\n");
        printf("2. Delete a node\n");
        printf("3. Print the tree\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Enter the valueof the node to be inserted: ");
                scanf("%d", &data);
                root=insert(root, data);
                break;
            
            case 2:
                printf("Enter the value of the node to be deleted: ");
                scanf("%d", &data);
                root=deleteNode(root, data);
                break;
            
            case 3:
                preOrder(root);
                break;
            
            default:
                return 0;
        }
    }
}


