#include<iostream>
using namespace std;

pair<int,int> solve(int *arr, int low,int high)
{
    if(low==high)
    {
        return {arr[low],arr[low]};
    }
    int mid = (low+high)/2;
    pair<int,int> left = solve(arr,low,mid);
    pair<int,int> right = solve(arr,mid+1,high);
    return {max(left.first,right.first),min(left.second,right.second)};
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

    pair <int,int> ans = solve(arr,0,n-1);
    cout<<"Max "<<ans.first<<" Min "<<ans.second;

}