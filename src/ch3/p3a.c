#include <stdio.h>
#include "list.h"
#include "node.c"

int main(void) {
    ptr_to_node list = init_common_list(10);
    ptr_to_node p1 = find(list, 3);
    ptr_to_node p2 = find(list, 4);
    
    swap_adjacent(list, p1, p2);
    
    print_list(list);
    
    free_list(list);
    
    return 0;
}