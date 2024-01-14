#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

long long int ans=0;

//destination,r
vector<pair<int,int>> adj[100001];
bool visited[5001]={};

//int ans=0;
int kx=0;
void dfs(int c,int k){
	if(visited[c]){
		return;
	}
	visited[c]=true;
	ans++;
	for(auto e:adj[c]){
		if(e.second>=kx){
			//cout << c << " " << e.first << "\n";
			dfs(e.first,min(k,e.second));
		}
	}



}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
    int n,q; fin >> n >> q;
	for(int i=0;i<n-1;i++){
		int a,b,c; fin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	for(int i=0;i<q;i++){
		int ki,vi; fin >> ki >> vi;
		kx=ki;
		dfs(vi,1000000001);
		fout << ans-1 << '\n';
		ans=0;
		for(auto &e:visited){
			e=false;
		}
	}


}