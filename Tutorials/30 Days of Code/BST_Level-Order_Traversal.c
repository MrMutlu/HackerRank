#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

void levelOrder(Node* root){
  //Write your code here
    if(root==NULL) 
        return;
    else {
    
        struct Node* queue[1000];
        int front = 0, rear = 0;

        // Enqueue the root node
        queue[++rear] = root;
        
        while (front != rear) {
            // Dequeue a node and print its value
            struct Node* current = queue[++front];
            printf("%d ", current->data);

            // Enqueue the left child if exists
            if (current->left != NULL) {
                queue[++rear] = current->left;
            }

            // Enqueue the right child if exists
            if (current->right != NULL) {
                queue[++rear] = current->right;
        }
    }

    printf("\n");
        
    }

    
}

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder(root);
    return 0;
    
}
