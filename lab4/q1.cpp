#include <iostream>
using namespace std;

int solve(int *arr, int low, int high, int n)
{
    int mid = (low + high) / 2;
    if (mid == 0 && arr[mid] >= arr[mid + 1])
    {
        return arr[mid];
    }
    if (mid == n - 1 && arr[mid] >= arr[mid - 1])
    {
        return arr[mid];
    }
    if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
    {
        return arr[mid];
    }

    if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        return solve(arr, low, mid - 1, n);
    }
    else if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
    {
        return solve(arr, mid + 1, high, n);
    }
    else if (arr[mid - 1] > arr[mid + 1])
    {
        return solve(arr, low, mid - 1, n);
    }

    return solve(arr, mid + 1, high, n);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(arr, 0, n - 1, n);
    cout << ans;
}
