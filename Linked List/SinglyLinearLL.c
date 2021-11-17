#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE, * PNODE, ** PPNODE;

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int i = 0;
    while (Head != NULL)
    {
       i++;
       Head = Head->next;
    }
    return i;

}

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }

}
void InsertLast(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head != NULL)
    {
        *Head = (*Head)->next;
        free(temp);

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
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    

}


void InsertAtPos(PPNODE Head, int no, int iPos)
{
    int i = 0, size = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;

    size = Count(*Head);

    if((iPos < 1) || (iPos > size + 1))
    {
        printf("Invalid!");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,no);
    }
    else if(iPos == size + 1)
    {
        InsertLast(Head,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }

}

void DeleteAtPos(PPNODE Head, int iPos)
{
    PNODE temp = *Head;
    PNODE target = NULL;
    int i = 0, size = 0;

    size = Count(*Head);

    if((iPos < 1) || (iPos > size))
    {
        printf("Invalid!!");
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
        target = temp->next;
        temp->next = target->next;
        free(target);

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
        printf("Enter valiod chice");
            break;
        }


    }

    return 0;
}
