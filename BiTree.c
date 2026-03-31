#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *Left;
    struct TreeNode *Right;
    
} TreeNode, *PtrToNode, *Tree;

Tree CreateTree(){
    Tree root = malloc(sizeof(TreeNode));
    if(root){
        return root;
    }
    return NULL;
}

Tree CreateNode(int data){
    Tree newNode = malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

Tree insert(Tree root, int data){
    if(!root){
        return CreateNode(data);
    }
    if(data < root->data){
        root->Left = insert(root->Left, data);
    }else if(data > root->data){
        root->Right = insert(root->Right, data);
    }
    return root;
}

void PreOrder(Tree root){
    if(!root) return;
    printf("%d", root->data);
    PreOrder(root->Left);
    PreOrder(root->Right);
}

void InOrder(Tree root){
    if(!root) return;
    InOrder(root->Left);
    printf("%d", root->data);
    InOrder(root->Right);
}

void PostOrder(Tree root){
    if(!root) return;
    PostOrder(root->Left);
    PostOrder(root->Right);
    printf("%d", root->data);
}

// void levelOrder(Tree root){
//     if(!root) return;
// }需要队列，时间不够

Tree search(Tree root, int target){
    if(!root || root->data == target){
        return root;
    }
    if(target < root->data){
        return search(root->Left, target);
    }
    return search(root->Right, target);
}

int getHeight(Tree root){
    if(!root) return 0;
    int leftHeight = getHeight(root->Left);
    int RightHeight = getHeight(root->Right);
    return (leftHeight > RightHeight ? leftHeight : RightHeight) + 1;
}

int CountNodes(Tree root){
    if(!root) return 0;
    return 1 + CountNodes(root->Left) + CountNodes(root->Right);
}

void freeTree(Tree root){
    if(!root) return;
    freeTree(root->Left);
    freeTree(root->Right);
    free(root);
}
int main(){


    return 0;
}