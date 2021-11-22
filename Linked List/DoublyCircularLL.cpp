/////////////////////////////////////////////////////////
// 
// Title : Implementation of Doubly Circular Liked List.
// Author: Shreyas Kulkarni
// Date  : 18/11/21
// 
/////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node * Next;
    struct node * Prev;
}NODE,*PNODE;

class DoublyCL
{
    private:
    PNODE first;
    PNODE last;
    int size;

    public:
    DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }

    //Function Declaration
    void Display();
    int Count();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no,int pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int pos);

};

// Return_Value Class_Name :: Function_Name(Parameters)

void DoublyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->Data = no;
    newn->Next = NULL;
    newn->Prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->Next = first;
        first-> Prev = newn;
        first = newn;
    }
    last->Next = first;     
    first->Prev = last;     
    size++;
}
void DoublyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->Data = no;
    newn->Next = NULL;
    newn->Prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->Next = newn;
        newn->Prev = last;
        last = newn;
    }
    last->Next = first;     
    first->Prev = last;    
    size++;
}

void DoublyCL :: Display()
{
    PNODE temp = first;

    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->Data<<"| -> ";
        temp = temp->Next;
    }
    cout<<"NULL\n";
}

int DoublyCL :: Count()
{
    return size;
}

void DoublyCL :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->Next;
        delete last->Next;  // first->prev
        first->Prev = last;
        last->Next = first;
    
    }
    size--;

} 

void DoublyCL :: DeleteLast()
{
    PNODE temp = first;
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->Prev;
        delete last->Next;  //first->prev
        first->Prev = last;
        last->Next = first;       
    }
    size--;
} 

void DoublyCL :: InsertAtPos(int no,int pos)
{
    PNODE temp = first;
    if((pos < 1) || (pos > size + 1))
    {
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->Data = no;
        newn->Next = NULL;
        newn->Prev = NULL;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next->Prev = newn;
        temp->Next = newn;
        newn->Prev = temp;  
    }
    size++;
}
void DoublyCL :: DeleteAtPos(int pos)
{
    PNODE temp = first;
    if((pos < 1) || (pos > size))
    {
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == size)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->Next;
        }
        temp->Next = temp->Next->Next;
        delete temp->Next->Prev;
        temp->Next->Prev = temp;    
        size--;
    }
   
}

int main()
{

    DoublyCL obj;

    // obj.InsertFirst(21);
    // obj.InsertFirst(11);
    // obj.InsertLast(51);
    // obj.InsertLast(101);

    // obj.Display();

    // obj.InsertAtPos(75,3);
    // obj.Display();
    // iRet = obj.Count();
    // cout<<"Elements in LL are: "<<iRet<<"\n";

    // obj.DeleteAtPos(3);
    // obj.DeleteFirst();
    // obj.DeleteLast();
    // obj.Display();
    // iRet = obj.Count();
    // cout<<"Elements in LL are: "<<iRet<<"\n";

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
