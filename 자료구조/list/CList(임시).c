#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {
    element data;
    struct Node* next;
} Node;

typedef struct {
    Node* tail;
    int size;
} ListType;

Node* makeNode(element e) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

void init(ListType* L) {
    L->tail = NULL;
    L->size = 0;
}

int isEmpty(ListType* L) {
    return L->size == 0;
}


void insert(ListType* L, element e, int pos) {
    if (pos <= 0 || pos > L->size + 1) {
        printf("Invalid Position.\n");
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

element delete(ListType* L, int pos) {
    if (isEmpty(L)) {
        printf("Empty!\n");
        return 0;
    }

    if (pos <= 0 || pos > L->size) {
        printf("Invalid Position.\n");
        return 0;
    }

    Node* p = L->head;

    if (pos == 1) {
        element data = p->data;
        L->head = p->next;
        free(p);
        L->size--;
        return data;
    }

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

void insertFirst(ListType* L, element e) {
    Node* node = makeNode(e);

    if (isEmpty(L)) {
        L->tail = node;
        L->tail->next = node;
    }
    else {
        node->next = L->tail->next;
        L->tail->next = node;
    }
    L->size++;
}

void insertLast(ListType* L, element e) {
    Node* node = makeNode(e);

    if (isEmpty(L)) {
        L->tail = node;
        L->tail->next = node;
    }
    else {
        node->next = L->tail->next;
        L->tail->next = node;
        L->tail = node;
    }
    L->size++;
}

void print(ListType* L) {
    for (Node* p = L->head; p != NULL; p = p->next) {
        printf("[%c]", p->data);
        if (p->next != NULL)
            printf("->");
    }
    printf("\n");
}

int main(void) {
    ListType L;
    init(&L);

    insertFirst(&L, 'A');
    insert(&L, 'B', 2);
    insert(&L, 'C', 3);

    print(&L); // [A]->[B]->[C]

    delete(&L, 2);
    print(&L); // [A]->[C]

    return 0;
}

//delFirst
//delLast
//print 본인이 직접 하기
