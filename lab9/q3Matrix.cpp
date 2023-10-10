#include<iostream>
#include <list>
#include<queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int **adjMatrix = new int*[n+1];
    for(int i = 0;i<=n;i++)
    {
        adjMatrix[i]= new int[n+1];
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j =0;j<=n;j++)
        {
            cin>>adjMatrix[i][j];
        }
    }

    queue<int>q;
    q.push(0);
    vector<int>vis(n+1,-1);
    vis[0]=1;
    while(!q.empty())
    {
        int ele = q.front();
        q.pop();
        for(int i = 0;i<=n;i++)
        {
            int edge = adjMatrix[ele][i];
            if(vis[i]==-1 && edge==1)
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }

    for(int i = 0;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            cout<<"Not connected";
            break;
        }
    }


}