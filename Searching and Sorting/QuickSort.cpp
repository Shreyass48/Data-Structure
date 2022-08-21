///////////////////////////////////////////////
//
// Quick Sort
//
///////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    // take pivot
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }    
    }

    // putting pivot at propr position
    int pivotIndx = s + cnt;
    swap(arr[pivotIndx], arr[s]);

    // sort left and right part
    // < pivot | pivot | > pivot
    int i = s, j = e;
    while(i < pivotIndx && j > pivotIndx)
    {
        while(arr[i] <= pivot)
        {   
            i++;
        }

        while(arr[j] > pivot)
        {    
            j--;
        }

        if(i < pivotIndx && j > pivotIndx)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndx;
}

void qSort(int arr[], int s,int e)
{
    while(s >= e)
    {
        return;
    }
    // pivot indx
    int p = partition(arr,s,e);

    //for left side sorting
    qSort(arr,s,p-1);
    //for right side sorting
    qSort(arr,p+1,e);
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
    qSort(arr, 0, n-1);
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