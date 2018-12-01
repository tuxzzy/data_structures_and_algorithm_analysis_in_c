struct Node;

typedef struct Node *ptr_to_node;

struct Node *init_common_list(int list_len);

void free_list(struct Node *head);

void print_list(struct Node *head);

ptr_to_node find(ptr_to_node head, int index);

void swap_adjacent(ptr_to_node head, ptr_to_node p1, ptr_to_node p2);