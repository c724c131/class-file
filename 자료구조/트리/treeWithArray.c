///이진 탐색 트리 기본적으로 '같다'는 없다.
/// key(왼쪽서브트리) < key(루트노드) < key(오른쪽서브트리)
/// 중위순회시정렬됨
/// 최악의 경우 트리의 높이많큼 비교함 
/// 


#include <stdio.h>
#include <stdlib.h>

#define N 100

int BST[N];

void insertKey(int root, int key) {
    while (1) {
        if (root >= N) { ///N이라고 꼭 꽉찬 트리는 아님
            printf("Overflow.\n");
            return;
        }

        if (BST[root] == 0) {
            BST[root] = key;
            return;
        }

        if (key < BST[root])
            root = root * 2; //왼쪽 자식
        else if (key > BST[root])
            root = root * 2 + 1; //오른쪽 자식
        else
            return;
    }
}

void preOrder(int root) {

    if (BST[root] != 0) {
        printf("[%d] ", BST[root]);
        preOrder(root * 2);
        preOrder(root * 2 + 1);
    }
}

int main(void) {
    int keys[] = { 35, 18, 7 ,26 ,12, 3, 68, 22, 30 ,99}; //ppt 트리

    for (int i = 0; i < 10;i++)
        insertKey(1, keys[i]); //1이 전체 트리 (root 노드)

    printf("Pre : "); preOrder(1);
    return 0;
}

//삭제, 높이, 노드관련 연산
