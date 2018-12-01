#include <stdio.h>
#include "list.h"

int main(void) {
    ptr_to_node head = init_common_list(10);
    
    print_list(head);
    
    free_list(head);
    
    return 0;
}

