#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;




void solve(){
    int n; cin >> n;
    vector<int> b(n);
    for(auto &e:b){
        cin >> e;
    }
    int ans=0;
    /*vector<int> pr;
    for(int i=0;i<n;i++){
        pr.push_back(b[i]-i);
    }
    vector<int> pl;
    for(int i=0;i<n;i++){
        pr.push_back(b[i]+i);
    }*/
    multiset<int> l;
    l.insert(b[0]);
    multiset<int> r;
    for(int i=2;i<n;i++){
        r.insert(b[i]-i);
    }

    for(int i=1;i<n-1;i++){
        /*for(auto e:r){
            cout << e << " ";
        }
        cout << '\n';*/
        ans = max(ans, b[i]+*r.rbegin()+*l.rbegin());
        r.erase(r.find(b[i+1]-i-1));
        l.insert(b[i]+i);
    }
    cout << ans << '\n';


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	//ifstream fin("meetings.in");
	//ofstream fout("meetings.out");
    int t; cin >> t;
    while(t--){
        solve();
    }

}