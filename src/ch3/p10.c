#include <stdlib.h>
#include <stdio.h>
#include "doubly_node.c"

typedef struct Node *ptr_to_node;

ptr_to_node init_doubly_list(int n);
void remove_node(ptr_to_node ptn);
int josephus(int m, int n, ptr_to_node list);

int main(void) {
    int result, m, n;
    scanf("%d %d", &m, &n);
    ptr_to_node ptn = init_doubly_list(n);
    result = josephus(m, n, ptn);
    
    printf("\nresult: %d", result);
    
    return 0;
}

ptr_to_node init_doubly_list(int n) {
    int i;
    ptr_to_node p, pre = NULL, head;
    
    if (n == 0) {
        return NULL;
    }
    
    head = malloc(sizeof(struct Node));
    if (head == NULL) {
        perror("error");
        exit(EXIT_FAILURE);
    }
    
    head->val = 1;
    head->pre = NULL;
    head->next = NULL;
    
    pre = head;
    
    for (i = 2; i <= n; i++) {
        p = malloc(sizeof(struct Node));
        if (p == NULL) {
            perror("error");
            exit(EXIT_FAILURE);
        }
        p->val = i;
        p->pre = pre;
        p->next = NULL;
        
        pre->next = p;
        
        pre = p;
    }
    
    pre->next = head;
    head->pre = pre;
    
    return head;
}

int josephus(int m, int n, ptr_to_node list) {
    int cnt;
    ptr_to_node p = list, mv;
    
    if (m == 0) {
        return n;
    }
    
    while (n > 1) {
        for (cnt = 0; cnt != m; cnt++) {
            p = p->next;
        }
        
        mv = p;
        p = p->next;
        
        remove_node(mv);
        
        n--;
    }
    
    return p->val;
}

void remove_node(ptr_to_node ptn) {
    ptn->pre->next = ptn->next;
    ptn->next->pre = ptn->pre;
    
    printf("%d ", ptn->val);
    
    free(ptn);
}