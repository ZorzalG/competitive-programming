#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define int long long


int n,m;

vector<int> adj[200001];
bool visited[200001]={};

vector<int> cats(200001);

void dfs(int c, int cat){
    if(visited[c]){
        return;
    }
    if(cats[c]==1){
        cat++;
    }
    else{
        cat=0;
    }
    if(cat>m){
        return;
    }
    visited[c]=true;
    
    for(auto e:adj[c]){
        dfs(e,cat);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> cats[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> leaves;
    for(int i=2;i<=n;i++){
        if(adj[i].size()==1){
            leaves.insert(i);
        }
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            //cout << i << " ";
            if(leaves.count(i)){
                ans++;
            }
        }
        
    }
    cout << ans;


    


    

}