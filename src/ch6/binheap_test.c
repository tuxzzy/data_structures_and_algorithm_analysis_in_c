#include "binheap.h"
#include <stdio.h>

int main(void) {
    int i, val;
    PriorityQueue H = Initialize(10);
    
    for (i = 10; i > 0; i--) {
        Insert(i, H);
    }
    
    while (!IsEmpty(H)) {
        val = DeleteMin(H);
        printf("%d ", val);
    }
    
    for (i = 4; i > 0; i--) {
        Insert(i, H);
    }
    
    printf("\nFindMin: %d\n", FindMin(H));
    MakeEmpty(H);
    printf("FindMin: %d\n", FindMin(H));
    
    return 0;
}