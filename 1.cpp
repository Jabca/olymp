#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

vector<int> zf(string& s, vector<int>& z){
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

vector<int> manacher_even(vector<int>& q) {
    int n = q.size();
    vector<int> s;
    s.push_back(-1);
    for(int i = 1; i <= n; i++){
        s.push_back(q[i-1]);
        s.push_back(i * -1); 
    }
    
    vector<int> p(s.size());
    for(int i = 1; i <= n; i++) {
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
    }
    vector<int> ans = vector<int>(begin(p) + 1, end(p) - 1);
    return vector<int>(begin(ans) + 1, end(ans) - 1);

}

int main()
{
    config_io();
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<int> ans = manacher_even(s);
    for(auto x: ans){
        cout << x << ' ';
    }
}