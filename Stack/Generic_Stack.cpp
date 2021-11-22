/////////////////////////////////////////////////////////
//
// Title : Implementation of Stack.
// Type  : Generic Programming
// Author: Shreyas Kulkarni
// Date  : 19/11/21
//
/////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <typename T>
struct node
{
    int data;
    struct node *next;
};

template <class T>
class Stack
{
private:
    node<T> *first;
    int size;

public:
    Stack();
    void push(T);
    int pop();
    void Display();
    int Count();
};

template <class T>
Stack<T>::Stack()
{
    first = NULL;
    size = 0;
}

template <class T>
void Stack<T>::push(T no)
{
    node<T> *newn = new node<T>;

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

template <class T>
int Stack<T>::pop()
{
    node<T> *temp = first;
    int val = 0;

    if (first->next == NULL)
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

template <class T>
void Stack<T>::Display()
{
    node<T> *temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return size;
}

int main()
{
    Stack<int> obj;
    int iret = 0, choice = 1, value = 0;

    while (choice != 0)
    {
        cout << "________________________\n";
        cout << "Enter your choice :\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Display Stack\n";
        cout << "4. Count total elements\n";
        cout << "________________________\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element : ";
            cin >> value;
            obj.push(value);
            break;
        case 2:
            iret = obj.pop();
            cout << "Popped element is :" << iret << "\n";
            break;
        case 3:
            obj.Display();
            break;
        case 4:
            iret = obj.Count();
            cout << "Size of stack is : " << iret << "\n";
            break;
        case 0:
            cout << "Thnak you!\n";

        default:
            cout << "ENter valid choice!\n";
            break;
        }
    }

    return 0;
}
