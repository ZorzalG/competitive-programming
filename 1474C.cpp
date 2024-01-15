#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    multiset<int> s;
    for(int i=0;i<2*n;i++){
        int a; cin >> a;
        s.insert(a);
    }
    multiset<int> dupe = s;
    int maxi = *dupe.rbegin();
    int x = maxi;
    bool check=false;
    int finalans=0;
    //s.erase(s.find(maxi));
    int cnter=0;
    for(auto e:s){
        cnter++;
        if(cnter==s.size()){
            break;
        }
        //cout << e << " ";
        dupe = s;
        dupe.erase(dupe.find(e));
        dupe.erase(dupe.find(maxi));
        x=maxi;
        //cout << maxi << "\n";
        while(!dupe.empty()){
            int newe=x-*dupe.rbegin();
            if(dupe.find(newe) == prev(dupe.end())){
                break;
            }
            if(dupe.count(newe)==0){
                break;
            }
            x=*dupe.rbegin();
            dupe.erase(dupe.find(*dupe.rbegin()));
            dupe.erase(dupe.find(newe));
        }
        if(dupe.empty()){
            check=true;
            finalans=*s.rbegin()+e;
            break;
        }

    }
    if(check){
        cout << "YES\n" << finalans << "\n";
        dupe=s;
        while(!dupe.empty()){
            //cout << dupe.size() << "s\n";
            cout << *dupe.rbegin() << " " << finalans-*dupe.rbegin() << "\n";
            dupe.erase(dupe.find(finalans-*dupe.rbegin()));
            finalans=*dupe.rbegin();
            dupe.erase(dupe.find(*dupe.rbegin()));
            
        }
        //cout << "\n";
    }
    else{
        cout << "NO\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("swap.in");
    //ofstream fout("swap.out");
    int t; cin >> t;
    while(t--){
        solve();
    }
    

}