#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;



void solve(){
    int q; cin >> q;
    string ans="";
    bool decrease=false;
    
    int starter=-1;
    int prev=-1;
    for(int i=0;i<q;i++){
        int decision = 0;
        int a; cin >> a;
        if(starter==-1){
            starter=a;
        }
        if(a<prev){
            
            if(decrease==false){
                //still possible
                if(a>starter){
                    //no, final decision
                    decision = 2;
                }
                else{
                    decision = 1;
                    decrease = true;
                }

            }
            else{
                //no, final decision
                decision = 2;
            }
        }
        //dbg(ans);
        //dbg(decision);
        if(decision == 1){
            prev = a;
            ans+='1';
            continue;
        }
        else if(decision==2){
            ans+='0';
            continue;
        }

        if(decrease==true){
            if(a>starter){
                //no, final decision
                decision = 2;
            }
            else{
                //yes, final
                decision = 1;
            }
        }
        
        if(decision == 1){
            prev = a;
            ans+='1';
            continue;
        }
        else if(decision==2){
            ans+='0';
            continue;
        }

        //finally, if it hasnt decreased yet, and the number isnt lower

        prev=a;
        ans+='1';




    }
    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t; cin >> t;
    while(t--){
        solve();
    }
}
 