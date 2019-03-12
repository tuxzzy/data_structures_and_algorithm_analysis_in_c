#ifndef _List_H
#define _List_H

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
List Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
List Insert(ElementType X, List L, Position P);
List InsertFirst(ElementType X, List L);
void DeleteList(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif