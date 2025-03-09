#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the AVL tree
struct StudentAVLNode {
    int rollNumber;
    struct StudentAVLNode* left;
    struct StudentAVLNode* right;
    int height;
};

// Function to get the height of a node
int getNodeHeight(struct StudentAVLNode* node) {
    return node ? node->height : 0;
}

// Function to create a new AVL node with a given roll number
struct StudentAVLNode* createAVLNode(int rollNumber) {
    struct StudentAVLNode* node = (struct StudentAVLNode*)malloc(sizeof(struct StudentAVLNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->rollNumber = rollNumber;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Function to update the height of a node
void updateHeight(struct StudentAVLNode* node) {
    if (node) {
        node->height = 1 + (getNodeHeight(node->left) > getNodeHeight(node->right) ? getNodeHeight(node->left) : getNodeHeight(node->right));
    }
}

// Function to get the balance factor of a node
int getBalanceFactor(struct StudentAVLNode* node) {
    return node ? getNodeHeight(node->left) - getNodeHeight(node->right) : 0;
}

// Perform a right rotation to balance the tree
struct StudentAVLNode* performRightRotation(struct StudentAVLNode* y) {
    struct StudentAVLNode* x = y->left;
    struct StudentAVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Perform a left rotation to balance the tree
struct StudentAVLNode* performLeftRotation(struct StudentAVLNode* x) {
    struct StudentAVLNode* y = x->right;
    struct StudentAVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Insert a node into the AVL tree and maintain balance
struct StudentAVLNode* insertStudent(struct StudentAVLNode* root, int rollNumber) {
    if (!root) {
        return createAVLNode(rollNumber);
    }

    if (rollNumber < root->rollNumber) {
        root->left = insertStudent(root->left, rollNumber);
    } else if (rollNumber > root->rollNumber) {
        root->right = insertStudent(root->right, rollNumber);
    } else {
        return root;
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    if (balance > 1 && rollNumber < root->left->rollNumber) {
        return performRightRotation(root);
    }
    if (balance < -1 && rollNumber > root->right->rollNumber) {
        return performLeftRotation(root);
    }
    if (balance > 1 && rollNumber > root->left->rollNumber) {
        root->left = performLeftRotation(root->left);
        return performRightRotation(root);
    }
    if (balance < -1 && rollNumber < root->right->rollNumber) {
        root->right = performRightRotation(root->right);
        return performLeftRotation(root);
    }

    return root;
}

// Inorder traversal to print the tree (sorted order)
void inorderTraversal(struct StudentAVLNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->rollNumber);
        inorderTraversal(root->right);
    }
}

// Function to check if the tree is AVL
int isAVLTree(struct StudentAVLNode* root) {
    if (!root) return 1;

    int balance = getBalanceFactor(root);

    // Check if current node is balanced
    if (balance < -1 || balance > 1) {
        return 0;  // Unbalanced
    }

    // Check left and right subtrees recursively
    return isAVLTree(root->left) && isAVLTree(root->right);
}

// Main function to demonstrate AVL tree operations
int main() {
    struct StudentAVLNode* root = NULL;
    int rollNumber, choice;

    while (1) {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert student\n");
        printf("2. Display tree (In-order traversal)\n");
        printf("3. Check if tree is AVL\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the roll number to insert: ");
                scanf("%d", &rollNumber);
                root = insertStudent(root, rollNumber);
                printf("Student with roll number %d inserted.\n", rollNumber);
                break;

            case 2:
                printf("In-order traversal of the AVL tree: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                if (isAVLTree(root)) {
                    printf("The tree is balanced (AVL Tree).\n");
                } else {
                    printf("The tree is not balanced (Not AVL Tree).\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
