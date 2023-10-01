#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<climits>
using namespace std;

void printList(vector<pair<int, int>>vec)
{
    for(auto it:vec)
    {
        cout<<"("<<it.first<<" "<<it.second<<")"<<" ";
    }
    cout<<endl;
}
int distance(pair<int, int> p1, pair<int, int> p2)
{
    return int(sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)));
}
bool compare(pair<int, int> it1, pair<int, int> it2)
{
    return (it1.second <= it2.second);
}
int closestPair(vector<pair<int, int>> Px, vector<pair<int, int>> Py)
{
    if (Px.size() <= 3)
    {
        int dist = INT_MAX;
        for(int i = 0;i<Px.size();i++)
        {
            for(int j = i+1;j<Px.size();j++)
            {
                dist = min(dist,distance(Px.at(i),Px.at(j)));
            }
        }

        return dist;
    }
    vector<pair<int, int>> Qx;
    vector<pair<int, int>> Qy;
    vector<pair<int, int>> Rx;
    vector<pair<int, int>> Ry;
    pair<int, int> mid = Px.at((0+Px.size()-1) / 2);
    cout<<"mid "<<mid.first<<" "<<mid.second<<endl;
    for (auto it : Px)
    {
        if (it.first <= mid.first)
        {
            Qx.push_back(it);
        }
        else if (it.first > mid.first)
        {
            Rx.push_back(it);
        }
    }
    for (auto it : Py)
    {
        if (it.first <= mid.first)
        {
            Qy.push_back(it);
        }
        else if (it.first > mid.first)
        {
            Ry.push_back(it);
        }
    }
    // printList(Qx);
    // printList(Qy);
    // printList(Rx);
    // printList(Ry);

    int d = INT_MAX;


    if(Qx.size()>0 && Qy.size()>0 && Rx.size()>0 && Ry.size()>0)
    {
    int dl = INT_MAX;
    int dr = INT_MAX;

    dl = closestPair(Qx, Qy);
    dr = closestPair(Rx, Ry);

    d = min(dl, dr);
    }
    
    vector<pair<int, int>> Sy;
    for (auto it : Py)
    {
        if (it.first >= mid.first - d && it.first <= mid.first + d)
            Sy.push_back(it);
    }


    for (int i = 0; i < Sy.size(); i++)
    {
        int j = i+1;
        int count = 0;
        while(j<Sy.size() && count<7)
        {
            d=min(d,distance(Sy.at(i),Sy.at(j)));
            count++;

        }
    }

    return d;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> Px;
    vector<pair<int, int>> Py;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        Px.push_back({a, b});
        Py.push_back({a, b});
    }
    sort(Px.begin(), Px.end());
    sort(Py.begin(), Py.end(), compare);

    cout << closestPair(Px, Py);
}