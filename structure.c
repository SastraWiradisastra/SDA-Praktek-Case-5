#include "structure.h"

elmtAddress allocate(string nama) {
    elmtAddress newNode = (elmtAddress)malloc(sizeof(Elmt));
    if (newNode != NULL) {
        newNode->nama = strdup(nama);
        newNode->next = NULL;
    }
    return newNode;
}

void createList(List* list) {
    list->front = NULL;
}

void deallocate(elmtAddress node) {
    if (node != NULL) {
        free((void*)node->nama);
        free(node);
    }
}

void deleteList(List* list) {
    elmtAddress current = list->front;
    while (current != NULL) {
        elmtAddress next = current->next;
        deallocate(current);
        current = next;
    }
    list->front = NULL;
}

bool listEmpty(List list) {
    return list.front == NULL;
}

int getTotalElmt(List list) {
    int count = 0;
    elmtAddress current = list.front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printElmt(elmtAddress node) {
    if (node != NULL)
        printf("- %s\n", node->nama);
}

void printList(List list) {
    elmtAddress current = list.front;
    if (current == NULL) {
        printf("List kosong!\n");
        return;
    }
    while (current != NULL) {
        printElmt(current);
        current = current->next;
    }
}

elmtAddress searchList(List list, string query) {
    elmtAddress current = list.front;
    while (current != NULL) {
        if (strcasecmp(current->nama, query) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void insFront(List* list, elmtAddress node) {
    node->next = list->front;
    list->front = node;
}

void insRear(List* list, elmtAddress node) {
    if (list->front == NULL) {
        list->front = node;
    } else {
        elmtAddress current = list->front;
        while (current->next != NULL)
            current = current->next;
        current->next = node;
    }
    node->next = NULL;
}

void insManual(List* list, elmtAddress node, unsigned int position) {
    if (position == 1) {
        insFront(list, node);
        return;
    }
    elmtAddress current = list->front;
    for (int i = 1; i < position - 1 && current != NULL; i++)
        current = current->next;
    if (current == NULL) {
        insRear(list, node);
        return;
    }
    node->next = current->next;
    current->next = node;
}

void delFront(List* list) {
    if (list->front == NULL) return;
    elmtAddress temp = list->front;
    list->front = list->front->next;
    deallocate(temp);
}

void delRear(List* list) {
    if (list->front == NULL) return;
    elmtAddress current = list->front;
    elmtAddress prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
        list->front = NULL;
    else
        prev->next = NULL;
    deallocate(current);
}

void delManual(List* list, unsigned int position) {
    if (position < 1) return;
    if (position == 1) {
        delFront(list);
        return;
    }
    elmtAddress current = list->front;
    elmtAddress prev = NULL;
    for (int i = 1; current != NULL && i < position; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;
    prev->next = current->next;
    deallocate(current);
}
