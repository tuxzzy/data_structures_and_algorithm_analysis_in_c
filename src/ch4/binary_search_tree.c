#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

static Position init_node(ElementType X);
static void InOrderWalk0(SearchTree T, void (*f)(ElementType X));

SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    
    return NULL;
}

Position Find(ElementType X, SearchTree T) {
    Position p = T;
    
    while (p != NULL) {
        if (X == p->Element) {
            return p;
        }
        
        p = X < p->Element ? p->Left : p->Right;
    }
    
    return NULL;
}

Position FindMin(SearchTree T) {
    Position p = T;
    
    if (p == NULL) {
        return NULL;
    }
    
    for (; p->Left != NULL; p = p->Left)
        ;
        
    return p;
}

Position FindMax(SearchTree T) {
    Position p = T;
    
    if (p == NULL) {
        return NULL;
    }
    
    for (; p->Right != NULL; p = p->Right)
        ;
        
    return p;
}

SearchTree Insert(ElementType X, SearchTree T) {
    Position n = T;
    
    if (n == NULL) {
        return init_node(X);
    }
    
    while (1) {
        if (X == n->Element) {
            break;
        }
        
        if (X < n->Element) {
            if (n->Left == NULL) {
                n->Left = init_node(X);
                break;
            } else {
                n = n->Left;
                continue;
            }
        }
        
        if (X > n->Element) {
            if (n->Right == NULL) {
                n->Right = init_node(X);
                break;
            } else {
                n = n->Right;
                continue;
            }
        }
    }
    
    return T;
}

static Position init_node(ElementType X) {
    Position node = malloc(sizeof(struct TreeNode));
    
    if (node == NULL) {
        perror("Out of Memory");
        exit(EXIT_FAILURE);
    }
    
    node->Element = X;
    node->Left = NULL;
    node->Right = NULL;
    
    return node;
}

SearchTree Delete(ElementType X, SearchTree T) {
    Position p = T, del_node;
    Position *ptr_p = &p;
    Position min_node_of_right_sub_tree;
    int del_root;
    
    while (p != NULL) {
        if (X == p->Element) {
            break;
        }
        
        ptr_p = X < p->Element ? &(p->Left) : &(p->Right);
        p = X < p->Element ? p->Left : p->Right;
    }
    
    if (p == NULL) {
        fprintf(stderr, "%s: %d", "Delete element not exist", X);
        exit(EXIT_FAILURE);
    }
    
    del_root = p == T ? 1 : 0;
    
    if (p->Left == NULL) {
        del_node = p;
        *ptr_p = p->Right;
        free(del_node);
        
        return del_root ? *ptr_p : T;
    }
    
    if (p->Right == NULL) {
        del_node = p;
        *ptr_p = p->Left;
        free(del_node);
        
        return del_root ? *ptr_p : T;
    }
    
    // has two children
    min_node_of_right_sub_tree = FindMin(p->Right);
    p->Element = min_node_of_right_sub_tree->Element;
    p->Right = Delete(min_node_of_right_sub_tree->Element, p->Right);
    
    return T;
}

ElementType Retrieve(Position P) {
    if (P == NULL) {
        fprintf(stderr, "%s", "No element exist");
        exit(EXIT_FAILURE);
    }
    
    return P->Element;
}

void InOrderWalk(SearchTree T, void (*f)(ElementType X)) {
    if (T == NULL) {
        printf("empty tree\n");
        return;
    }
    
    InOrderWalk0(T, f);
}

static void InOrderWalk0(SearchTree T, void (*f)(ElementType X)) {
    if (T == NULL) {
        return;
    }
    
    InOrderWalk0(T->Left, f);
    f(T->Element);
    InOrderWalk0(T->Right, f);
}