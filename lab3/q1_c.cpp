#include<iostream>
#include<limits.h>
using namespace std;

pair<int,int> solve(int *arr, int low,int high)
{
    if(low==high)
    {
        return {arr[low],INT_MIN};
    }
    int mid = (low+high)/2;
    pair<int,int> left = solve(arr,low,mid);
    pair<int,int> right = solve(arr,mid+1,high);
    int maxi;
    int smaxi;
    if(left.first>right.first)
    {
        maxi = left.first;
        smaxi = max(right.first,left.second);
    }
    else if(right.first>left.first) 
    {
        maxi = right.first;
        smaxi = max(right.second,left.first);
    }
    else if(right.first==left.first)
    {
        maxi = left.first;
        smaxi = max(right.second,left.second);
    }
    return {maxi,smaxi};
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
    cout<<"Max "<<ans.first<<" Second Max "<<ans.second;

}