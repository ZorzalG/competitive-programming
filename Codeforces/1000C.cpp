#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    map<long long int,long long int> c;
    for(int i=0;i<n;i++){
        long long int a,b; cin >> a >> b;
        c[a]++;
        c[b+1]--;
    }
    // (0,1) (1,1) (3,1) (4,-2) (8,-1)
    
    vector<long long int> ans(n+1);
    long long int cur=0;
    long long int prev= c.begin()->first;
    
    for(auto e: c){
        //cout << e.first << " " << e.second << "\n";
        ans[cur]+=e.first-prev;
        cur+=e.second;
        prev=e.first;

        //cout << e.second << " ";

    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
}
