/////////////////////////////////////////////////////////
// 
// Title : Implementation of Singly Circular Liked List.
// Author: Shreyas Kulkarni
// Date  : 17/11/21
// 
/////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next;
} NODE, *PNODE;

class SinglyCircularLL
{
private:
    PNODE first;
    PNODE last;
    int size;

public:
    SinglyCircularLL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int ,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

SinglyCircularLL::SinglyCircularLL()
{
    first = NULL;
    last = NULL;
    size = 0;
}

void SinglyCircularLL::Display()
{
    PNODE temp = first;
    do
    {
        cout << "|" << temp->Data << "| -> ";
        temp = temp->Next;
    } while (temp != last->Next);
    cout << "NULL\n";
}

int SinglyCircularLL::Count()
{
    return size;
}

void SinglyCircularLL::InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->Data = no;
    newn->Next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->Next = first;
        first = newn;
    }
    last->Next = first;
    size++;
}

void SinglyCircularLL::InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->Data = no;
    newn->Next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->Next = newn;
        last = newn;
    }
    last->Next = first;
    size++;
}

void SinglyCircularLL::InsertAtPos(int no, int pos)
{
    int i = 0;
    PNODE temp = first;
    if ((pos < 1) || (pos > size + 1))
    {
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->Data = no;
        newn->Next = NULL;

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;
    }
    size++;
}

void SinglyCircularLL::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->Next;
        delete last->Next;
        last->Next = first;
    }
    
    size--;
}

void SinglyCircularLL::DeleteLast()
{
    int i = 0;
    PNODE temp = first;
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while (temp->Next != last)
        {
            temp = temp->Next;
        }
        delete temp->Next;
        temp->Next = first;
        last->Next = first;
    }
    size--;
}

void SinglyCircularLL::DeleteAtPos(int pos)
{
    int i = 0;
    PNODE temp = first;
    PNODE target = NULL;
    if ((pos < 1) || (pos > size))
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == size)
    {
        DeleteLast();
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->Next;
        }
        target = temp->Next;
        temp->Next = target->Next;
        delete target;
    }
    size--;
}

int main()
{
    int iRet = 0, iChoice = 1, val = 0, pos = 0;
    SinglyCircularLL obj;

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
