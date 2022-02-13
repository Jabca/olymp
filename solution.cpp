#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void config_io()
{
    cin.tie(NULL);
    cout.tie(NULL);
    cout.sync_with_stdio(false);
#ifdef _deb
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
}

void print_pair(pair<int, int> p)
{
    cout << '{' << p.first << "; " << p.second << "}\n";
}

void solve()
{
    int n;
    cin >> n;
    int health[n];
    int time[n];
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> health[i];
    }

    vector<pair<int, int>> v;
    int t;
    for (int i = 0; i < n; i++)
    {
        t = time[i] - health[i];
        if (time[i] - t > 1)
        {
            v[i + 1] = {t, time[i]};
        }
    }
    for (auto z : v)
    {
        print_pair(z);
    }

    ll mana = 0;
    int l;
    int len = v.size() + 1;
    pair<int, int> tmp;
    int cur_left, z, min_left;

    while (len != 0)
    {
        tmp = v[len];
        cur_left = tmp.first;
        min_left = cur_left;
        while (v[len].second > cur_left)
        {
            if (v[len].first < min_left)
            {
                min_left = v[len].first;
            }
            len--;
        }
        l = tmp.second - min_left;
        cout << l << '\n';
        mana += l * (l + 1) / 2;
        mana += min_left - v[len].second;
    }
    cout << mana - min_left << '\n';
}

int main()
{
    config_io();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}