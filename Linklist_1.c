#include<stdio.h>
struct node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
List MakeEmpty(List L);
List CreateLinklist();
int Retrieve(Position P);
Position Advance(Position P);
struct Node
{
    int Data;
    Position Next;
};

int main()
{


    return 0;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(int X, List L)
{
    Position P;

    P = L-> Next;
    while(P != NULL && P->Data != X)
    {
        P = P->Next;
    }
    return P;
}

void Delete(int X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);
    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(int X, List L)
{
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->Data != X)
    {
        P = P->Next;
    }
    return P;
}

void Insert(int X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));

    if(TmpCell == NULL){
        printf("Out of space!!!\n");
    }

    TmpCell->Data = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while(P != NULL){
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

List MakeEmpty(List L)
{
    Position P = L->Next;
    Position TmpCell;
    while(P != NULL)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
    return L;
}

List CreateLinklist()
{
    Position Head;
    Head = malloc(sizeof(struct Node));
    if(Head != NULL){
        Head->Next = NULL;
    }
    return Head;
}

int Retrieve(Position P)
{
    return P->Data;
}

Position Advance(Position P)
{
    return P->Next;
}