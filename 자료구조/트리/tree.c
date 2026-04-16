#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char Telement;

typedef struct Treenode{
	Telement data;
	struct Treenode* left;
	struct Treenode* right;
}Treenode;

Treenode* makeNode(Telement data, Treenode* left, Treenode* right) {

	Treenode* node = (Treenode*)malloc(sizeof(Treenode));
	node->data = data;
	node->left = left;
	node->right = right;

	return node;
}

void preOrder(Treenode* root) {
	if (root != NULL) {
		printf("[%c]", root->data); //집 주인을 만나는 건 출력
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
int main(void) {
	
	//트리를 만들려면 노드를 아래에서 부터 만들어야 한다.
	Treenode* N6 = makeNode('F',NULL,NULL);
	Treenode* N5 = makeNode('E',N6,NULL);
	Treenode* N4 = makeNode('D',NULL,NULL);
	Treenode* N3 = makeNode('C',NULL,NULL );
	Treenode* N2 = makeNode('B',N4,N5);
	Treenode* N1 = makeNode('A',N2,N3);

	printf("Pre  : "); preOrder(N1);printf("\n");
	printf("In   : "); inOrder(N1);printf("\n");
	printf("Post : "); postOrder(N1);printf("\n\n");

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
