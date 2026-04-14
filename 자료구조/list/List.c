#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {
    element data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} ListType;

Node* makeNode(element e) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = e;
    node->next = NULL;
    return node;
}

void init(ListType* L) {
    L->head = NULL;
    L->size = 0;
}

int isEmpty(ListType* L) {
    return L->size == 0;
}

void insertFirst(ListType* L, element e) {
    Node* node = makeNode(e);
    node->next = L->head;
    L->head = node;
    L->size++;
}

element deleteFirst(ListType* L) {
    if (isEmpty(L)) {
        printf("Empty\n");
        return '\0';
    }

    Node* p = L->head;
    element data = p->data;

    L->head = p->next;
    free(p);
    L->size--;

    return data;
}

void insert(ListType* L, element e, int pos) {
    if (pos <= 0 || pos > L->size + 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertFirst(L, e);
        return;
    }

    Node* p = L->head;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }

    Node* node = makeNode(e);
    node->next = p->next;
    p->next = node;

    L->size++;
}

element deletePosition(ListType* L, int pos) {
    if (isEmpty(L)) {
        printf("Empty\n");
        return '\0';
    }

    if (pos <= 0 || pos > L->size) {
        printf("Invalid Position\n");
        return '\0';
    }

    if (pos == 1) {
        return deleteFirst(L);
    }

    Node* p = L->head;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }

    Node* temp = p->next;
    element data = temp->data;

    p->next = temp->next;
    free(temp);
    L->size--;

    return data;
}

void print(ListType* L) {
    Node* p = L->head;

    while (p != NULL) {
        printf("[%c]", p->data);
        if (p->next != NULL)
            printf("->");
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    ListType L;
    init(&L);

    insertFirst(&L, 'A');
    insertFirst(&L, 'B');
    insertFirst(&L, 'C');
    insertFirst(&L, 'D');

    insert(&L, 'I', 4);
    insert(&L, 'K', 3);

    print(&L);

    printf("Del : [%c]\n", deleteFirst(&L));
    print(&L);

    printf("Del : [%c]\n", deletePosition(&L, 2));
    print(&L);

    return 0;
}
