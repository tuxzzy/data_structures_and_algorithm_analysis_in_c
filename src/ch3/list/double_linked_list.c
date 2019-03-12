#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType Element;
    Position pre;
    Position next;
};

static void FatalError(char *msg);

int IsEmpty(List L) {
    return L == NULL ? 1 : 0;
}

int IsLast(Position P, List L) {
    if (L == NULL || P == NULL) {
        FatalError("P or List is NULL");
    }
    
    return P->next == L ? 1 : 0;
}

Position Find(ElementType X, List L) {
    Position p = L;
    
    if (p == NULL) {
        return NULL;
    }
    
    if (p->Element == X) {
        return p;
    }
    
    for (p = p->next; p->Element != X && p != L; p = p->next)
        ;
    
    return p != L ? p : NULL;
}

List Delete(ElementType X, List L) {
    Position pre, next, head;
    Position del_node = Find(X, L);
    if (del_node == NULL) {
        FatalError("not exist element");
    }
    
    pre = del_node->pre;
    next = del_node->next;
    
    pre->next = next;
    next->pre = pre;
    
    if (del_node != L) { // 待删除节点不是表头
        head = L;
    } else if (del_node == del_node->next) { // 待删除节点是表头, 且待删除的节点是链表剩下的唯一节点
        head = NULL;
    } else { // 待删除节点是表头, 获取下一个节点作为新表头
        head = del_node->next;
    }
    
    free(del_node);
    
    return head;
}

Position FindPrevious(ElementType X, List L) {
    Position p = Find(X, L);
    if (p == NULL) {
        return NULL;
    }
    
    // X对应的节点是链表中的头节点, 定义其previous为NULL
    if (p == L) {
        return NULL;
    }
    
    return p->pre;
}

/**
 * @brief 把X插入到列表List的P节点之后
 * @param X
 * @param L
 * @param P
 * @return 新链表表头
 */
List Insert(ElementType X, List L, Position P) {
    Position n = malloc(sizeof(struct Node));
    if (n == NULL) {
        FatalError("out of memory");
    }
    
    n->Element = X;
    
    if (L == NULL) {
        n->pre = NULL;
        n->next = NULL;
        
        return n;
    }
    
    n->pre = P;
    n->next = P->next;
    
    P->next->pre = n;
    P->next = n;
    
    return L;
}

List InsertFirst(ElementType X, List L) {
    Position p = malloc(sizeof(struct Node));
    
    if (p == NULL) {
        FatalError("out of memory");
    }
    
    p->Element = X;
    
    if (L == NULL) {
        p->pre = p;
        p->next = p;
    } else {
        p->next = L;
        p->pre = L->pre;
        
        L->pre->next = p;
        L->pre = p;
    }

    return p;
}

void DeleteList(List L) {
    Position p, q;
    
    if (L == NULL) {
        return;
    }
    
    // 把表尾元素的next置为NULL, 充当哨兵
    L->pre->next = NULL;
    
    for (p = L; p != NULL; p = q) {
        q = p->next;
        
        free(p);
    }
}

Position First(List L) {
    if (L == NULL) {
        return NULL;
    }
    
    return L;
}

Position Advance(Position P) {
    if (P == NULL) {
        return NULL;
    }
    
    return P->next;
}

ElementType Retrieve(Position P) {
    if (P == NULL) {
        FatalError("Position is NULL");
    }
    
    return P->Element;
}

static void FatalError(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}