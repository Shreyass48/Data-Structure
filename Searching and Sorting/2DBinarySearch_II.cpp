///////////////////////////////////////////////
//
// Search in Sorted Row wise  & col wise Matrix
//
///////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

bool SearchElement(int brr[][3], int key, int n, int m)
{
    int row = n;
    int col = m;

    //Pointing to 1st rows last col
    int rIndx = 0;
    int cIndx = col -1;

    while(rIndx < row && cIndx >= 0)
    {
        int element = brr[rIndx][cIndx];
        if(element == key)
            return 1;
        
        if(element < key)
        {
            rIndx++;
        }
        else
        {
            cIndx--;
        }
    }
    return 0;
}

int main()
{
    int arr[][3] = {{1,4,7}, {2,5,8},{3,6,9}};
    int key = 13;

    bool ans = SearchElement(arr,key,3,3);

    cout<<ans<<endl;

    return 0;
}

// Time Comp : o(log MN)