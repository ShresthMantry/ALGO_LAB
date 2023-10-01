#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a = 2;
    int b = 4;

    if(n<a)
    {
        cout<<'0';
    }
    else if(n==a || (n>a && n<b))
    {
        cout<<'1';
    }
    else if(n== b || (n>b && n<a+b+1))
    {
        cout<<'2';
    }
    else
    {
        int height = 3;
        while(true)
        {
            int nodes = a+b+1;
            if(n==nodes)
            {
                cout<<height;
                break;
            }
            if(n<nodes)
            {
                cout<<height-1;
                break;
            }
            int c = b;
            b = a+b+1;
            a = c;
            height++;
        }
    }
}