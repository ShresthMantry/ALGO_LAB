#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

void printList(vector<pair<int, int>> vec)
{
    for (auto it : vec)
    {
        cout << "(" << it.first << " " << it.second << ")"
             << " ";
    }
    cout << endl;
}
int distance(pair<int, int> p1, pair<int, int> p2)
{
    return int(sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)));
}
bool compare(pair<int, int> it1, pair<int, int> it2)
{
    return (it1.second <= it2.second);
}
pair<pair<int, int>, pair<int, int>> closestPair(vector<pair<int, int>> Px, vector<pair<int, int>> Py)
{
    if (Px.size() <= 3)
    {
        pair<pair<int, int>, pair<int, int>> ans;
        int dist = INT_MAX;
        for (int i = 0; i < Px.size(); i++)
        {
            for (int j = i + 1; j < Px.size(); j++)
            {
                int d = distance(Px.at(i), Px.at(j));
                if (d < dist)
                {
                    dist = d;
                    ans.first = Px.at(i);
                    ans.second = Px.at(j);
                }
            }
        }

        return ans;
    }
    vector<pair<int, int>> Qx;
    vector<pair<int, int>> Qy;
    vector<pair<int, int>> Rx;
    vector<pair<int, int>> Ry;
    pair<int, int> mid = Px.at((0 + Px.size() - 1) / 2);
    // cout << "mid " << mid.first << " " << mid.second << endl;
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

    pair<pair<int, int>, pair<int, int>> ans;
    if (Qx.size() > 0 && Qy.size() > 0 && Rx.size() > 0 && Ry.size() > 0)
    {
        pair<pair<int, int>, pair<int, int>> dl = closestPair(Qx, Qy);
        pair<pair<int, int>, pair<int, int>> dr = closestPair(Rx, Ry);

        if (distance(dl.first, dl.second) <= distance(dr.first, dr.second))
        {
            ans = dl;
        }
        else
            ans = dr;

        d = distance(ans.first, ans.second);
    }

    vector<pair<int, int>> Sy;
    for (auto it : Py)
    {
        if (it.first >= mid.first - d && it.first <= mid.first + d)
            Sy.push_back(it);
    }

    int dist = INT_MAX;

    for (int i = 0; i < Sy.size(); i++)
    {
        int j = i + 1;
        int count = 0;
        while (j < Sy.size() && count < 7)
        {
            d = distance(Sy.at(i), Sy.at(j));
            if (d < dist)
            {
                dist = d;
                ans.first = Sy.at(i);
                ans.second = Sy.at(j);
            }
            count++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> Px;
    vector<pair<int, int>> Py;
    vector<pair<int, int>> Zx;
    vector<pair<int, int>> Zy;
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

    pair<pair<int, int>, pair<int, int>> ans = closestPair(Px, Py);
    cout << "(" << ans.first.first << " " << ans.first.second << ") "
         << "(" << ans.second.first << " " << ans.second.second << ")"<<endl;

    for(auto it:Px)
    {
        if(it.first==ans.first.first && it.second==ans.first.second)
        {
            continue;
        }
        Zx.push_back(it);
    }

    for(auto it:Py)
    {
        if(it.first==ans.first.first && it.second==ans.first.second)
        {
            continue;
        }
        Zy.push_back(it);
    }



    pair<pair<int, int>, pair<int, int>> ans1 = closestPair(Zx,Zy);
    Zx.clear();
    Zy.clear();

    for(auto it:Px)
    {
        if(it.first==ans.second.first && it.second==ans.second.second)
        {
            continue;   
        }
        Zx.push_back(it);
    }

    for(auto it:Py)
    {
        if(it.first==ans.second.first && it.second==ans.second.second)
        {
            continue;
        }
        Zy.push_back(it);
    }

    pair<pair<int, int>, pair<int, int>> ans2 = closestPair(Zx,Zy);
    

    if(distance(ans1.first,ans1.second) <= distance(ans2.first,ans2.second))
    {
        cout << "(" << ans1.first.first << " " << ans1.first.second << ") "
         << "(" << ans1.second.first << " " << ans1.second.second << ")"<<endl;
    }
    else
    {
        cout << "(" << ans2.first.first << " " << ans2.first.second << ") "
         << "(" << ans2.second.first << " " << ans2.second.second << ")"<<endl;
    }
    
}