#include "hash_sep.h"
#include <stdlib.h>
#include <math.h>

struct ListNode {
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl {
    int TableSize;
    List *TheLists;
};

static void FatalError(char* msg);
static int NextPrime(int val);
static void ClearSlot(HashTable ht, int slot);
static void RemoveSlotElements(Position P);
static int isPrime(int val);

HashTable InitializeTable(int TableSize) {
    int i;
    HashTable ht = malloc(sizeof(struct HashTbl));
    
    if (ht == NULL) {
        FatalError("InitializeTable Fail");
    }
    
    ht->TableSize = NextPrime(TableSize);
    ht->TheLists = malloc(ht->TableSize * sizeof(Position));
    
    if (ht->TheLists == NULL) {
        FatalError("InitializeTable Fail");
    }
    
    for (i = 0; i < ht->TableSize; i++) {
        ht->TheLists[i] = NULL;
    }
    
    return ht;
}

void DestroyTable(HashTable H) {
    int i;
    
    for (i = 0; i < H->TableSize; i++) {
        RemoveSlotElements(H->TheLists[i]);
    }
    
    free(H);
}

unsigned int Index(ElementType Key, int TableSize) {
    return Key % TableSize;
}

Position Find(ElementType Key, HashTable H) {
    Position p;
    unsigned int idx = Index(Key, H->TableSize);
    
    for (p = H->TheLists[idx]; p != NULL; p = p->Next) {
        if (p->Element == Key) {
            return p;
        }
    }
    
    return NULL;
}

void Insert(ElementType Key, HashTable H) {
    Position p, ele;
    unsigned int idx;
    
    p = Find(Key, H);
    if (p != NULL) {
        return;
    }
    
    ele = malloc(sizeof(struct ListNode));
    if (ele == NULL) {
        FatalError("Insert Error");
    }
    
    ele->Element = Key;
    
    idx = Index(Key, H->TableSize);
    ele->Next = H->TheLists[idx];
    H->TheLists[idx] = ele;
}

ElementType Retrieve(Position P) {
    return P->Element;
}

int Delete(ElementType Key, HashTable H) {
    unsigned int idx = Index(Key, H->TableSize);
    Position del;
    Position* ptr_to_del;
    
    for (del = H->TheLists[idx], ptr_to_del = &(H->TheLists[idx]); del != NULL; ptr_to_del = &(del->Next), del = del->Next) {
        if (del->Element == Key) {
            *ptr_to_del = del->Next;
            free(del);
            
            return 1;
        }
    }
    
    return 0;
}

void MakeEmpty(HashTable H) {
    int i;
    
    for (i = 0; i < H->TableSize; i++) {
        ClearSlot(H, i);
    }
}

static void ClearSlot(HashTable ht, int slot) {
    RemoveSlotElements(ht->TheLists[slot]);
    ht->TheLists[slot] = NULL;
}

static void RemoveSlotElements(Position P) {
    Position q;

    while (P != NULL) {
        q = P->Next;
        free(P);
        P = q;
    }
}

static int NextPrime(int val) {
    int i = val;
    
    while (!isPrime(i)) {
        i++;
    }
    
    return i;
}

static int isPrime(int val) {
    int i = val, j, sqrt_val = (int)sqrt(val);
    
    for (j = 2; j <= sqrt_val; j++) {
        if (val % j == 0) {
            return 0;
        }
    }
    
    return 1;
}

static void FatalError(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}