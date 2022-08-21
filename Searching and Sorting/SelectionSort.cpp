///////////////////////////////////////////////
//
// Selection Sort
//
///////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

void sSort(int arr[], int n)
{
    int minIndx = 0;
    for(int i = 0; i < n; i++)
    {
       minIndx = i;
       for(int j = i; j < n; j++)
       {
            if(arr[minIndx] > arr[j])
            {
                minIndx = j;
            }
       } 
       swap(arr[i],arr[minIndx]);
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
    sSort(arr, 5);
    cout<<"After Sorting"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}

/*
    - Use MinIndx and just swap it with current i
    Time Complexity : n^2;
*/