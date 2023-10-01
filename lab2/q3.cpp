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

    int num;
    cin>>num;

    int low = 0;
    int high = n-1;


    while(low<=high)
    {
        int mid = (high-low+1)/3;
        if(arr[low+mid]==num)
        {
            cout<<mid+low<<endl;
            break;
        }
        else if(arr[low+2*mid]==num)
        {
            cout<<mid+2*low<<endl;
        }
        else if(num<arr[low+mid])
        {
            high = low+mid-1;
        }
        else if(arr[2*mid+low]<num)
        {
            low = 2*mid+low+1;
        }
        else if(num>arr[low+mid] && num<arr[low+2*mid])
        {
            low = mid+low+1;
            high = mid+2*low-1;
        }

    }

}