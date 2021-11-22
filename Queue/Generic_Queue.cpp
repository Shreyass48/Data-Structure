/////////////////////////////////////////////////////////
//
// Title : Implementation of Queue.
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
    T data;
    struct node *next;
};

template <class T>
class Queue
{
private:
    node<T> *first;
    int size;

public:
    Queue();
    void Enqueue(T);
    int Dequeue();
    void Display();
    int Count();
};

template <class T>
Queue<T>::Queue()
{
    first = NULL;
    size = 0;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
    node<T> *newn = new node<T>;
    node<T> *temp = first;

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

template <class T>
int Queue<T>::Dequeue()
{
    node<T> *temp = first;
    int val = 0;

    if (size == 0)
    {
        cout << "Queue is empty!\n";
        return -1;
    }

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
void Queue<T>::Display()
{
    node<T> *temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "\n";
}

template<class T>
int Queue<T>::Count()
{
    return size;
}


int main()
{
    Queue<int> obj;

    int iret = 0, choice = 1, value = 0;

    while (choice != 0)
    {
        cout << "________________________\n";
        cout << "Enter your choice :\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display queue\n";
        cout << "4. Count total elements\n";
        cout << "________________________\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element : ";
            cin >> value;
            obj.Enqueue(value);
            break;
        case 2:
            iret = obj.Dequeue();
            cout << "Deleted element is :" << iret << "\n";
            break;
        case 3:
            obj.Display();
            break;
        case 4:
            iret = obj.Count();
            cout << "Size of queue is : " << iret << "\n";
            break;
        case 0:
            cout << "Thnak you!\n";

        default:
            cout << "Enter valid choice!\n";
            break;
        }
    }

    return 0;
}
