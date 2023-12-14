#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

void printLeafNodes(struct Node *root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

struct Node *mirrorTree(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node *temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);

    return root;
}

void printLevelOrder(struct Node *root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}

void printTreeLevelOrder(struct Node *root) {
    int height = findHeight(root);
    int i;
    for (i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        printLevelOrder(root, i);
        printf("\n");
    }
}

void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Original Tree (Level-wise):\n");
    printTreeLevelOrder(root);

    int height = findHeight(root);
    printf("\nHeight of the Tree: %d\n", height);

    printf("\nLeaf Nodes: ");
    printLeafNodes(root);
    printf("\n");

    struct Node *mirrorRoot = mirrorTree(root);

    printf("\nMirror Image of the Tree (Level-wise):\n");
    printTreeLevelOrder(mirrorRoot);

    freeTree(root);
    freeTree(mirrorRoot);

    return 0;
}
