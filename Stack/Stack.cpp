/////////////////////////////////////////////////////////
// 
// Title : Implementation of Stack.
// Author: Shreyas Kulkarni
// Date  : 16/11/21
// 
/////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Stack     
{
private:
    PNODE first;
    int size;
    
public:
    Stack()
    {
        first = NULL;
        size = 0;
    }
    
    void push(int no)   
    {
        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
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
    
    int pop()   
    {
        PNODE temp = first;
        int val = 0;
        
        if(first->next == NULL)
        {
            val = first->data;
            delete first;
            first = NULL;
            
        }
        else
        {
            val = first->data;
            first = temp->next;
            delete temp;

        }
        size--;
        return val; 
    }
    
    void Display()
    {
        PNODE temp = first;
        while (temp != NULL)
        {
            cout<<"|"<<temp->data<<"|\n";
            temp = temp->next;
        }
        
    }
    
    int Count()
    {
        return size;
    }
};

int main()
{
    Stack obj;
    int iret = 0, choice = 1, value = 0;

    while (choice != 0)
    {
       cout<<"________________________\n";
       cout<<"Enter your choice :\n";
       cout<<"1. Push Element\n";
       cout<<"2. Pop Element\n";
       cout<<"3. Display Stack\n";
       cout<<"4. Count total elements\n";
       cout<<"________________________\n";
       
       cin>>choice;

        switch (choice)
    {
    case 1:
        cout<<"Enter element : ";
        cin>>value;
        obj.push(value);
        break;
    case 2:
        iret = obj.pop();
        cout<<"Popped element is :"<<iret<<"\n";     
        break;
    case 3:
        obj.Display();
        break;
    case 4:
        iret = obj.Count();
        cout<<"Size of stack is : "<<iret<<"\n";  
        break;
    case 0:
        cout<<"Thnak you!\n";

    default:
        cout<<"ENter valid choice!\n";
        break;
    }
    }

   
          
    
    return 0;
}
