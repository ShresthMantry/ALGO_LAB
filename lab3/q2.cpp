#include <iostream>
using namespace std;

// int solve(int *arr, int low, int high)
// {
//     if (low == high)
//         return 0;
//     int mid = (low + high) / 2;
//     if (mid > 0 && arr[mid] - arr[mid - 1] == 2)
//     {
//         return arr[mid] - 1;
//     }
//     if (mid < high && arr[mid + 1] - arr[mid] == 2)
//     {
//         return arr[mid + 1] - 1;
//     }
//     int left = solve(arr, low, mid);
//     if (left != 0)
//     {
//         return left;
//     }
//     int right = solve(arr, mid + 1, high);
//     if (right != 0)
//     {
//         return right;
//     }
//     return 0;
// }

int solve(int *arr,int low,int high)
{
    if(low==high)
    {
        return arr[low]-1;
    }
    int mid = (low+high)/2;
    if(mid+1==arr[mid])
    {
        return solve(arr,mid+1,high);
    }
    return solve(arr,low,mid);

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

    int ans = solve(arr, 0, n - 1);
    cout << ans;
}