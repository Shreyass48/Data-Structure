#include<iostream>
using namespace std;

class BinarySearch
{
   public:
   bool Bs(int Arr[],int no,int isize)
    {
        int i = 0, j = 0, start, end, mid;
        start = 0;
        end = isize - 1;
        mid = (start + end) / 2;

        for(i = 0; i < isize; i++)
        {
            if(Arr[mid] == no)
            {
                break;
            }
            else if(Arr[mid] > no)
            {
                end = mid - 1;
            }
            else if(Arr[mid] < no)
            {
                start = mid + 1;
            }
            mid = (start + mid) / 2;
        }
        if(Arr[mid] == no)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int main()
{
    int iNo = 0, size = 0;

    cout<<"Enter size of array : \n";
    cin>>size;

    int *Arr = new int[size];  

    cout<<"Enter elements :";
    for(int i = 0; i < size; i++)
    {
        cin>>Arr[i];
    }
    cout<<"Entered elements :";
    for(int i = 0; i < size; i++)
    {
        cout<<Arr[i]<<"\n";
    }

    cout<<"Enter number to search :";
    cin>>iNo;
    
    bool bret = false;

    BinarySearch obj;
    bret = obj.Bs(Arr,iNo,size);
    if(bret == true)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Element not Found.\n";
    }

    return 0;
}