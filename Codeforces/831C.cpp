#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,n; cin >> k >> n;
    vector<int> jury(k);
    vector<int> pf(1);
    for(auto &e:jury){
        cin >> e;
        pf.push_back(pf.back()+e);
    }
    vector<int> scores(n);
    for(auto &e:scores){
        cin >> e;
    }
    int ans=0;
    set<int> vals;
    for(int j=1;j<=k;j++){
        vals.insert(scores[0]-pf[j]);
    }

    
    for(auto e:vals){
        set<int> points;
        for(int i=1;i<=k;i++){
            points.insert(e+pf[i]);
        }
        bool check=true;
        for(auto p:scores){
            if(!points.count(p)){   
                check=false;
            }
        }
        if(check){
            ans++;
        }
    }
    cout << ans;



    

}