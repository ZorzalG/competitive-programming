#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

long long int ans=0;


vector<int> adj[100001];
bool visited[100001]={};


void dfs(int c){
	if(visited[c]){
		return;
	}
	visited[c]=true;
	int temp=0;
	for(auto e:adj[c]){
		if(!visited[e]){
			temp++;
		}
	}
	ans+=temp;
	while(temp>0){
		temp/=2;
		ans++;
	}
	for(auto e: adj[c]){
		dfs(e);
	}



}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	//ifstream fin("milkvisits.in");
	//ofstream fout("milkvisits.out");
    int n; cin >> n;
	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << ans;


}