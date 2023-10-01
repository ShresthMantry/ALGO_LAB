#include <iostream>
using namespace std;

int main()
{
    string num1;
    cin>>num1;
    string num2;
    cin>>num2;

    int n;
    cin>>n;

    int **arr = new int*[n];
    for(int i = 0;i<n;i++)
    {
        arr[i]=new int[2*n];
    }

    int row = 0;
    int count = 0;

    for(int i = num2.length()-1;i>=0;i--)
    {
        int digit = num2[i]-'0';
        int carry = 0;
        
        int col = 2*n-1;
        for(int j = num1.length()-1;j>=0;j--)
        {
            int upDigit = num1[j]-'0';
            int res = digit*upDigit+carry;
            int ans = res%10;
            carry = res/10;
            arr[row][col-count]=ans;
            col--;
        }
        arr[row][col-count]=carry;
        count++;
        row++;
    }



    int carry = 0;
    int *arr2 = new int[2*n+1];
    int k = 2*n;

    for(int i = 2*n-1;i>=0;i--)
    {
        int sum = 0;
        for(int j= 0;j<n;j++)
        {
            sum = sum+arr[j][i];
        }

        int res = sum+carry;
        int digit = res%10;
        carry = res/10;
        arr2[k--]=digit;
        

    }
    arr2[k]=carry;


    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = 0;j<2*n;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<endl;
    for(int i = 0;i<2*n+1;i++)
    {
        cout<<arr2[i]<<" ";
    }
}