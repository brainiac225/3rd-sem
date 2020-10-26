BINARY SEARCH TREE (INSERTION & SEARCHING(1&2) with PREORDER, INORDER, POSTORDER TRAVERSALS & 3 types of DELETION)-

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


bool Search1(struct node *root, int key){
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

bool Search2(struct node *node, int key){
    if(node==NULL){
        return false;
    }
    else
    if(node->key == key){
        return true;
    }
    else
    if(key<node->key)
    Search(node->left, key);
    else
    if(key>node->key)
    Search(node->right, key);
}

struct node *MinVal(struct node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
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

struct node *Delete(struct node *node, int key){
    c = Search2(node, key);
    if(node==NULL)
    return node;
    
    if(key<node->key){
        node->left = Delete(node->left, key);
    }
    else
    if(key>node->key){
        node->right = Delete(node->right, key);
    }
    
    else{
        if(node->left==NULL && node->right==NULL){
            free(node);
            node = NULL;
            return node;
        }
        else 
        if(node->left==NULL){
            struct node *temp = node;
            node = node->right;
            free(temp);
            return node;
        }
        else
        if(node->right ==NULL){
            struct node *temp = node;
            node = node->left;
            free(temp);
            return node;
        }
        
        else{
            struct node *temp = MinVal(node->right);
            node->key = temp->key;
            node->right = Delete(node->right, temp->key);
        }
        
    }
    return node;
}


int main(){
    struct node *root = NULL;
    root = Insert(root, 80);// this is the main Root node
    Insert(root, //somevalue);
    Insert(root, //somevalue);
    Insert(root, //somevalue);
    Insert(root, //somevalue);
    Insert(root, //somevalue);
    Insert(root, //somevalue);
    
    printf("The List in Inorder is: ");
    Inorder(root);
    
    if(Search1(root, //somevalue)){
        printf("Found");
    }
    else
    printf("Not Found");
    
    Delete(root, //somevalue);
    if(c){
        printf("Element Deleted");
        printf("Tree in Inorder is: ");
        Inorder(root);
    }
    else
    printf("Not found");
    
    return 0;
}
