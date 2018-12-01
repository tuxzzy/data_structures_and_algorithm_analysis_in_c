#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.c"

struct Node *init_common_list(int list_len) {
    int i;
    struct Node *head = malloc(sizeof (struct Node)), *n, *p = head;
    head->next = NULL;
    
    for (i = 1; i <= list_len; i++) {
        n = malloc(sizeof (struct Node));
        if (n == NULL) {
            perror("malloc Node error");
            exit(EXIT_FAILURE);
        }
        
        n->val = i;
        n->next = NULL;
        
        p->next = n;
        
        p = n;
    }
    
    return head;
}

void print_list(struct Node *head) {
    struct Node *p;
    
    for (p = head->next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
}

void free_list(struct Node *head) {
    struct Node *p = head, *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        
        free(q);
    }
}

ptr_to_node find(ptr_to_node head, int index) {
    int i;
    ptr_to_node p;
    
    for (i = 0, p = head->next; p != NULL; i++, p = p->next) {
        if (i == index) {
            return p;
        }
    }
    
    return NULL;
}

void swap_adjacent(ptr_to_node head, ptr_to_node p1, ptr_to_node p2) {
    ptr_to_node *p = &head->next;
    
    if (p1 == NULL || p2 == NULL) {
        perror("p1 or p2 is NULL");
        exit(EXIT_FAILURE);
    }
    
    p1->next = p2->next;
    p2->next = p1;
    
    for (; *p != NULL && *p != p1; p = &(*p)->next)
        ;
        
    if (*p == NULL) {
        perror("p is NULL");
        exit(EXIT_FAILURE);
    }
    
    *p = p2;
}