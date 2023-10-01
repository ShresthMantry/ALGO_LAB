#include<iostream>
using namespace std;

int solve(int* arr,int low,int high)
{
    if(low==high)
    {
        return arr[low];
    }

    int mid = (low+high)/2;
    if(mid==0 && arr[mid]>arr[mid+1])
    {
        return arr[mid];
    }
    if(mid<high && arr[mid]>arr[mid+1] && mid>0 && arr[mid]>arr[mid-1])
    {
        return arr[mid];
    }
    if(arr[low]>arr[mid])
    {
        return solve(arr,low,mid-1);
    }
    return solve(arr,mid+1,high);
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    int low = 0;
    int high = n-1;

    cout<<solve(arr,0,n-1);
    
}