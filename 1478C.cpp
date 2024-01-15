#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long int n; cin >> n;
    vector<long long int> d;
    for(int i=0;i<2*n;i++){
        long long int a; cin >> a;
        d.push_back(a);
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    bool check = true;
    set<long long int> a;
    long long int r=0;
    for(long long int i=0;i<2*n;i+=2){
        long long int t = (d[i]-r)/(2*n-i);
        if(d[i]!=d[i+1] || (d[i]-r)%(2*n-i) != 0 || (d[i]-r) <= 0 || a.count(t)){
            check=false;
        }
        a.insert(t);
        r+= 2*t;
    }
    //for(auto e:a){
    //   cout << e << " ";
    //}
    if(check){
        cout << "yes" << "\n";

    }
    else{
        cout << "no" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}