#include<bits/stdc++.h>
int findUnique(int *arr, int size)
{
    //Write your code here
    /*TC=O(n^2) SC=)(1)
    for(int i=0;i<size;i++)
    {
        int f=0;
        for(int j=0;j<size;j++)
        {
            if(i!=j &&arr[i]==arr[j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
            return arr[i];
    }
    */
    //TC=O(n) SC=O(1)
    int ans=arr[0];
    for(int i=1;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}
