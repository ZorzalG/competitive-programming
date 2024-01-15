// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
bool visited[200001] = {};
vector<int> tracker[2];
void dfs(int c, int cnt){
	if(visited[c]){
		return;
	}
	visited[c]=true;
	tracker[cnt%2].push_back(c);
	for(auto e:adj[c]){
		dfs(e,cnt+1);
	}
}


void solve(){
	int n,m; cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	if(tracker[0].size() < tracker[1].size()){
		cout << tracker[0].size() << '\n';
		for(auto e:tracker[0]){
			cout << e << " ";
		}
		cout << '\n';
	}
	else{
		cout << tracker[1].size() << '\n';
		for(auto e:tracker[1]){
			cout << e << " ";
		}
		cout << '\n';
	}
	for(int i=1;i<=n;i++){
		assert(visited[i]==true);
	}

	for(int i=0;i<=n;i++){
		adj[i].clear();
	}
	for(int i=0;i<=n;i++){
		visited[i]=false;
	}
	tracker[0].clear();
	tracker[1].clear();



}


int main() {
	int t; cin >> t;
	while(t--){
		solve();
	}

}
