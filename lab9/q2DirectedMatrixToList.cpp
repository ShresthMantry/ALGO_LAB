#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int **adjMatrix = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        adjMatrix[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    list<int> adjList[n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << "Node " << i << "-> ";
        for (auto it : adjList[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}