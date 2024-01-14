#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

bool cmp(pair<int,int> x, pair<int,int> y){
	return x.second < y.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	//id, value
	vector<pair<int,int>> a;
	map<int,int> lookup;
	for(int i=0;i<n;i++){
		int x; cin >> x;
		a.push_back({i+1,x});
	}
	sort(a.begin(),a.end(),cmp);
	int original = 0;
	for(int i=0;i<n;i++){
		original += a[i].second*(i+1);
	}
	vector<int> prefix(1);
	prefix[0] = 0;
	for(int i=0;i<n;i++){
		prefix.push_back(prefix.back()+a[i].second);
	}

	for(auto e:prefix){
		cout << e << ' ';
	}
	
	

	for(int i=0;i<n;i++){
		lookup[a[i].first] = i;
	}
	

	multiset<int> b;
	for(auto e:a){
		b.insert(e.second);
	}

	int q; cin >> q;
	for(int i=0;i<q;i++){
		int ind, val; cin >> ind >> val;
		int original_index = lookup[ind]; //unused for now
		//store the original value
		int oval = a[original_index].second;

		b.erase(b.find(oval));
		b.insert(val);

		auto it = b.lower_bound(val);
		//cout << it << '\n';

	}



}

