#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head, int no)
{
    PNODE newn = new NODE;
    PNODE temp = *Head;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(1)
        {
            if(temp->data == no)
            {
                delete newn;
                break;
            }
            else if(no < (temp->data))
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no > (temp->data))
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;

            }
        }
        
    }


}

bool Search(PNODE Head, int no)
{
    if(Head == NULL)
    {
        return false;
    }
    else
    {
        while(Head != NULL)
        {
            if(Head->data == no)
            {
                break;
            }
            else if(Head->data < no)
            {
                Head = Head->rchild;
            }
            else if(Head->data > no)
            {
                Head = Head->lchild;
            }
        }
        
    }
    if(Head == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }

}

int Count(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
       iCnt++;
       Count(Head->lchild);
       Count(Head->rchild);
    }
    return iCnt;
} 


int CountLeaf(PNODE Head)
{
    static int icnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            icnt++;
        }
        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }
    return icnt;
}

int CountParent(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
       if((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            iCnt++;
        }
       CountParent(Head->lchild);
       CountParent(Head->rchild);
    }
    return iCnt;
} 

void In(PNODE Head)
{
    if(Head != NULL)
    {
        In(Head->lchild);
        cout<<Head->data<<"\n";
        In(Head->rchild);
    }
}
void Pre(PNODE Head)
{
    if(Head != NULL)
    {
        cout<<Head->data<<"\n";
        Pre(Head->lchild);
        Pre(Head->rchild);
    }
}
void Post(PNODE Head)
{
    if(Head != NULL)
    {
        Post(Head->lchild);
        Post(Head->rchild);
        cout<<Head->data<<"\n";
    }
}

int main()
{
    PNODE first = NULL;
    bool bret = false;
    int iRet = 0;

    Insert(&first,21);
    Insert(&first,31);
    Insert(&first,11);


    bret = Search(first,21);
    if(bret == true)
    {
        cout<<"Element found\n";
    }
    else
    {
        cout<<"Element not found\n";
    }

    iRet = Count(first);
    cout<<"Total elements : "<<iRet<<"\n";
    iRet = CountLeaf(first);
    cout<<"Total Leaf Node : "<<iRet<<"\n";
    iRet = CountParent(first);
    cout<<"Total Parent NOde : "<<iRet<<"\n";

    cout<<"IN:\n";
    In(first);
    cout<<"Pre:\n";
    Pre(first);
    cout<<"Post:\n";
    Post(first);

    return 0;
}
