#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;




void solve(){
    int n; cin >> n;
    vector<pair<long long int,long long int>> cows;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        cows.push_back({a,i+1});
    }
    sort(cows.begin(),cows.end());
    long long int ans=0;
    for(int i=0;i<n;i++){
        ans+=(i+1)*cows[i].first;
    }
    vector<int> ind(n+1);
    for(int i=0;i<n;i++){
        ind[cows[i].second]=i;
    }
    vector<long long int> p(1);
    for(auto e:cows){
        p.push_back(p.back() + e.first);
    }
    vector<long long int> co;
    for(auto e:cows){
        co.push_back(e.first);
    }
    co.push_back(200000000);
    /*for(auto e:co){
        cout << e << " ";
    }*/
    //dbg(ans);
    int q; cin >> q;
    for(int k=0;k<q;k++){
        long long int i,j; cin >> i >> j;
        auto it = upper_bound(co.begin(),co.end(), j);
        //it= it-co.begin();

        int buf=0;
        if(co[ind[i]]<=j){
            buf+=1;
        }

        //cout << it - co.begin() << '\n';

        long long int temp = p[ind[i]+buf] - p[it-co.begin()];
        
        cout << ans + temp - co[ind[i]]*(ind[i]+1) + j*(it-co.begin()+1-buf) << "\n";


    }


    
    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	//ifstream fin("meetings.in");
	//ofstream fout("meetings.out");
    //int t; cin >> t;
    //while(t--){
    solve();
    //}

}