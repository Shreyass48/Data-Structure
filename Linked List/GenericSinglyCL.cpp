/////////////////////////////////////////////////////////
//
// Title : Implementation of Singly Circular Liked List.
// Type  : Generic Programming
// Author: Shreyas Kulkarni
// Date  : 17/11/21
//
/////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T Data;
    struct node *Next;
};

template <class T>
class SinglyCircularLL
{
private:
    node<T>* first;
    node<T>* last;
    int size;

public:
    SinglyCircularLL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCircularLL<T>::SinglyCircularLL()
{
    first = NULL;
    last = NULL;
    size = 0;
}

template <class T>
void SinglyCircularLL<T>::Display()
{
    node<T> *temp = first;
    if((first == NULL) && (last == NULL))
    {
        return;
    }

    do
    {
        cout << "|" << temp->Data << "| -> ";
        temp = temp->Next;
    } while (temp != last->Next);
    cout << "NULL\n";
}

template <class T>
int SinglyCircularLL<T>::Count()
{
    return size;
}

template <class T>
void SinglyCircularLL<T>::InsertFirst(T no)
{
    node<T> *newn = new node<T>;

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

template <class T>
void SinglyCircularLL<T>::InsertLast(T no)
{
    node<T> *newn = new node<T>;

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

template <class T>
void SinglyCircularLL<T>::InsertAtPos(T no, int iPos)
    {
        node<T>* temp = first;
        if((iPos < 1) || (iPos > size + 1))
        {
            cout<<"Invalid!\n";
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            node<T>* newn = new node<T>;

            newn->Data = no;
            newn->Next = NULL;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp->Next;
            }
            newn->Next = temp->Next;
            temp->Next = newn;
            size++;
        }
        
    }


template <class T>
void SinglyCircularLL<T>::DeleteFirst()
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

template <class T>
void SinglyCircularLL<T>::DeleteLast()
{
    int i = 0;
    node<T> *temp = first;
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
        delete last;
        last = temp;
        last->Next = first;
    }

    size--;
}

template <class T>
void SinglyCircularLL<T>::DeleteAtPos(int pos)
{
    int i = 0;
    node<T> *temp = first;
    node<T> *target = NULL;
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
        size--;
    }
   
}

int main()
{
    // int iRet = 0, iChoice = 1, val = 0, pos = 0;
    SinglyCircularLL<int> cobj;

    // while (iChoice != 0)
    // {
    //     cout << "_________________________________\n";
    //     cout << "1. Insert at First\n";
    //     cout << "2. Insert at Last\n";
    //     cout << "3. Insert at Position\n";
    //     cout << "4. Delete at First\n";
    //     cout << "5. Delete at Last\n";
    //     cout << "6. Delete at Position\n";
    //     cout << "7. Display\n";
    //     cout << "8. Count\n";
    //     cout << "_________________________________\n";
    //     cin >> iChoice;

    //     switch (iChoice)
    //     {
    //     case 1:
    //         cout << "Enter Element :";
    //         cin >> val;
    //         obj.InsertFirst(val);
    //         break;
    //     case 2:
    //         cout << "Enter Element :";
    //         cin >> val;
    //         obj.InsertLast(val);
    //         break;
    //     case 3:
    //         cout << "Enter Element :";
    //         cin >> val;
    //         cout << "Enter position :";
    //         cin >> pos;
    //         obj.InsertAtPos(val, pos);
    //         break;

    //     case 4:
    //         obj.DeleteFirst();
    //         break;

    //     case 5:
    //         obj.DeleteLast();
    //         break;

    //     case 6:
    //         cout << "Enter position :";
    //         cin >> pos;
    //         obj.DeleteAtPos(pos);
    //         break;

    //     case 7:
    //         obj.Display();
    //         break;

    //     case 8:
    //         iRet = obj.Count();
    //         cout << "Elements in LL:" << iRet << "\n";
    //         break;

    //     case 0:
    //         cout << "Application Closed!\n";
    //         break;

    //     default:
    //         cout << "Enter valid choice\n";
    //         break;
    //     }
    // }

        // SinglyCircularLL<char> cobj;

    cout<<"Singly Circular LL:\n";
    cout<<"______________________________________________\n";
    cobj.InsertFirst(3);
    cobj.InsertFirst(2);
    cobj.InsertFirst(1);
    
    cobj.InsertLast(4);
    cobj.InsertLast(5);
    
    cobj.Display();

    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.Display();

    cobj.InsertAtPos(33,1);
    cobj.Display();
    cobj.DeleteAtPos(1);
    cobj.Display();

    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.Display();
    
    int iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    cout<<"__________________________________________\n";

    return 0;
}
