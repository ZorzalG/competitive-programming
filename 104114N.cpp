#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;




void solve(){
    int n,m; cin >> n >> m;
    vector<int> s(n);
    for(auto &e:s){
        cin >> e;
    }
    /*
    vector<int> p(n);
    vector<bool> ppal(n);

    for(int i=0;i<n-1;i++){
        //check next
        //if the next forces you to jump up then you also need to pull up everything before you
        //if you go down here but then the next one needs to go up and pull you as well
        if(s[i+1] - s[i] > m){
            p[i]=s[i+1] - s[i] - m;
            ppal[i]=true;
        }
        else if(s[i]-s[i+1]>m){
            p[i]=0;
            ppal[i]=false;
        }
    }



    for(int i=0;i<n;i++){
        cout << s[i]+p[i] << " ";
    }
    //do the same thing in reverse
    vector<int> preverse(n);

    for(int i=0;i<n-1;i++){
        //check next
        if(s[i+1] - s[i] > m){
            p[i]=s[i+1] - s[i] - m;
            ppal[i]=true;
        }
        else if(s[i]-s[i+1]>m){
            p[i]=0;
            ppal[i]=false;
        }
    }*/
    //value, index
    pair<int,int> thebig = {0,0};
    for(int i=0;i<n;i++){
        if(s[i]>thebig.first){
            thebig = {s[i],i};
        }
    }

    //going right
    for(int i=thebig.second;i<n-1;i++){
        //check next

        if(s[i]-s[i+1] > m){ // im too big
            s[i+1]+=(s[i]-s[i+1]-m);
        }
    }
    
    for(int i=n-1;i>thebig.second;i--){
        //check next

        if(s[i]-s[i-1] > m){ // im too big
            s[i-1]+=(s[i]-s[i-1]-m);
        }
    }

    //going left
    for(int i=thebig.second;i>0;i--){
        //check next

        if(s[i]-s[i-1] > m){ // im too big
            s[i-1]+=(s[i]-s[i-1]-m);
        }
    }
    
    for(int i=0;i<thebig.second;i++){
        //check next

        if(s[i]-s[i+1] > m){ // im too big
            s[i+1]+=(s[i]-s[i+1]-m);
        }
    }

    for(auto e:s){
        cout << e << " ";
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