// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;




int main() {
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");
	long long int l,n,f,b; fin >> l >> n >> f >> b;
	//pos val
	vector<pair<long long int,long long int>> rest;
	//vector<pair<int,int>> rest(n);
	//val,pos
	multiset<pair<long long int,long long int>> track;
	for(long long int i=0;i<n;i++){
		long long int a,aa; fin >> a >> aa;
		rest.push_back({a,aa});
		track.insert({aa,a});
	}
	//beeline to maximum, then 2nd maximum, then 3rd, etc.
	vector<pair<long long int,long long int>> trackr;
	long long int ite=0;
	while(!track.empty()){
		auto it = *track.rbegin();
		trackr.push_back({it.second,it.first});
		while(rest[ite].first<=it.second){
			track.erase({rest[ite].second , rest[ite].first});
			ite++;
		}
	}
	long long int ans=0;
	long long int cur=0;
	for(auto e:trackr){
		ans+=(f - b)*(e.first-cur)*e.second;
		cur = e.first;
		//cout << e.first << " " << e.second << "| ";
	}
	fout << ans;

}
