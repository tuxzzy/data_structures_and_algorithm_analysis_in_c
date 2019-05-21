#ifndef _LeftHeap_H
#define _LeftHeap_H

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H));
#define DeleteMin(H) (H = DeleteMin1(H));

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

void PrintQueue(PriorityQueue H);

#endif