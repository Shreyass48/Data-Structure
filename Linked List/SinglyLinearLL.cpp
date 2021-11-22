/////////////////////////////////////////////////////////
// 
// Title : Implementation of Singly Linear Liked List.
// Author: Shreyas Kulkarni
// Date  : 17/11/21
// 
/////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

class SinglyLL
{
private:
    PNODE first;
    int size;

public:
    SinglyLL();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

SinglyLL::SinglyLL()
{
    first = NULL;
    size = 0;
}

void SinglyLL::InsertFirst(int no)
{
    
    PNODE newn = new NODE; 
    
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++; 
}
void SinglyLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = first;

    newn->data = no;
    newn->next = NULL;

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
    }
    size++;
}

void SinglyLL::InsertAtPos(int no, int iPos)
{
    int i = 0;
    if ((iPos < 1) || (iPos > size + 1))
    {
        cout << "invalid!\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->data = no;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    size++;
}

void SinglyLL::DeleteFirst()
{
    PNODE temp = first;
    if (first != NULL)
    {
        first = first->next;
        delete temp;

        size--;
    }
}

void SinglyLL::DeleteLast()
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
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

        size--;
    }
}

void SinglyLL::DeleteAtPos(int iPos)
{
    PNODE temp = first;
    PNODE target = NULL;
    int i = 0;

    if ((iPos < 1) || (iPos > size))
    {
        cout << "invalid!\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == size)
    {
        DeleteLast();
    }
    else
    {
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        size--;
    }
}

void SinglyLL::Display()
{
    PNODE temp = first;
    while (temp != NULL)
    {
        cout << "|" <<temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "\n";
}

int SinglyLL::Count()
{
    return size;
}

int main()
{
    int iRet = 0, iChoice = 1, val = 0, pos = 0;

    SinglyLL obj;

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