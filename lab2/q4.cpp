#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
using namespace std;

void merge(int *arr,int low,int mid,int high)
{
    int left = low;
    int right = mid+1;
    int *temp = (int*)calloc(high-low+1,sizeof(int));

    int k = 0;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp[k++]=arr[left++];
        }
        else if(arr[right]<arr[left])
        {
            temp[k++]=arr[right++];
        }
    }

    while(left<=mid)
    {
        temp[k++]=arr[left++];
    }
    while(right<=high)
    {
        temp[k++]=arr[right++];
    }

    for(int i = low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    free(temp);
}



void mergeSort(int *arr, int low, int high)
{
    if (low == high)
    {
        return;
    }
    double middle = (high - low + 1) / 4;
    int mid;
    if (middle - int(middle) >= 0.5)
        mid = int(ceil(middle));
    else
        mid = int(floor(middle));
    mergeSort(arr, low, low + mid - 1);
    mergeSort(arr, low + mid, low + 2 * mid - 1);
    mergeSort(arr, low + 2 * mid, low + 3 * mid - 1);
    mergeSort(arr, low + 3 * mid, high);
    merge(arr, low, low + mid - 1, low + 2 * mid - 1);
    merge(arr, low + 2 * mid, low + 3 * mid - 1, high);
    merge(arr, low, low + 2 * mid - 1, high);
    // newMerge(arr,low,low+mid-1,low+2*mid-1,low+3*mid-1,high);
}

int main()
{

    int n;
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}