#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
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

vector<int> zf(const vector<int>& s, vector<int>& z){
    int n = z.size();
    z[0] = n;
    int l = 0;
    int r = 0;

    for(int i = 1; i < n; i++){
        if(i <= r){
            z[i] = min(r-i+1, z[i-l]);
        }
        
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
 
    }
    return z;
}

vector<int> pf(vector<int>& s, vector<int>& p){
    int n = s.size();
    int k;
    for(int i = 1; i < n; i++){
        k = p[i-1];
        while (k > 0 && s[i] != s[k]){
            k = p[k - 1];
        }
        if(s[i] == s[k]){
            k++;
        }
        p[i] = k;

    }
    return p;
}