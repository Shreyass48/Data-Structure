/////////////////////////////////////////////////////////
//
// Title : Implementation of Doubly Linear Liked List.
// Author: Shreyas Kulkarni
// Date  : 18/11/21
//
/////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE, *PNODE;

class DoublyLinearLL
{
private:
    int size;
    PNODE first;

public:
    DoublyLinearLL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

DoublyLinearLL::DoublyLinearLL()
{
    size = 0;
    first = NULL;
}

void DoublyLinearLL::Display()
{
    PNODE temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int DoublyLinearLL::Count()
{
    return size;
}

void DoublyLinearLL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }
    size++;
}

void DoublyLinearLL::InsertLast(int no)
{
    PNODE temp = first;
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
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
    size++;
}

void DoublyLinearLL::InsertAtPos(int no, int ipos)
{
    PNODE temp = first;
    if ((ipos < 1) || (ipos > size + 1))
    {
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size++;
    }
}
void DoublyLinearLL ::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    size--;
}

void DoublyLinearLL::DeleteLast()
{
    PNODE temp = first;
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}

void DoublyLinearLL::DeleteAtPos(int ipos)
{
    PNODE temp = first;
    // PNODE targeted = first;
    if ((ipos < 1) || (ipos > size))
    {
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        size--;
    }
}

int main()
{
    DoublyLinearLL obj;
    int iRet = 0, iChoice = 1, val = 0, pos = 0;

    while (iChoice != 0)
    {
        cout << "_________________________________\n";
        cout << "1. Insert at First\n";
        cout << "2. Insert at Last\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at First\n";
        cout << "5. Delete at Last\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Count\n";
        cout << "_________________________________\n";
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            cout << "Enter Element :";
            cin >> val;
            obj.InsertFirst(val);
            break;
        case 2:
            cout << "Enter Element :";
            cin >> val;
            obj.InsertLast(val);
            break;
        case 3:
            cout << "Enter Element :";
            cin >> val;
            cout << "Enter position :";
            cin >> pos;
            obj.InsertAtPos(val, pos);
            break;

        case 4:
            obj.DeleteFirst();
            break;

        case 5:
            obj.DeleteLast();
            break;

        case 6:
            cout << "Enter position :";
            cin >> pos;
            obj.DeleteAtPos(pos);
            break;

        case 7:
            obj.Display();
            break;

        case 8:
            iRet = obj.Count();
            cout << "Elements in LL:" << iRet << "\n";
            break;

        case 0:
            cout << "Application Closed!\n";
            break;

        default:
            cout << "Enter valid choice\n";
            break;
        }
    }


    return 0;
}