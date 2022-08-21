///////////////////////////////////////////////
//
// Efficient Bubble Sort
//
///////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

void bSort(int arr[], int n)
{
    bool flag = 0;
    for(int i = 0; i < n; i++)
    {
        flag = 0;
       for(int j = 0; j < n - i - 1; j++)
       {
            if(arr[j] > arr[j+1])
            {
                flag = 1;
                swap(arr[j],arr[j+1]);
            }
       } 
       if(flag == 0)
        break;
    }
}

int main()
{
    int arr[] = {3,2,1,4,5};

    cout<<"Before Sorting"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    bSort(arr, 5);
    cout<<"After Sorting"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}

/*
    - Using flag we can cheak if that pass is already sorted or not 
    if flag is false then we just skip that pass.

    Time Complexity : n^2;
*/