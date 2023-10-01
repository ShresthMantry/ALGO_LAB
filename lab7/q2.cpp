#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>&arr,int i, int j,vector<vector<int>>&dp)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini = INT_MAX;
    for(int k = i;k<=j-1;k++)
    {
        int ans = arr[i-1]*arr[k]*arr[j]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
        mini = min(ans,mini);
    }

    return dp[i][j]=mini;

}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i = 0;i<n;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    // cout<<solve(arr,1,n-1,dp);
    for(int i = n-1;i>=1;i--)
    {
        for(int j = i+1;j<=n-1;j++)
        {
            int mini = INT_MAX;
            for(int k = i;k<=j-1;k++)
            {
                int ans=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini = min(ans,mini);
            }
            dp[i][j]= mini;
        }
    }

    cout<<dp[1][n-1];
}