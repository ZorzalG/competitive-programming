// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n; cin >> n;
	vector<int> a;
	long long int init=0;
	for(int i=0;i<n;i++){
		int b; cin >> b;
		a.push_back(b);
		init+=b;
	}

	int mini=1000000001;
	int last=0;
	int cur=0;
	int steps=0;
	multiset<long long int> positions;
	multiset<long long int> things;
	//this is all assuming we start at the first
	while(steps<n/2){
		while(cur<steps*2+2){
			positions.insert({a[cur]});
			cur++;
		}
		auto it = *positions.begin();
		things.insert(it);
		positions.erase(positions.find(it));
		
		steps++;
		mini=1000000001;
	}
	
	for(auto e:things){
		init-=e;
	}
	cout << init;

	
	

}