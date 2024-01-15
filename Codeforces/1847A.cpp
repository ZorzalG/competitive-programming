// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n,k; cin >> n >> k;
	vector<int> a(n);
	multiset<int> vals;
	for(auto &e:a){
		cin >> e;
	}
	for(int i=0;i<n-1;i++){
		vals.insert(abs(a[i]-a[i+1]));
	}
	auto it = vals.begin();
	int ans=0;
	for(int i=0;i<n-k;i++){
		ans+=*it;
		it++;
	}
	cout << ans << '\n';

}

int main() {
	int t; cin >> t;
	while(t--){
		solve();
	}

}