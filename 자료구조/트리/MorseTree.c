#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    char alpha;
    char code[N];
}Code;

Code table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}
};

typedef struct TreeNode {
    char alpha;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(char alpha) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->alpha = alpha;
    node->left = node->right = NULL;

    return node;
}

TreeNode* makeMorseTree() {
    TreeNode* root = makeNode('0');

    for (int i = 0;i < 26;i++) {
        TreeNode* p = root;
        int n = strlen(table[i].code);

        for (int j = 0; j < n;j++) {

            char c = table[i].code[j];

            if (c == '.') {
                if (p->left == NULL)
                    p->left = makeNode(0);
                p = p->left;
            }
            else {
                if (p->right == NULL)
                    p->right = makeNode(0);
                p = p->right;
            }
        }
        p->alpha = table[i].alpha;
    }
    return root;
}

void preOrder(TreeNode* root) {
    if (root != NULL) {
        if(root->alpha != '0')
            printf("[%c] ", root->alpha);

        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(void) {
    TreeNode* root = makeMorseTree();
    preOrder(root);printf("\n");

    return 0;
}
