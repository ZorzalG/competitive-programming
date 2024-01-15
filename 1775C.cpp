#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define int long long


void solve(){
    int n,x; cin >> n >> x;
    //dbg(n);
    //dbg(x);
    int tn=n;
    int cn = n;
    int largestbit = 0;
    while(tn>0){
        tn/=2;
        largestbit++;
    }
    largestbit--;
    int anothert =1;
    for(int i=0;i<largestbit;i++){
        anothert*=2;
    }
    //cout << anothert << "x\n";
    if(((n&x) <anothert && x!=0) || n < x){
        cout << -1 << "\n";
        return;
    }
    while(n!=x){
        //find next
        int anding =1;
        while((anding&cn) == 0){
            anding*=2;
        }
        //cout << anding << "\n";
        //cn-=anding;
        cn+=anding;
        n=n&cn;
        if((n&x)==0 && x!=0){
            cout << -1 << "\n";
            return;
        }
        //cout << cn << " " << n << "\n";
    }
    cout << cn << "\n";
    //dbg(cn);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }    


    

}