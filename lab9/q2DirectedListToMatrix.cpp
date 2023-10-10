#include<iostream>
#include <list>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    list<int> adjList[n+1];
    int **adjMatrix = new int*[n+1];
    for(int i = 0;i<=n;i++)
    {
        adjMatrix[i]= new int[n+1];
    }
    for(int i = 0;i<=n;i++)
    {
        cout<<"Enter nodes for "<<i<<" ending with -1"<<endl;
        int input;
        cin>>input;
        while(input!=-1)
        {
            adjList[i].push_back(input);
            adjMatrix[i][input]=1;
            cin>>input;
        }
    }

    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

}