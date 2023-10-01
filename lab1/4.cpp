#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a;
    cin >> a;

    int left=0;

    int **arr = new int*[n];
    for(int i = 0;i<n;i++)
    {
        arr[i]= new int[n];
    }

    for (int i = 1; i <= n; i++)
    {
        int arg = a;
        for(int j = 1;j<=n;j++)
        {
            //cout<<"*";
            arr[i-1][j-1]=1;
            if(left==0)
                left=1;
            else
            {
                left=0;
            }

        }
        while(arg>0 && i<n)
        {
            i++;
            if(left==0)
                arr[i-1][0]=1;
            else
            {
                arr[i-1][n-1]=1;
            }
            arg--;
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]==1)
            cout<<'*';
            else
            cout<<" ";
        }
        cout<<endl;
    }
}