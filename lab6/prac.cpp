#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int select(vector<int> v, int n, int k)
{
    if(k>n)
    {
        return -1;
    }
    if(n<=2)
    {
        return v.at(n/2);
    }
    int median = -1;
    if(n<=5)
    {
        sort(v.begin(),v.end());
        median = v.at(n/2);
    }
    else
    {
        int size = n%5==0?n/5:n/5+1;
        for(int i = 0;i<size-1;i++)
        {
            sort(v.begin()+i*5,v.begin()+(i+1)*5);
        }
        sort(v.begin()+5*(size-1),v.end());
        vector<int>temp;

        for(int i = 2;i<(n/5)*5;i+=5)
        {
            temp.push_back(v.at(i));
        }
        if(n%5!=0)
        {
            temp.push_back(v.at(((n/5)*5+n)/2));
        }
    }
}