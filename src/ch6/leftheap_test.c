#include "leftheap.h"
#include <stdio.h>

static PriorityQueue initQueue1(void);
static PriorityQueue initQueue2(void);

int main(void) {
   
    PriorityQueue H1 = initQueue1();
    PriorityQueue H2 = initQueue2();
    PriorityQueue H = Merge(H1, H2);
    
    PrintQueue(H);
    
    return 0;
}

static PriorityQueue initQueue1() {
    PriorityQueue H1 = Initialize();
    PriorityQueue H2 = Initialize();
    PriorityQueue H3 = Initialize();
    
    H1 = Insert1(17, H1);
    H1 = Insert1(26, H1);
    H1 = Insert1(8, H1);
    
    H2 = Insert1(14, H2);
    H2 = Insert1(23, H2);
    
    H3 = Insert1(10, H3);
    H3 = Insert1(21, H3);
    
    H2 = Merge(H2, H3);
    H2 = Insert1(3, H2);
    
    return Merge(H1, H2);
}

static PriorityQueue initQueue2() {
    PriorityQueue H1 = Initialize();
    PriorityQueue H2 = Initialize();
    PriorityQueue H3 = Initialize();
    
    H1 = Insert1(7, H1);
    H1 = Insert1(37, H1);
    H1 = Insert1(18, H1);
    
    H2 = Insert1(24, H2);
    H2 = Insert1(33, H2);
    
    H3 = Insert1(18, H3);
    H3 = Insert1(12, H3);
    
    H2 = Merge(H2, H3);
    H2 = Insert1(6, H2);
    
    return Merge(H1, H2);
}