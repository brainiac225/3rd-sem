#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool c = false;

struct node{
    int key;
    struct node *left, *right;
};


struct node *newNode(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct node *root){
    if(root!=NULL)
    return;
    printf("%d", root->key);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root!=NULL)
    return;
    inorder(root->left);
    printf("%d", root->key);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root!=NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->key);
}

bool Search(struct node *root, int key){
    while(root!=NULL){
        if(key<root->key){
            root = root->left;
        }
        else
        if(key>root->key){
            root = root->right;
        }
        return true;
    }
    return false;
}

struct node *Insert(struct node *node, int key){
    if(node==NULL)
    return newNode(key);
    
    if(key<node->key){
        node->left = Insert(node->left, key);
    }
    else
    if(key>node->key){
        node->key = Insert(node->right, key);
    }
    return node;
}

int main(){
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    
    printf("The List in Inorder is: ");
    Inorder(root);
    
    printf("The List in Preorder is: ");
    Preorder(root);
    
    printf("The List in Postorder is: ");
    Postorder(root);
    
    if(Search(root, 40)){
        printf("Found");
    }
    else
    printf("Not Found");
    
    return 0;
}
