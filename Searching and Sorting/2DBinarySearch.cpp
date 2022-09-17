//////////////////////////////////////
//
// Search in Sorted Matrix
//
/////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

bool SearchElement(int brr[][3], int key, int n, int m)
{
    // row  = n
    // col = m
    int s = 0;
    int e = n * m - 1;
    int mid = s + (e-s)/2;

    while(s <= e)
    {
        
        int element = brr[mid/m][mid%m];
        if(element == key)
            return 1;
        
        if(element < key)
        {
            s = mid+1;
        }
        else
        {
            e= mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return 0;
}

int main()
{
    int arr[][3] = {{1,2,3}, {4,5,6},{7,8,9}};
    int key = 3;

    bool ans = SearchElement(arr,key,3,3);

    cout<<ans<<endl;

    return 0;
}

// Time Comp : o(log MN)
