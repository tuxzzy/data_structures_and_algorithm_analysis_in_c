#include <stdlib.h>
#include <stdio.h>
#include "leftheap.h"

struct TreeNode {
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

static PriorityQueue Merge0(PriorityQueue H1, PriorityQueue H2);
static int Npl(PriorityQueue H);
static void SwapChildren(PriorityQueue H);
static void PrintQueue0(PriorityQueue H);
static void FatalError(char *msg);

PriorityQueue Initialize(void) {
    return NULL;
}

ElementType FindMin(PriorityQueue H) {
    return H->Element;
}

int IsEmpty(PriorityQueue H) {
    return !!(H == NULL);
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
    if (H1 == NULL) {
        return H2;
    }
    
    if (H2 == NULL) {
        return H1;
    }
    
    if (H1->Element <= H2->Element) {
        return Merge0(H1, H2);
    }
    
    return Merge0(H2, H1);
}

PriorityQueue Merge0(PriorityQueue H1, PriorityQueue H2) {
    H1->Right = Merge(H1->Right, H2);
    
    if (Npl(H1->Left) < Npl(H1->Right)) {
        SwapChildren(H1);
    }
    
    H1->Npl = Npl(H1->Right) + 1;
}

static int Npl(PriorityQueue H) {
    if (H == NULL) {
        return -1;
    }
    
    return H->Npl;
}

static void SwapChildren(PriorityQueue H) {
    PriorityQueue tmp;
    
    if (H == NULL) {
        return;
    }
    
    tmp = H->Left;
    H->Left = H->Right;
    H->Right = tmp;
}

PriorityQueue Insert1(ElementType X, PriorityQueue H) {
    PriorityQueue n = malloc(sizeof(struct TreeNode));
    
    if (n == NULL) {
        FatalError("Out of Memory");
    }
    
    n->Element = X;
    n->Left = n->Right = NULL;
    n->Npl = 0;
    
    return Merge(n, H);
}

PriorityQueue DeleteMin1(PriorityQueue H) {
    PriorityQueue left, right;
    
    if (IsEmpty(H)) {
        return H;
    }
    
    left = H->Left;
    right = H->Right;
    
    free(H);
    
    return Merge(left, right);
}

void PrintQueue(PriorityQueue H) {
    if (H == NULL) {
        printf("%s", "PriorityQueue is empty");
        return;
    }
    
    PrintQueue0(H);
}

static void PrintQueue0(PriorityQueue H) {
    int left, right;
    
    left = H->Left != NULL ? H->Left->Element : -1;
    right = H->Right != NULL ? H->Right->Element : -1;
    
    printf("val: %d; npl: %d; left: %d; right: %d\n", H->Element, H->Npl, left, right);
    
    if (H->Left != NULL) {
        PrintQueue(H->Left);
    }
    
    if (H->Right != NULL) {
        PrintQueue(H->Right);
    }
}

static void FatalError(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}