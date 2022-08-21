///////////////////////////////////////////////
//
// Insertion Sort
//
///////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

void iSort(int arr[], int n)
{
    int key = 0, i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
       key = arr[i];
       for(j = i - 1; (j >= 0) && (arr[j] > key); j--)
       {
            arr[j+1] = arr[j];
       } 
       arr[j+1] = key;
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
    iSort(arr, 5);
    cout<<"After Sorting"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}

/*
    -Like selection sort(minIndx) maintain Key here chk it
     and insert in corect position
    - No swapping
    Time Complexity : n^2;
*/