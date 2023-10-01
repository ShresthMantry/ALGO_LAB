#include<stdio.h>
#include<stdlib.h>

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

int mergeSort(int *arr,int low,int high,int n)
{
    if(low==high)
    {
        return -1;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid,n);
    mergeSort(arr,mid+1,high,n);
    merge(arr,low,mid,high);
    int count = 1;
    int max = -1;
    for(int i = low+1;i<=high;i++)
    {
        if(arr[i-1]==arr[i])
        {
            count++;
        }
        else
        {
            if(count>n/2)
            {
                max = arr[i-1];
            }
            count=1;
        }
    }
    return max;


}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        arr[i]=num;
    }

    int ans = mergeSort(arr,0,n-1,n);

    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }

    printf("\n %d ",ans);


}