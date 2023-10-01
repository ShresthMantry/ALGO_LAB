#include<iostream>
using namespace std;

int solve(int *arr, int low,int high)
{
    if(low==high)
    {
        return arr[low];
    }
    int mid = (low+high)/2;
    int left = solve(arr,low,mid);
    int right = solve(arr,mid+1,high);
    return max(left,right);
}


int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i= 0;i<n;i++)
    {
        cin>>arr[i];   
    }

    int ans = solve(arr,0,n-1);
    cout<<ans;
}