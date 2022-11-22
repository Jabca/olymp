#include <iostream>
#include <bits/stdc++.h>
// typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
const int b = 29;

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


vector<int> init_p(int l){
    vector<int> p(l + 1);
    p[0] = 1;
    for(int i = 1; i < 1 + l; i++){
        p[i] = 1ll * p[i-1] * b % mod;
    }
    return p;
}



vector<int> init_h(string s){
    int n = s.size();
    vector<int> h(n+1);
    h[0] = 0;
    for(int i = 1; i < n + 1; i++){
        h[i] = (h[i-1] * b + (s[i-1] - 'a' + 1)) % mod;
    }
    return h;
}

int get(int l, int r,  const vector<int>& h,  const vector<int>& p){
    return (h[r] - 1ll * h[l-1] * p[r - l + 1] % mod + mod) % mod;
}




int main(){
    config_io();
    string s;
    cin >> s;

    vector<int> p = init_p(s.size());
    vector<int> h = init_h(s);

    int m;
    cin >> m;
    int a, b, c, d;

    for(int _ = 0; _ < m; _++){
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if(get(a, b, h, p) == get(c, d , h, p)){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }

}