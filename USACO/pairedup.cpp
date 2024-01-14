// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int main() {

	ifstream fin("pairup.in");
	ofstream fout("pairup.out");

	int n; fin >> n;
	//val,amt
	vector<pair<int,int>> cows;
	for(int i=0;i<n;i++){
		int a,b; fin >> a >> b;
		cows.push_back({b,a});
	}
	sort(cows.begin(),cows.end());
	int front=0;
	int back = n-1;
	int ans=0;
	while(front < back){
		ans = max(ans,cows[front].first + cows[back].first);
		if(cows[front].second<cows[back].second){
			cows[back].second -= cows[front].second;
			front++;
		}
		else if(cows[front].second==cows[back].second){
			front++;
			back--;
		}
		else{
			cows[front].second -= cows[back].second;
			back--;
		}
	}
	fout << ans;
	
	

}
