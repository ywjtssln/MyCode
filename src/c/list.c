#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List l);
List IsEmpty(List l);
List IsLast(Postion p, List l);
Postion Find(DataType x, List l);
void Delete(DataType x, List l);
void Insert(DataType x, List l, Postion p);
void DeleteList(List l);



#endif
