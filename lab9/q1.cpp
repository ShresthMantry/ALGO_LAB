#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    int *sortedarr = new int[n];
    int maxi = INT_MIN;
    int mini = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        maxi = max(maxi,arr[i]);
        mini= min(mini,arr[i]);
    }

    int *count = new int[maxi-mini+1];
    for(int i = 0;i<n;i++)
    {
        count[arr[i]-mini]++;
    }

    for(int i = 1;i<maxi-mini+1;i++)
    {
        count[i]=count[i-1]+count[i];
    }

    for(int i = n-1;i>=0;i--)
    {
        int ele = arr[i];
        int index = count[ele-mini];
        sortedarr[index-1]=ele;
        count[ele-mini]=count[ele-mini]-1;
    }


    for(int i = 0;i<n;i++)
    {
        cout<<sortedarr[i]<<" ";
    }


}