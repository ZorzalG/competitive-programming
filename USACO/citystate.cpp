// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	long long int n; fin >> n;
	map<string,long long int> lookup;
	for(int i=0;i<n;i++){
		string a,b; fin >> a >> b;
		string res = a.substr(0,2)+b;
		lookup[res]+=1;
	}
	long long int ans=0;
	
	for(auto e:lookup){
		
		string names = e.first;
		if(names.substr(2,4) == names.substr(0,2)){
			continue;
		}
		string temp = names.substr(2,4) + names.substr(0,2);
		//cout << temp;
		ans+=lookup[temp]*e.second;
	}
	/*for(auto e:lookup){
		cout << e.first << " " << e.second << "\n";
	}*/
	fout << (ans/2);
	
}
