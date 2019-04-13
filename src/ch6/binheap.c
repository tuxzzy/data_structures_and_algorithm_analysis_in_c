#include "binheap.h"
#include <stdio.h>
#include <stdlib.h>

struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

static void FatalError(char *msg);
static void Error(char *msg);

PriorityQueue Initialize(int MaxElements) {
    PriorityQueue H = malloc(sizeof(struct HeapStruct));
    
    if (H == NULL) {
        FatalError("Out of memory");
    }

    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL) {
        FatalError("Out of memory");
    }
    
    H->Capacity = MaxElements;
    H->Size = 0;
    
    return H;
}

void Destroy(PriorityQueue H) {
    free(H->Elements);
    free(H);
}

void MakeEmpty(PriorityQueue H) {
    H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H) {
    int i;
    
    if (IsFull(H)) {
        Error("PriorityQueue is full");
        return;
    }
    
    H->Elements[++H->Size] = X;
    
    for (i = H->Size; i > 1 && H->Elements[i / 2] > X ; i /= 2) {
        H->Elements[i] = H->Elements[i / 2];
    }
    
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H) {
    ElementType min, last, smallest;
    int i = 0, swap_pos = 1;
    
    if (IsEmpty(H)) {
        Error("PriorityQueue is Empty");
        return -1;
    }
    
    min = H->Elements[1];
    last = H->Elements[H->Size];
    H->Size--;

    while (1) {
        i = swap_pos;
        smallest = last;
        
        if (i * 2 <= H->Size && H->Elements[i * 2] < smallest) {
            swap_pos = i * 2;
            smallest = H->Elements[i * 2];
        }
        
        if (i * 2 + 1 <= H->Size && H->Elements[i * 2 + 1] < smallest) {
            swap_pos = i * 2 + 1;
            smallest = H->Elements[i * 2 + 1];
        }
        
        if (swap_pos == i) {
            H->Elements[i] = smallest;
            break;
        }
        
        H->Elements[i] = H->Elements[swap_pos];
    }
    
    return min;
}

ElementType FindMin(PriorityQueue H) {
    if (H->Size == 0) {
        Error("PriorityQueue is empty");
        return -1;
    }
    
    return H->Elements[1];
}

int IsEmpty(PriorityQueue H) {
    return H->Size == 0;
}

int IsFull(PriorityQueue H) {
    return H->Size == H->Capacity;
}

static void FatalError(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static void Error(char *msg) {
    perror(msg);
}