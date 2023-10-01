#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    // int num;
    // cin>>num;

    // int low = 0;
    // int high = n-1;


    // while(low<=high)
    // {
    //     int mid = (low+high)/2;
    //     if(arr[mid]==num)
    //     {
    //         cout<<mid<<endl;
    //         break;
    //     }
    //     else if(arr[mid]>num)
    //     {
    //         high = mid-1;
    //     }
    //     else if(arr[mid]<num)
    //     {
    //         low = mid+1;
    //     }

    // }

    int low = 0;
    int high = n-1;
    int alpha;
    cin>>alpha;


    while(low<=high)
    {
        int mid = ((high-low)*2)/3;
        mid =  mid+low;
        if(arr[mid]==alpha)
        {
            cout<<mid;
            break;
        }
        else if(arr[mid]>alpha)
        {
            high = mid-1;
        }
        else if(arr[mid]<alpha)
        {
            low = mid+1;
        }
        
    }

    // int low = 0;
    // int high = n-1;
    // int alpha;
    // cin>>alpha;


    // while(low<=high)
    // {
    //     int mid = ((high-low)*1)/4;
    //     mid =  mid+low;
    //     if(arr[mid]==alpha)
    //     {
    //         cout<<mid;
    //         break;
    //     }
    //     else if(arr[mid]>alpha)
    //     {
    //         high = mid-1;
    //     }
    //     else if(arr[mid]<alpha)
    //     {
    //         low = mid+1;
    //     }
        
    // }
}