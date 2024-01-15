// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	map<int,int> val;
	vector<int> a(n);
	for(auto &e:a){
		cin >> e;
		val[e]=1000000;
	}
	vector<int> dp(n);
	//optimal a_j, dp[j]
	//min dp[j] such that a_j+1 = a_i 
	//val[a_i] should find min dp[j] such that a_j+1 = a_i 
	//val[a_i] = min(val[a_i] , dp[i-1])
	
	dp[0]=1;
	val[a[0]]=0;
	//val[a[1]]=min(val[a[1]],1);
	for(int i=1;i<n;i++){
		dp[i] = min(dp[i-1]+1 , val[a[i]]);
		val[a[i]]=min(val[a[i]] , dp[i-1]);
	}
	//for(auto e:dp){
	//	cout << e << " ";
	//}
	cout << n-dp[n-1] << "\n";


}


int main() {
	int t; cin >> t;
	while(t--){
		solve();
	}

}