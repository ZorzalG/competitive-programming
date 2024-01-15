#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;




void solve(){
    string s; cin >> s;
    int q; cin >> q;
    map<int,vector<int>> countsp;
    for(int i='a';i<='z';i++){
        countsp[i].push_back(0);
    }
    for(int i=0;i<s.length();i++){
        int tmp=s[i];
        for(int j='a';j<='z';j++){
            countsp[j].push_back(countsp[j].back() + 0);
        }
        countsp[tmp].pop_back();
        countsp[tmp].push_back(countsp[tmp].back() + 1);
    }

    for(int i=0;i<q;i++){
        bool ans = false;
        int l,r; cin >> l >> r;
        if(r-l == 0){
            ans = true;
        }
        else if(s[l-1] != s[r-1]){
            ans = true;
        }
        else{
            int cnt=0;
            for(int j='a';j<='z';j++){
                //cout << (char)j << " " << (countsp[j][r] - countsp[j][l-1]) << "\n";
                cnt += ((countsp[j][r] - countsp[j][l-1])>0);
            }
            if(cnt>2){
                ans=true;
            }
        }

        if(ans){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << '\n';
        }

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