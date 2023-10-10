#include<iostream>
#include <list>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    list<int> adjList[n+1];
    for(int i = 0;i<=n;i++)
    {
        cout<<"Enter nodes for "<<i<<" ending with -1"<<endl;
        int input;
        cin>>input;
        while(input!=-1)
        {
            adjList[i].push_back(input);
            cin>>input;
        }
    }

    vector<int>vis(n+1,-1);
    queue<int>q;
    q.push(0);
    vis[0]=1;

    while(!q.empty())
    {
        int ele = q.front();
        q.pop();

        for(auto it:adjList[ele])
        {
            if(vis[it]==-1)
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }


    for(int i = 0;i<=n;i++)
    {
        cout<<vis[i]<<" ";
    }

}