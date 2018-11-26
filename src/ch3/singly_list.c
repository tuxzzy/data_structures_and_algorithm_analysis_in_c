#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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