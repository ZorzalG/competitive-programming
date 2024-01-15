#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("sort.in");
    //ofstream fout("sort.out");
    int n; cin >> n;
    string s; cin >> s;
    set<int> seen;
    for(int i=0;i<n;i++){
        seen.insert(s[i]);
    }
    int si=seen.size();
    int ans=100001;
    multiset<int> cs;
    seen.clear();
    int l=0;
    int r=0;
    while(l<n){
        while(seen.size()<si && r<n){
            seen.insert(s[r]);
            cs.insert(s[r]);
            r++;
        }
        int sie=cs.size();
        if(seen.size()==si){
            ans=min(ans, sie);
            //cout << l << " " << r << "\n";
        }
        cs.erase(cs.find(s[l]));
        if(cs.count(s[l]) == 0){
            seen.erase(s[l]);
        }
        l++;
        
    }
    cout << ans;


    

}