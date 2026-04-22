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

    node->data = data;
    node->left = left;
    node->right = right;
     
    return node;
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

void freeTree(Treenode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

#define N 10

typedef Treenode* element; ///트리 노드 포인터
typedef struct StackType {
    element stack[N];
    int top;
}StackType;

void init(StackType* S) {
    S->top = -1;
}

int isEmpty(StackType* S) {
    return S->top == -1;
}

int isFull(StackType* S) {
    return S->top == N - 1;
}

void push(StackType* S, element e) {
    if (isFull(S)) {
        printf("overflow\n");
    }
    else {
        S->top++;
        S->stack[S->top] = e;
    }
}

element pop(StackType* S) {
    if (isEmpty(S)) {
        printf("Empty\n");
        return NULL;
    }
    element e = S->stack[S->top];
    S->top--;
    return e;
}

void iterPreOrder(element root) {
    StackType S;
    init(&S);

    while (root != NULL || !isEmpty(&S)) {

        //왼쪽 끝까지 이동(L)
        while (root != NULL) {
            printf(" [%c] ", root->data);
            if (root->right != NULL)
                push(&S, root->right);

            root = root->left;
        }
        if (!isEmpty(&S)) {
            root = pop(&S);
        }
    }
}

void iterInOrder(element root) {
    StackType S;
    init(&S);

    while (root != NULL || !isEmpty(&S)) {

        //왼쪽 끝까지 이동(L)
        while (root != NULL) {
            push(&S, root);
            root = root->left;
        }
        root = pop(&S);
        printf(" [%c] ", root->data);

        //오른쪽으로 이동 (R)
        root = root->right;
    }
}

void iterPostOrder(element root) {
    StackType S1, S2;
    init(&S1);
    init(&S2);

    if (root == NULL)
        return;

    push(&S1, root);

    while (!isEmpty(&S1)) {
        root = pop(&S1);
        push(&S2, root);

        if (root->left != NULL)
            push(&S1, root->left);

        if (root->right != NULL)
            push(&S1, root->right);
    }

    while (!isEmpty(&S2)) {
        root = pop(&S2);
        printf(" [%c] ", root->data);
    }
}

void iterTreeReverse(Treenode* root) {
    if (root == NULL)
        return;

    StackType S;
    init(&S);

    push(&S, root);

    while (!isEmpty(&S)) {
        element cur = pop(&S);

        element temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;

        if (cur->left) {
            push(&S, cur->left);
        }
        if (cur->right) {
            push(&S, cur->right);
        }
    }
}

int main(void) {
    Treenode* N6 = makeNode('F', NULL, NULL);
    Treenode* N5 = makeNode('E', N6, NULL);
    Treenode* N4 = makeNode('D', NULL, NULL);
    Treenode* N3 = makeNode('C', NULL, NULL);
    Treenode* N2 = makeNode('B', N4, N5);
    Treenode* N1 = makeNode('A', N2, N3);

    printf("Pre  : ");
    iterPreOrder(N1);
    printf("\n");

    printf("In   : ");
    iterInOrder(N1);
    printf("\n");

    printf("Post : ");
    iterPostOrder(N1);
    printf("\n\n");

    iterTreeReverse(N1);
    printf("In   : ");
    iterInOrder(N1);
    printf("\n");

    printf("Node Count : %d\n", nodeCount(N1));
    printf("Leaf Count : %d\n", leafNodeCount(N1));
    printf("Height : %d\n", height(N1));

    freeTree(N1);

    return 0;
}

//        A
//      /   |
//     B     C
//   /   | 
//  D    E
// 	    /
//	   F

// L V R
// 
// V L R 전위 pre order
// L V R 중위 in order
// L R V 후위 post order : D F E B C A
