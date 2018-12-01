struct Node;

typedef struct Node *ptr_to_node;

struct Node *init_common_list(int list_len);

void free_list(struct Node *head);

void print_list(struct Node *head);