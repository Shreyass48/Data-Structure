/////////////////////////////////////////////////////////
// 
// Title : Implementation of Singly Circular Liked List.
// Author: Shreyas Kulkarni
// Date  : 17/11/21
// 
/////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int Data;
    struct node *Next;
} NODE, *PNODE, **PPNODE;

void Display(PNODE Head, PNODE Tail)
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }

    do
    {
        printf("|%d| -> ", Head->Data);
        Head = Head->Next;
    } while (Tail->Next != Head);
    printf("NULL\n");
}
int Count(PNODE Head, PNODE Tail)
{
    int Cnt = 0;
    do
    {
        Cnt++;
        Head = Head->Next;
    } while (Tail->Next != Head);
    return Cnt;
}
void InsertFirst(PPNODE Head, PPNODE Tail, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->Next = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->Next = *Head;
        *Head = newn;
    }
    (*Tail)->Next = *Head;
}
void InsertLast(PPNODE Head, PPNODE Tail, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->Next = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->Next = newn;
        *Tail = newn;
    }
    (*Tail)->Next = *Head;
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int no, int pos)
{
    PNODE temp = *Head;
    int i = 0;

    int size = Count(*Head, *Tail);

    if ((pos < 1) || (pos > size + 1))
    {
        return;
    }

    if (pos == 1)
    {
        InsertFirst(Head, Tail, no);
    }
    else if (pos == size + 1)
    {
        InsertLast(Head, Tail, no);
    }
    else
    {
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = no;
        newn->Next = NULL;

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;
    }
}
void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if ((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if (*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->Next;
        free((*Tail)->Next);
        (*Tail)->Next = *Head;
        (*Tail)->Next = *Head;
    }
    
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;
    if ((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if (*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        while (temp->Next != *Tail)
        {
            temp = temp->Next;
        }
        free(temp->Next);
        temp->Next = *Head;
        *Tail = temp;
        (*Tail)->Next = *Head;
    }
    
}
void DeleteAtPos(PPNODE Head, PPNODE Tail, int pos)
{
    PNODE temp = *Head;
    PNODE target = NULL;
    int i = 0;

    int size = Count(*Head, *Tail);

    if ((pos < 1) || (pos > size))
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    else if (pos == size)
    {
        DeleteLast(Head, Tail);
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->Next;
        }
        target = temp->Next;
        temp->Next = target->Next;
        free(target);
    }
}

int main()
{
    PNODE first = NULL;
    PNODE last = NULL;

    int iRet = 0, iChoice = 1, val = 0, pos = 0;

    while(iChoice != 0)
    {
        printf("________________________\n");
        printf("Enter your choice :\n");
        printf("1: Insert at first\n");
        printf("2: Insert at last\n");
        printf("3: Insert at pos\n");
        printf("4: Delete first\n");
        printf("5: Delete last\n");
        printf("6: Delete at pos\n");
        printf("7: Display\n");
        printf("8: count node\n");
        printf("0: Terminate app\n");
        printf("________________________\n");
        scanf("%d",&iChoice);

        switch (iChoice)
        {
        case 1:
            printf("enter data: ");
            scanf("%d",&val);
            InsertFirst(&first,&last,val);
            break;
        case 2:
            printf("enter data: ");
            scanf("%d",&val);
            InsertLast(&first,&last,val);
            break;
        case 3:
            printf("enter data: ");
            scanf("%d",&val);
            printf("enter pos:");
            scanf("%d",&pos);
            InsertAtPos(&first,&last,val,pos);
            break;

        case 4:
            DeleteFirst(&first,&last);
            break;

        case 5:
            DeleteLast(&first,&last);
            break;

        case 6:
            printf("enter pos: ");
            scanf("%d",&pos);
            DeleteAtPos(&first,&last,pos);
            break;

        case 7:
            Display(first,last);
            break;

        case 8:
            iRet = Count(first,last);
            printf("number of nodes are : %d\n",iRet);
            break;

        case 0:
            printf("Application closed!\n");
            break;
        
        default:
        printf("Enter valiod chice");
            break;
        }


    }

    return 0;
}