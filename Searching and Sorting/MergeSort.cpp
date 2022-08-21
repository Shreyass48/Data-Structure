///////////////////////////////////////////////
//
// Merge Sort
//
///////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    
    // length of new 2 arrays i.e. left and right side
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //creating 2 arrays
    int *first = new int[len1];
    int *second = new int[len2];

    //Copy values
    int mainArrIndx = s;
    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrIndx++];
    }
    mainArrIndx = mid+1;
    for(int i = 0; i < len1; i++)
    {
        second[i] = arr[mainArrIndx++];
    }

    // Merge Arrays
    int indx1 = 0;
    int indx2 = 0;
    mainArrIndx = s; 

    while(indx1 < len1 && indx2 < len2)
    {
        if(first[indx1] < second[indx2])
        {
            arr[mainArrIndx++] = first[indx1++];
        }
        else
        {
            arr[mainArrIndx++] = second[indx2++];
        }
    }

    while(indx1 < len1)
    {
        arr[mainArrIndx++] = first[indx1++];
    }

    while(indx2 < len2)
    {
        arr[mainArrIndx++] = second[indx2++];
    }

    delete []first;
    delete []second;
}

void mSort(int arr[], int s,int e)
{
    while(s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    //for left side sorting
    mSort(arr,s,mid);
    //for right side sorting
    mSort(arr,mid+1,e);

    // Merge that sorted Arrays
    merge(arr,s,e);
}

int main()
{
    int arr[5] = {3,2,1,4,5};
    int n = 5;
    cout<<"Before Sorting"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    mSort(arr, 0, n-1);
    cout<<"After Sorting"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}

/*
    
    Time Complexity : o(N log N);
*/