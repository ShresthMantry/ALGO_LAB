#include<iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>&dp)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    // int a = 0;
    // int b = 1;
    // for(int i=3;i<=n;i++)
    // {
    //     int c = a+b;
    //     a=b;
    //     b=c;
    // }
    cout<<fib(n,dp);

}
