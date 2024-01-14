#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

set<int> mods[4];


void sieve(){
    bool prime[5000001]={};
    for(int i=2;i<=5000000;i++){
        if(!prime[i]){
            for(int j=2*i;j<=5000000;j+=i){
                prime[j]=true;
            }
        }
    }
    for(int i=2;i<=5000000;i++){
        if(!prime[i]){
            if(i%4==1){
                mods[1].insert(i);
            }
            if(i%4==2){
                mods[2].insert(i);

            }
            if(i%4==3){
                mods[3].insert(i);

            }
        }
    }
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> steps;
    for(auto &e:a){
        cin >> e;
    }
    for(auto e:a){
        int mult = e%4==0 ? -1 : 1;
        int cnt=0;
        if(e<4){
            cnt=1;
        }
        else if(e%2==0){
            cnt = e/2;
        }
        else{
            auto it = mods[e%4].lower_bound(e);
            if(*it>e){
                it--;
            }
            cnt = (e-*it)/2+1;
        }
        
        steps.push_back(cnt*mult);
    }

    int mini=5000001;
    for(auto e:steps){
        mini=min(mini,abs(e));
        //cout << e << " ";
    }
    //cout << mini;
    for(auto &e:steps){
        if(abs(e)/2==mini/2){
            if(e<0){
                cout << "Farmer Nhoj";
            }
            else{
                cout << "Farmer John";
            }
            cout << "\n";
            return;
        }
    }

    //cout << '\n';


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
	//ifstream fin("meetings.in");
	//ofstream fout("meetings.out");
    int t; cin >> t;
    while(t--){
        solve();
    }


}