#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a;
    cin >> a;

    int left=0;




    for (int i = 1; i <= n; i++)
    {
        int arg = a;
        for(int j = 1;j<=n;j++)
        {
            cout<<"*";
            if(left==0)
                left=1;
            else
            {
                left=0;
            }

        }
        cout<<endl;
        while(arg>0 && i<n)
        {
            i++;
            if(left==0)
            cout<<"*"<<endl;
            else
            {
                for(int k = 1;k<=n-1;k++)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
            }
            arg--;
        }
    }
}