/////////////////////////////////////////////////////////
// 
// Title : Implementation of Doubly Linear Liked List.
// Author: Shreyas Kulkarni
// Date  : 17/11/21
// 
/////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
     while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; 

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        newn->next->prev = newn;
        // (*Head)->prev = newn;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; 

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
        
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;

        // while (temp->next != NULL)
        // {
        //     temp = temp->next;
        // }
        // temp->prev->next = NULL;
        // free(temp);
        
        
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int size = 0, i = 0;
    PNODE temp = *Head;

    size = Count(*Head);

    if((iPos < 1) || (iPos > size))   // Filter
    {
        printf("Invalid");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
        
    }
}

void InsertAtPos(PPNODE Head, int no, int iPos)
{
    int size = 0, i = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;

    size = Count(*Head);

    if((iPos < 1) || (iPos > size + 1))   // Filter
    {
        printf("Invalid");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,no);
    }
    else if(iPos == size+1)
    {
        InsertLast(Head,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
    }
}

int main()
{
    PNODE first = NULL;
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
            InsertFirst(&first,val);
            break;
        case 2:
            printf("enter data: ");
            scanf("%d",&val);
            InsertLast(&first,val);
            break;
        case 3:
            printf("enter data: ");
            scanf("%d",&val);
            printf("enter pos:");
            scanf("%d",&pos);
            InsertAtPos(&first,val,pos);
            break;

        case 4:
            DeleteFirst(&first);
            break;

        case 5:
            DeleteLast(&first);
            break;

        case 6:
            printf("enter pos: ");
            scanf("%d",&pos);
            DeleteAtPos(&first,pos);
            break;

        case 7:
            Display(first);
            break;

        case 8:
            iRet = Count(first);
            printf("number of nodes are : %d\n",iRet);
            break;

        case 0:
            printf("Application closed!\n");
            break;
        
        default:
            printf("Enter valid choice\n");
            break;
        }


    }
    return 0;
}
