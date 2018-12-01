#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.c"

ptr_to_node init_lots(int* lots, int size);
void print_lots(ptr_to_node list, ptr_to_node p);

int main(void) {
    int ints[] = {1, 4, 5, 8, 10};
    ptr_to_node list = init_common_list(10);
    ptr_to_node lots = init_lots(ints, 5);
    
    print_lots(list, lots);
    
    free_list(list);
    free_list(lots);
    
    return 0;
}

ptr_to_node init_lots(int* lots, int size) {
    ptr_to_node head = malloc(sizeof (struct Node)), p = head;
    int i;
    
    head->next = NULL;
    for (i = 0; i < size; i++) {
        p->next = malloc(sizeof (struct Node));
        p = p->next;
        p->val = lots[i];
        p->next = NULL;
    }
    
    return head;
}

void print_lots(ptr_to_node list, ptr_to_node p) {
    int idx = 0;
    for (p = p->next; p != NULL; p = p->next) {
        for (list = list->next; list != NULL; list = list->next) {
            if (++idx == p->val) {
                printf("%d ", list->val);
                break;
            }
        }
    }
}