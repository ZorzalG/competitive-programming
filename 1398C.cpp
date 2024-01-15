#include <bits/stdc++.h>
using namespace std;


void solve(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    long long int total=0;
    vector<int> si;
    vector<int> p1;
    map<int,long long int> o;
    string s; cin >> s;
    for(int i=0;i<n;i++){
        si.push_back(s[i]-'0');
    }
    p1.push_back(0);
    for(int i=0;i<n;i++){
        p1.push_back(p1[i]+si[i]);
    }
    for(int i=0;i<=n;i++){
        p1[i]=p1[i]-i;
        o[p1[i]]++;
    }
    for(auto e: p1){
        total+=(o[e] * (o[e]-1) / 2);
        o[e]=0;
    }
    cout << total << "\n";
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}