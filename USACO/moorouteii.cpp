#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

//adj[i] will store every flight that departs it
//flights are stored as: starting time, destination, ending time
//flights get removed right after you take them 

set<pair<int,pair<int,int>>> adj[200001];
vector<int> layover(200001);
vector<int> ans(200001);

//idfk lol: node, time
map<int,set<int>> visited;

void dfs(int c , int t){
	if(visited[c].count(t)){
		return;
	}
	visited[c].insert(t);
	ans[c]=min(t,ans[c]);
	if(c!=1 || t!=0){
		t+=layover[c];
	}
	vector<pair<int,pair<int,int>>> temp;


	//each time its like potentially n^2 or something, need a more efficient way to delete things
	auto it = adj[c].rbegin();
	while(it != adj[c].rend() && (*it).first >= t){
		temp.push_back(*it);
		adj[c].erase(*it);
		//it++;
	}




	/*cout << c << " " << t << ": ";
	for(auto e:adj[c]){
		cout << e.second.first << " ";
	}
	cout << "\n";*/



	for(auto e :temp){
		
		dfs(e.second.first , e.second.second);
	}

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
	for(int i=0;i<m;i++){
		int c,r,d,s; cin >> c >> r >> d >> s;
		adj[c].insert({r,{d,s}});

	}
	for(int i=1;i<=n;i++){
		cin >> layover[i];
		ans[i]=2000000000;
	}
    dfs(1,0);
	for(int i=1;i<=n;i++){
		if(ans[i]==2000000000){
			ans[i]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i] << "\n";
	}

	//debug
	/*
	for(int i=1;i<=n;i++){
		cout << i << ": ";
		for(auto e:adj[i]){
			cout << e.first << " ";
		}
		cout << "\n";
	}*/

}