#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BSTnode {
 int data;
 struct BSTnode* left;
 struct BSTnode* right;
};

struct queue{
    struct BSTnode* arr[50];
    int front;
    int rear;
};
struct BSTnode* createBST(struct BSTnode*);
void insert(struct BSTnode**,int);
struct BSTnode* getNewNode(int);
int findMin(struct BSTnode*);
int findMax(struct BSTnode*);
int findMaxRec(struct BSTnode*);
int max(int,int);
int findHeight(struct BSTnode*);
void enqueue(struct queue*, struct BSTnode*);
void levelOrder(struct BSTnode*,struct queue*);
struct BSTnode* dequeue(struct queue*);
bool isQueueEmpty(struct queue*);
void preOrder(struct BSTnode*);
void postOrder(struct BSTnode*);
void inOrder(struct BSTnode*);

int main(){
    struct queue theQueue;
    theQueue.rear = -1;
    theQueue.front = -1;
    struct BSTnode* rootPtr = NULL;
    rootPtr = createBST(rootPtr);
    printf("Min - %d \n", findMin(rootPtr));
    printf("Max - %d \n", findMax(rootPtr));
    printf("Maxrec - %d \n ", findMaxRec(rootPtr));
    printf("Height - %d \n", findHeight(rootPtr));
    levelOrder(rootPtr,&theQueue);
    printf("The post order traversel is : \n");
    postOrder(rootPtr);
    printf("The in order traversel is : \n");
    inOrder(rootPtr);
    printf("The pre order traversel is : \n");
    preOrder(rootPtr);
    return 0;
}

void enqueue(struct queue* theQueue, struct BSTnode* node){
    if(theQueue->front == -1){
        theQueue->front++;
        theQueue->rear++;
        theQueue->arr[theQueue->rear] = node;
    }
    else{
        theQueue->rear++;
        theQueue->arr[theQueue->rear] = node;
    }
}

struct BSTnode* dequeue(struct queue* theQueue ){
    struct BSTnode* node = theQueue->arr[theQueue->front];
    theQueue->front++;
    return node;
}

void levelOrder(struct BSTnode* rootPtr,struct queue* theQueue){
    enqueue(theQueue,rootPtr);
    while(!isQueueEmpty(theQueue)){
        struct BSTnode* theNode = dequeue(theQueue);
        printf("The element is %d\n", theNode->data);
        if(theNode->left!=NULL){
            enqueue(theQueue,theNode->left);
        }
        if(theNode->right!=NULL){
            enqueue(theQueue,theNode->right);
        }
    }
}

void preOrder(struct BSTnode* rootPtr){
    printf("The Data is %d\n",rootPtr->data);
    if(rootPtr->left!=NULL)preOrder(rootPtr->left);
    if(rootPtr->right!=NULL)preOrder(rootPtr->right);
}

void postOrder(struct BSTnode* rootPtr){
    if(rootPtr->left!=NULL)postOrder(rootPtr->left);
    if(rootPtr->right!=NULL)postOrder(rootPtr->right);
    printf("The Data is %d\n",rootPtr->data);
}

void inOrder(struct BSTnode* rootPtr){
    if(rootPtr->left!=NULL)inOrder(rootPtr->left);
    printf("The Data is %d\n",rootPtr->data);
    if(rootPtr->right!=NULL)inOrder(rootPtr->right);
}

bool isQueueEmpty(struct queue* theQueue){
    if((theQueue->front == -1) || (theQueue->front == theQueue->rear+1)){
        return true;
    }
    return false;
}

struct BSTnode* createBST(struct BSTnode* rootPtr){
insert(&rootPtr,33);
insert(&rootPtr,16);
insert(&rootPtr,36);
insert(&rootPtr,15);
insert(&rootPtr,20);
insert(&rootPtr,34);
insert(&rootPtr,39);
insert(&rootPtr,12);
return rootPtr;

}

void insert(struct BSTnode** root,int item){
    if(*root==NULL){
        *root = getNewNode(item);
    }
    else if(item <= (*root)->data){
        insert(&((*root)->left),item);
    }
    else{
        insert(&((*root)->right),item);
    }
}

struct BSTnode* getNewNode(int data){
    struct BSTnode* p = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    p->left = NULL;
    p->right = NULL;
    p->data = data;
    return p;
}

int findMin(struct BSTnode* root){
    struct BSTnode* p = root;
    while(p->left !=NULL){
        p = p->left;
    }
    return p->data;
}

int findMax(struct BSTnode* root){
    struct BSTnode* p = root;
    while(p->right !=NULL){
        p = p->right;
    }
    return p->data;
}

int findMaxRec(struct BSTnode* root){
    struct BSTnode* p = root;
    if(p->right !=NULL){
        return findMaxRec(p->right);
    }
    return p->data;
}

int findHeight(struct BSTnode* root){
    if(root!=NULL){
        return 1 + max(findHeight(root->left),findHeight(root->right));
    }
    return -1;
}

int max(int n1,int n2){
    if(n1>n2) return n1;
    return n2;
}
