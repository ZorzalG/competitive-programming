#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("sort.in");
    //ofstream fout("sort.out");
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int m; cin >> m;
        char c; cin >> c;

        int l=0;
        int r=0;
        int ans=0;
        int tmp=0;
        while(l<n && r<n){
            while(r<n){
                if(s[r]!=c){
                    tmp++;
                }
                //youve gone too far!
                if(tmp>m){
                    tmp--;
                    break;
                    //cout << r << "\n";
                }
                r++;
            }
            
            
            //cout << r << " " << l << "\n";
            ans=max(ans, r-l);
            
            if(s[l]!=c){
                tmp--;
            }
            l++;
            
        }
        cout << ans << "\n";








    }


    

}