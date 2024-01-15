#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> mini(n+1);
    mini[0]=0;
    for(int i=1;i<=n;i++){
        cin >> mini[i];
    }
    for(int i=1;i<=n;i++){
        if(mini[i]-mini[i-1]>15){
            cout << mini[i-1]+15;
            return 0;
        }
    }
    int limit=90;
    cout << min(limit,mini.back()+15);
    

}