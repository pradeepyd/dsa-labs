#include<stdio.h>
#include<stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST *root = NULL;

void inorder(struct BST *root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d ",root ->data);
        inorder(root ->right);
    }
}
void preorder(struct BST *root){
    if(root != NULL){
        printf("%d ",root ->data);
        preorder(root -> left);
        preorder(root -> right);
    }
}
void postorder(struct BST *root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ",root ->data);
    }
}

struct BST * search(struct BST *root, int key){
    if(root == NULL || key == root -> data)
       return root;
    else if (key < root -> data)
        return search(root ->left,key);
    else
        return search(root ->right,key);
}

struct BST * findMax(struct BST *root){
    while (root -> right != NULL)
    {
        root = root -> right;
    }
    return root;
    
}

struct BST * findMin(struct BST *root){
    while (root -> left != NULL)
    {
        root = root -> left;
    }
    return root; 
}

struct BST * insert(struct BST *root, int element){
    if(root == NULL){
        root = (struct BST *)malloc(sizeof(struct BST));
        root->left = NULL;
        root->right = NULL;
        root->data = element;
    }
    else if(element <root->data){
        root->left = insert(root ->left,element);
    }
    else{
        root ->right = insert(root ->right,element);
    }
    return root;
}

struct BST * deletionNode(struct BST *root, int key){
    if(root == NULL){
        return root;
    }
    else if(key <root->data){
        root->left = deletionNode(root ->left,key);
    }
    else if(key > root->data){
        root ->right = deletionNode(root ->right,key);
    }
    else {
        struct BST* temp;
        if(root -> left == NULL){
            temp = root ->right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            temp = root ->left;
            free(root);
            return temp;
        }
        else{
            temp = findMin(root -> right);
            root -> data = temp -> data;
            root->right = deletionNode(root -> right,root->data);
        }
    }
    return root;
}

int main(){
    struct BST *root = NULL, *temp = NULL;
    int choice , element;
    while(1){
        printf("1.INSERT\n2.DELETE\n3.SEARCH\n");
        printf("4.FIND MIN\n5.FIND MAX\n");
        printf("6.INORDER\n7.PREORDER\n8.POSTORDER\n");
        printf("Enter your choice?");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Element? ");
                scanf("%d",&element);
                root = insert(root,element);
                printf("%d INSERTED\n",element);
                break;
            case 2:
                printf("element? ");
                scanf("%d",&element);
                root = deletionNode(root,element);
                printf("%d was Deleted\n",element);
                break;
            case 3:
                printf("Element? ");
                scanf("%d",&element);
                temp = search(root,element);
                if(temp)
                    printf("%d was found\n",temp ->data);
                else
                    printf("SEARCH UNSUCCESSFUL\n");
                break;
            case 4:
                temp = findMin(root);
                if(temp)
                    printf("%d is minimum\n",temp ->data);
                else
                    printf("EMPTY TREE\n");
                break;
            case 5:
                temp = findMax(root);
                if(temp)
                    printf("%d is maximum\n",temp ->data);
                else
                    printf("EMPTY TREE\n");
                break;
            case 6:
                inorder(root);
                printf(" \n");
                break;
            case 7:
                preorder(root);
                printf(" \n");
                break;
            case 8:
                postorder(root);
                printf(" \n");
                break;
        }
    }
    return 0;
}

