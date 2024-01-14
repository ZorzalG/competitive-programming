#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	//ifstream fin("meetings.in");
	//ofstream fout("meetings.out");
    vector<int> pc[3];
    pc[0].push_back(0);
    pc[1].push_back(0);
    pc[2].push_back(0);

    string s; cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='C'){
            for(int j=0;j<3;j++){
                pc[j].push_back(pc[j].back());
            }
            pc[0].back()+=1;
        }
        else if(s[i]=='O'){
            for(int j=0;j<3;j++){
                pc[j].push_back(pc[j].back());
            }
            pc[1].back()+=1;
        }
        else{
            for(int j=0;j<3;j++){
                pc[j].push_back(pc[j].back());
            }
            pc[2].back()+=1;
        }
    }
    
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int l,r; cin >> l >> r;
        int cparity = (pc[0][r]-pc[0][l-1]) % 2;
        int oparity = (pc[1][r]-pc[1][l-1]) % 2;
        int wparity = (pc[2][r]-pc[2][l-1]) % 2;

        if(cparity == 1){
            if(oparity ==0 && wparity == 0){
                cout << 'Y';
                continue;
            }
        }
        else{
            if(oparity ==1 && wparity == 1){
                cout << 'Y';
                continue;
            }
        }

        cout << 'N';
    }



}