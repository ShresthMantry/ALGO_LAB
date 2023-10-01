#include <iostream>
#include <vector>
using namespace std;

unsigned int fact(int n, vector<int> &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }

    if (n == 1 || n == 0)
    {
        return 1;
    }

    return dp[n] = n * fact(n - 1, dp);
}

unsigned int ncr(int n, int r, vector<int> &dp)
{
    return (fact(n, dp) / (fact(n - r, dp) * fact(r, dp)));
}

unsigned int solve(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans + ncr(n, i, dp) * solve(n - i, dp);
    }
    cout << ans << endl;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp);
}