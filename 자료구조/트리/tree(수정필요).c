#include <stdio.h>
#include <stdlib.h>

typedef char Telement;

typedef struct Treenode {
    Telement data;
    struct Treenode* left;
    struct Treenode* right;
} Treenode;

Treenode* makeNode(Telement data, Treenode* left, Treenode* right) {
    Treenode* node = (Treenode*)malloc(sizeof(Treenode));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

void preOrder(Treenode* root) {
    if (root != NULL) {
        printf("[%c]", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Treenode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("[%c]", root->data);
        inOrder(root->right);
    }
}

void postOrder(Treenode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%c]", root->data);
    }
}

int nodeCount(Treenode* root) {
    if (root == NULL)
        return 0;

    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

int isExternal(Treenode* root) {
    return root != NULL && root->left == NULL && root->right == NULL;
}

int leafNodeCount(Treenode* root) {
    if (root == NULL)
        return 0;

    if (isExternal(root))
        return 1;

    return leafNodeCount(root->left) + leafNodeCount(root->right);
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int height(Treenode* root) {
    if (root == NULL)
        return 0;

    return 1 + MAX(height(root->left), height(root->right));
}

void treeReverse(Treenode* root) {
    if (root == NULL)
        return;

    Treenode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    treeReverse(root->left);
    treeReverse(root->right);
}

void freeTree(Treenode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    Treenode* N6 = makeNode('F', NULL, NULL);
    Treenode* N5 = makeNode('E', N6, NULL);
    Treenode* N4 = makeNode('D', NULL, NULL);
    Treenode* N3 = makeNode('C', NULL, NULL);
    Treenode* N2 = makeNode('B', N4, N5);
    Treenode* N1 = makeNode('A', N2, N3);

    printf("Pre  : ");
    preOrder(N1);
    printf("\n");

    printf("In   : ");
    inOrder(N1);
    printf("\n");

    printf("Post : ");
    postOrder(N1);
    printf("\n\n");

    printf("Node Count : %d\n", nodeCount(N1));
    printf("Leaf Count : %d\n", leafNodeCount(N1));
    printf("Height : %d\n", height(N1));

    freeTree(N1);

    return 0;
}
