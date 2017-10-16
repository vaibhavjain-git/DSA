#include<stdio.h>
#include<stdlib.h>

struct BSTnode {
 int data;
 struct BSTnode* left;
 struct BSTnode* right;
};
struct BSTnode* createBST(struct BSTnode*);
struct BSTnode* insert(struct BSTnode*,int);
struct BSTnode* getNewNode(int);

int main(){
    struct BSTnode* rootPtr = NULL;
    rootPtr = createBST(rootPtr);
    printf("%d\n",rootPtr->data);
    printf("%d\n",rootPtr->left->data);
    printf("%d\n",rootPtr->right->data);
    printf("%d\n",rootPtr->left->left->data);
    return 0;
}

struct BSTnode* createBST(struct BSTnode* rootPtr){
rootPtr = insert(rootPtr,15);
rootPtr = insert(rootPtr,10);
rootPtr = insert(rootPtr,20);
rootPtr = insert(rootPtr,5);
return rootPtr;

}

struct BSTnode* insert(struct BSTnode* root,int item){
    struct BSTnode* p = root;
    if(root==NULL){
        root = getNewNode(item);
    }
    else if(item <= root->data){
        root->left = insert(root->left,item);
    }
    else{
        root->right = insert(root->right,item);
    }
    return root;

}

struct BSTnode* getNewNode(int data){
    struct BSTnode* p = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    p->left = NULL;
    p->right = NULL;
    p->data = data;
    return p;
}
