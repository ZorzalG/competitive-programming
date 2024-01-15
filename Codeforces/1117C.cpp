#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int x,y; cin >> x >> y;
    long long int x1,y1; cin >> x1 >> y1;
    int c; cin >> c;
    string s;
    cin >> s;
    vector<long long int> prefx(c+1);
    vector<long long int> prefy(c+1);
    for(int i=1;i<=c;i++){
        if(s[i-1]=='U'){
            prefy[i]=1;
        }
        if(s[i-1]=='D'){
            prefy[i]=-1;
        }
        if(s[i-1]=='R'){
            prefx[i]=1;
        }
        if(s[i-1]=='L'){
            prefx[i]=-1;
        }
    }
    /*
    for(auto e:prefy){
        cout << e << " ";
    }*/
    for(int i=2;i<=c;i++){
        prefx[i]=prefx[i-1]+prefx[i];
        prefy[i]=prefy[i-1]+prefy[i];
    }
    /*for(auto e:prefy){
        cout << e << " ";
    }*/
    
    long long int pos=0;
    long long int maxi=1000000000000000000;
    
    for(long long int a=maxi; a>0; a/=2){
        //cout << pos << " " << a << " ";
        
        while(abs(x1-x-prefx[c]*((pos+a)/c)-prefx[(pos+a)%c]) + abs(y1-y-prefy[c]*((pos+a)/c)-prefy[(pos+a)%c]) > pos+a){
            pos=pos+a;
            if(pos > maxi){
                break;
            }
        }
    }
    if(pos > maxi){
        cout << -1;
    }
    else{
        cout << pos+1;
    }

}