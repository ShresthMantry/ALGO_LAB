#include <iostream>
#include <climits>
using namespace std;

int right(int **dp, int **arr, int i, int j, int n, int m)
{
    if (j + 1 < m && arr[i][j + 1] <= arr[i][j])
    {
        return dp[i][j + 1];
    }
    return -1;
}

int below(int **dp, int **arr, int i, int j, int n, int m)
{
    if (i + 1 < n && arr[i + 1][j] < arr[i][j])
    {
        return dp[i + 1][j];
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int b = 1 + below(dp, arr, i, j, n, m);
            int r = 1 + right(dp, arr, i, j, n, m);
            dp[i][j] = max(max(b, r), 1);
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int maximum = 0;
    int maxi, maxj = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maximum = max(maximum, dp[i][j]);
            if (maximum == dp[i][j])
            {
                maxi = i;
                maxj = j;
            }
        }
    }

    cout << endl
         << maximum << endl;

    while (dp[maxi][maxj] >= 1)
    {
        cout << arr[maxi][maxj] << " ";
        if (maxi + 1 < n && dp[maxi + 1][maxj] == dp[maxi][maxj] - 1)
        {
            maxi = maxi + 1;
        }
        else if (maxj + 1 < m && dp[maxi][maxj + 1] == dp[maxi][maxj] - 1)
        {
            maxj = maxj + 1;
        }
        else
        {
            break;
        }
    }
}