#include<stdio.h>
#include<stdlib.h>

//function declaration
struct Node* insert(struct Node*, int);
int search(struct Node*, int);
struct Node* delete(struct Node*, int);
struct Node* minValueNode(struct Node*);
void inOrder(struct Node*);
void preOrder(struct Node*);
void postOrder(struct Node*);

//define a node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

//function to create a new node and return its address
struct Node* getNewNode(struct Node *root, int data) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//function to insert a new node 
struct Node* insert(struct Node* root, int data) {
    if(root==NULL) {
        root=getNewNode(root, data);
        return root;
    }

    if(data<=root->data)
        root->left=insert(root->left, data);
    else
        root->right=insert(root->right, data);
    return root;
}

//function to search for a node in the binary search tree
int search(struct Node* root, int data) {
    if(root==NULL) 
        return -1;
    else if(data<root->data)
        return search(root->left, data);
    else if(data>root->data)
        return search(root->right, data);
    else
        return 1;
}


//function to return the min value of the bst
struct Node* minValueNode(struct Node *node) {
    struct Node* current = node;
    while(current && current->left!=NULL) 
        current=current->left;

    return current;
}
//function to delete a node in the bst
struct Node* delete(struct Node* root, int data) {
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left=delete(root->left, data);
    else if(data>root->data)
        root->right=delete(root->right, data);
    //found the node to be deleted
    else {
        //node with one or zero children
        if(root->left==NULL) {
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL) {
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        //node with two children
        struct Node *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=delete(root->right, temp->data);
    }
    return root;
}
//function to print the bst in in-order
void inOrder(struct Node* root) {
    if(root!=NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

//function to print the bst in pre order 
void preOrder(struct Node* root) {
    if(root!=NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//function to print the bst in post order
void postOrder(struct Node* root) {
    if(root!=NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root=NULL;
    int choice, data, val;
    while(1) {
        printf("1.Insert a new node\n");
        printf("2.Search a node\n");
        printf("3.Delete a node\n");
        printf("4.In order traversal\n");
        printf("5.Pre order traversal\n");
        printf("6.Post order traversal\n");
        printf("7.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value of the node: ");
                scanf("%d", &data);
                root=insert(root, data);
                break;
            case 2:
                printf("Enter the node to search for: ");
                scanf("%d", &data);
                val=search(root, data);
                if(val==1)
                    printf("Found\n");
                else
                    printf("Not found\n");
                break;
            case 3:
                printf("Enter the node to delete\n");
                scanf("%d",&data);
                root=delete(root, data);
                break;
            case 4:
                inOrder(root);
                printf("\n");
                break;
            case 5:
                preOrder(root);
                printf("\n");
                break;
            case 6:
                postOrder(root);
                printf("\n");
                break;
            default:
                return 0;
        }
    }
}