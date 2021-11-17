#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node * Next;
}NODE, *PNODE;

class SinglyLL
{
    private:
    PNODE first;
    int size;

    public:
    SinglyLL()
    {
        first = NULL;
        size = 0;
    }
    void InsertFirst(int no)
    {
        PNODE newn = new NODE;

        newn->Data = no;
        newn->Next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->Next = first;
            first = newn;
        }
        size++;


    }
    void InsertLast(int no)
    {
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->Data = no;
        newn->Next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            while (temp->Next != NULL)
            {
                temp = temp->Next;
            }
            temp->Next = newn;
        }
        size++;

    }
    void InsertAtPos(int no, int iPos)
    {
        int i = 0;
        if((iPos < 1) || (iPos > size+1))
        {
            cout<<"invalid!\n";
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == size + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE newn = new NODE;
            PNODE temp = first;

            newn->Data = no;
            newn->Next = NULL;

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp->Next;
            }
            newn->Next = temp->Next;
            temp->Next = newn;
            
        }
        size++;
    }
    void DeleteFirst()
    {
        PNODE temp = first;
        if(first != NULL)
        {
            first = temp->Next;
            delete temp; 
            size--;
        }

        
    }
    void DeleteLast()
    {
        PNODE temp = first;

        if(first == NULL)
        {
            return;
        }
        else if(first->Next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while (temp->Next->Next != NULL)
            {
                temp = temp->Next;
            }
            delete temp->Next;
            temp->Next = NULL;

            size--;
        }
    }
    void DeleteAtPos(int iPos)
    {
        PNODE temp = first;
        PNODE target = NULL;
        int i = 0;

        if((iPos < 1) || (iPos > size))
        {
            cout<<"invalid!\n";
            return;
        }
        
        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == size)
        {
            DeleteLast();
        }
        else
        {
            for(i = 1; i < iPos-1; i++)
            {
                temp = temp->Next;
            }
            target = temp->Next;
            temp->Next = target->Next;
            delete target;
            size--;
        }
    }
    void Display()
    {
        PNODE temp = first;
        while(temp != NULL)
        {
            cout<<temp->Data<<"\t";
            temp = temp->Next;
        }cout<<"\n";
    }
    int Count()
    {
        return size;
    }
};

int main()
{
    int iRet = 0, iChoice = 1, val = 0, pos = 0;

    SinglyLL obj;

    // obj.InsertFirst(30);
    // obj.InsertFirst(20);
    // obj.InsertFirst(10);

    // obj.InsertLast(40);

    // obj.InsertAtPos(25,3);
    // obj.Display();

    // obj.DeleteFirst();
    // obj.Display();

    // obj.DeleteLast();
    // obj.Display();

    // obj.DeleteAtPos(2);
    // obj.Display();

    // iRet = obj.Count();
    // cout<<"Elements in LL:"<<iRet<<"\n";

    while(iChoice != 0)
    {
        cout<<"_________________________________\n";
        cout<<"1. Insert at First\n";
        cout<<"2. Insert at Last\n";
        cout<<"3. Insert at Position\n";
        cout<<"4. Delete at First\n";
        cout<<"5. Delete at Last\n";
        cout<<"6. Delete at Position\n";
        cout<<"7. Display\n";
        cout<<"8. Count\n";
        cout<<"_________________________________\n";
        cin>>iChoice;

        switch (iChoice)
        {
        case 1:
            cout<<"Enter Element :";
            cin>>val;
            obj.InsertFirst(val);
            break;
        case 2:
            cout<<"Enter Element :";
            cin>>val;
            obj.InsertLast(val);
            break;
        case 3:
            cout<<"Enter Element :";
            cin>>val;
            cout<<"Enter position :";
            cin>>pos;
            obj.InsertAtPos(val,pos);
            break;

        case 4:
            obj.DeleteFirst();
            break;

        case 5:
            obj.DeleteLast();
            break;

        case 6:
            cout<<"Enter position :";
            cin>>pos;
            obj.DeleteAtPos(pos);
            break;

        case 7:
            obj.Display();
            break;

        case 8:
            iRet = obj.Count();
            cout<<"Elements in LL:"<<iRet<<"\n";
            break;

        case 0:
            cout<<"Application Closed!\n";
            break;
        
        default:
            cout<<"Enter valid choice\n";
            break;
        }

    }



    return 0;
}
