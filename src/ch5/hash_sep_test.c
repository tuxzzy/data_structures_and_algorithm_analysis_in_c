#include "hash_sep.h"
#include <stdio.h>

static void TestInsert(HashTable ht);
static void TestFind(HashTable ht);
static void TestDelete(HashTable ht);
static void TestDeleteAll(HashTable ht);
static void TestMakeEmpty(HashTable ht);

int main(void) {
    
    HashTable ht = InitializeTable(20);
    TestInsert(ht);
    TestFind(ht);
    
    printf("\n\n");
    TestDelete(ht);
    
    TestDeleteAll(ht);
    
    TestMakeEmpty(ht);
    
    return 0;
}

static void TestInsert(HashTable ht) {
    int i;
    
    for (i = 0; i < 100; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        
        Insert(i, ht);
    }
}

static void TestFind(HashTable ht) {
    int i;
    Position p;
    for (i = 0; i < 100; i++) {
        p = Find(i, ht);
        if (p != NULL) {
            printf("find: %d\n", Retrieve(p));
        }
    }
}

static void TestDelete(HashTable ht) {
    int i;
    Position p;
    for (i = 0; i < 100; i++) {
        if (i % 7 == 0) {
            Delete(i, ht);
        }
    }
    
    for (i = 0; i < 100; i++) {
        p = Find(i, ht);
        if (p != NULL) {
            printf("find: %d\n", Retrieve(p));
        }
    }
}

static void TestDeleteAll(HashTable ht) {
    int i, is_empty = 1;
    Position p;
    
    for (i = 0; i < 200; i++) {
        Delete(i, ht);
    }
    
    for (i = 0; i < 200; i++) {
        p = Find(i, ht);
        if (p != NULL) {
            is_empty = 0;
            break;
        }
    }
    
    if (is_empty) {
        printf("%s", "ht is empty!");
    } else {
        printf("%s", "ht is not empty!!!!!!");
    }
}

static void TestMakeEmpty(HashTable ht) {
    int i;
    Position p;
    for (i = 0; i < 100; i++) {
        Insert(i, ht);
    }
    
    MakeEmpty(ht);
    
    for (i = 0; i < 200; i++) {
        p = Find(i, ht);
        if (p != NULL) {
            printf("%s", "Make Empty Error");
            return;
        }
    }
    
    printf("%s", "Make Empty Ok!");
}

