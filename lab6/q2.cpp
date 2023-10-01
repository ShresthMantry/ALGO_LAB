#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int select(vector<int> v, int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    if (n <= 2)
    {
        return v.at(n - 1);
    }
    int median = -1;
    if (n <= 5)
    {
        sort(v.begin(), v.end());
        median = v.at(n / 2);
    }
    else
    {
        int size = n % 5 == 0 ? n / 5 : n / 5 + 1;
        for (int i = 0; i < size - 1; i++)
        {
            sort(v.begin() + i * 5, v.begin() + i * 5 + 5);
        }
        sort(v.begin() + 5 * (size - 1), v.end());
        vector<int> temp;
        for (int i = 2; i < (n / 5) * 5; i += 5)
        {
            temp.push_back(v.at(i));
        }
        if (n % 5 != 0)
            temp.push_back(v.at(((n / 5) * 5 + n) / 2));
        median = select(temp, size, size / 2);
    }

    vector<int> a1;
    int c1 = 0, c2 = 0;
    vector<int> a2;
    for (auto it : v)
    {
        if (it >= median)
        {
            a2.push_back(it);
            c2++;
        }
        else
        {
            a1.push_back(it);
            c1++;
        }
    }
    if (k == c1)
    {
        return median;
    }
    else if (k < c1)
    {
        return select(a1, c1, k);
    }
    return select(a2, c2, k - c1);
}

int main()
{
    int k;
    cin >> k;

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int ans = select(v, n, k - 1);
    cout << ans;
}
