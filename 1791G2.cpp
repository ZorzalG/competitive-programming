#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void solve(){
    //cout << "x\n";
    long long int n, c; cin >> n >> c;
    vector<pair<long long int,long long int>> cost;
    vector<long long int> bkw;
    for(long long int i=1;i<=n;i++){
        long long int a; cin >> a;
        cost.push_back({min(a+i , n+1+a-i) , a+i});
        
    }
    sort(cost.begin(),cost.end());
    vector<long long int> pf;
    pf.push_back(0);
    for(long long int i=0;i<n;i++){
        //dbg(i);
        pf.push_back(pf[i] + cost[i].first);
    }

    long long int ans=0;
    for(long long int i=0;i<n;i++){
        
        long long int tm=c-cost[i].second;
        long long int l=0;
        long long int r=n;
        long long int maxi=0;
        while(l <= r)
        {
            long long int mid = l+r>>1;
            //programming is the most fucking miserable experience of my entire fucking life
            //every goddamn second i am in front of an IDE makes me want to smash a window
            //after i promote to usaco gold i will never touch programming again
            long long int price = pf[mid];
            long long int now = mid+1;
            if(mid > i)
            {
                price-=cost[i].first;
                now--;
            }
            if(price <= tm)
            {
                maxi = max(now, maxi);
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        ans = max(ans, maxi);

    }
    cout << ans << "\n";


    
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long int t; cin >> t;
    while(t--){
        solve();
    }

    

}