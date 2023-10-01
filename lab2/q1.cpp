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

    int first = arr[0];
    int last = arr[n-1];

    if(first>last)
    {
        cout<<"Largest "<<first<<" Smallest"<<last;
    }
    else
    {
        cout<<"Largest "<<last<<" Smallest"<<first;
    }
}