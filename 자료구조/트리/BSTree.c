///이진 탐색 트리 기본적으로 '같다'는 없다.
/// key(왼쪽서브트리) < key(루트노드) < key(오른쪽서브트리)
/// 중위순회시정렬됨
/// 최악의 경우 트리의 높이많큼 비교함 
/// 


#include <stdio.h>
#include <stdlib.h>

typedef int Telement;

typedef struct TreeNode {
    Telement data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(Telement key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

TreeNode* insertNode(TreeNode* root, Telement key) {

    if (root == NULL)
        return makeNode(key);

    if (key < root->data)
        root->left = insertNode(root->left, key);

    else if (key < root->data)
        root->right = insertNode(root->right, key);
}

void preOrder(TreeNode* root) {
    if (root != NULL) {
        printf("[%2d] ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(void) {
    TreeNode* root = NULL;

    Telement keys[] = { 35, 18, 7 ,26 ,12, 3, 68, 22, 30 ,99}; //ppt 트리

    for (int i = 0; i < 10;i++) {
        root = insertKey(1, keys[i]); //1이 전체 트리 (root 노드)
        preOrder(root);
        printf("\n");
    }
    printf("\n");

    printf("Pre : "); preOrder(1);
    return 0;
}

//삭제, 높이, 노드관련 연산
