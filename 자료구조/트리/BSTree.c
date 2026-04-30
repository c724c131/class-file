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

    else if (key > root->data)
        root->right = insertNode(root->right, key);

    return root;
}

void preOrder(TreeNode* root) {
    if (root != NULL) {
        printf("[%2d] ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

TreeNode* minValueNode(TreeNode* root) {
    TreeNode* cur = root;
    while (cur->left != NULL)
        cur = cur->left;

    return cur;
}

TreeNode* maxValueNode(TreeNode* root) {
    TreeNode* cur = root;
    while (cur->right != NULL)
        cur = cur->right;

    return cur;
}

TreeNode* deleteNode(TreeNode* root, Telement key) {

    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            TreeNode* tmp = root->right; //오른쪽이 없으면 NULL이 될것
            free(root);
            return tmp;
        }
        else if (root->right == NULL) {
            TreeNode* tmp = root->left;
            free(root);
            return tmp;
        }
        else {
            //자식이 둘일때는 보통 노드를 진짜로 삭제하지 않음 (복잡하다)
            //서브트리의 MAX를 계승자로 사용 또는 오른쪽 서브트리의 MIN을 계승자로 사용
            //오른쪽 노드 계승자 사용하면 case1에 걸린다 (root->left == NULL)

            TreeNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(void) {
    TreeNode* root = NULL;

    Telement keys[] = { 35, 18, 7 ,26 ,12, 3, 68, 22, 30 ,99 }; //ppt 트리

    for (int i = 0; i < 10; i++) {
        root = insertNode(root, keys[i]);
        preOrder(root);
        printf("\n");
    }

    printf("\n");

    printf("Min : [%d] , Max : [%d]\n", minValueNode(root)->data, maxValueNode(root)->data);

    /*root = deleteNode(root, 30);preOrder(root);printf("\n");
    root = deleteNode(root, 26);preOrder(root);printf("\n");*/
    root = deleteNode(root, 18);preOrder(root);printf("\n");
    return 0;
}

//삭제, 높이, 노드관련 연산
