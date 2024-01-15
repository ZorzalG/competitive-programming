#include <bits/stdc++.h>
 
using namespace std;
 
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n>4){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
	
}