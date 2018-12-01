#include <stdio.h>
#include "list.h"
#include "node.c"

int main(void) {
    int vs1[] = { 1, 3, 5, 7, 9 };
    int vs2[] = { 1, 5, 6, 9, 10 };
    ptr_to_node list1 = init_list(vs1, 5);
    ptr_to_node list2 = init_list(vs2, 5);
    ptr_to_node list;
    
    list = intersect_sorted_list(list1, list2);
    
    print_list(list);
    
    free_list(list);
    
    return 0;
}