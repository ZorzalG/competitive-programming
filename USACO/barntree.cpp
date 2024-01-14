#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


vector<int> adj[200001];
vector<long long int> h;
vector<long long int> subtreesums;


vector<pair<pair<int,int>,long long int>> ops;




bool visited[200001]={};
void ssum(int c, int p){
    /*if(visited[c]){
        return;
    }
    visited[c]=true;*/
    //if leaf return value
    /*
    if(adj[c].size()==1 && c!=1){
        subtreesums[c] = h[c-1];
        return h[c-1];
    }
    //else return sum of children
   
    else{
        long long int temp=h[c-1];
        for(auto &e:adj[c]){
            if(e!=p){
                temp+=ssum(e,c);
            }
        }
        subtreesums[c]=temp;
        return temp;
    }*/
    subtreesums[c]=h[c-1];
    for(auto &e:adj[c]){
        if(e!=p){
            ssum(e,c);
            subtreesums[c]+=subtreesums[e];
        }
    }
   


}


void dfs(int c, int p){
    /*if(visited[c]){
        return;
    }
    //if leaf move up
    if(adj[c].size()==1 && c!=1){
        if(h[c-1]>0){
            // source , destination, #
            ops.push_back({{c,p},h[c-1]});
        }
        else if(h[c-1]<0){
            ops.push_back({{p,c},-1*h[c-1]});
        }
        return;
    }


    visited[c]=true;
    for(auto &e:adj[c]){
        if(subtreesums[e]>=0){
            //you need to move haybales from here
            dfs(e,c);
        }
    }
    //done getting everything up
    //move from here to down if necessary
    for(auto &e:adj[c]){
        if(subtreesums[e]<0){
            //you need to move haybales to there
            ops.push_back({{c,e},-1*subtreesums[e]});
            dfs(e,c);
        }
    }
    //move up
    if(subtreesums[c]>0){
        ops.push_back({{c,p},subtreesums[c]});
    }*/
    
    for(auto &e:adj[c]){
        if(e!=p){
            if(subtreesums[e] >= 0){
                dfs(e,c);
            }
            if(subtreesums[e]>0){
                ops.push_back({{e,c},subtreesums[e]});
            }
        }
        
        
    }
    for(auto &e:adj[c]){
        if(e!=p && subtreesums[e]<0){
            ops.push_back({{c,e},-1*subtreesums[e]});
            dfs(e,c);
        }
    }
    
    

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ifstream fin("meetings.in");
	ofstream fout("meetings.out");
    int n; cin >> n;
    h.resize(n);
    long long int weights=0;
    for(auto &e : h){
        cin >> e;
        weights+=e;
    }
    weights/=n;
    for(auto &e:h){
        e-=weights;
    }
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    subtreesums.resize(n+1);
    ssum(1,1);
    dfs(1,1);
    cout << ops.size() << '\n';
    for(auto e:ops){
        cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
    }
	/*cout << ssum(1,1);
    for(auto e:subtreesums){
        cout << e;
    }
    */


}