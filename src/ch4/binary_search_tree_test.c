#include "tree.h"
#include <stdio.h>

static void print_element(ElementType X);

int main(void) {
    int elements[] = { 4, 2, 5, 1, 3, 6 };
    int size = 6, i;
    SearchTree root = NULL;
    
    for (i = 0; i < size; i++) {
        root = Insert(elements[i], root);
    }
    
    InOrderWalk(root, print_element);
    printf("\n");
    
    root = Delete(5, root);
    InOrderWalk(root, print_element);
    printf("\n");
    
    root = Delete(2, root);
    InOrderWalk(root, print_element);
    printf("\n");
    
    while (root != NULL) {
        printf("Delete root: %d\n", Retrieve(root));
        root = Delete(Retrieve(root), root);
        InOrderWalk(root, print_element);
        printf("\n");
    }

    return 0;
}

static void print_element(ElementType X) {
    printf("%d ", X);
}