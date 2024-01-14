#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ifstream fin("cowjog.in");
	ofstream fout("cowjog.out");
    long long int n,t; fin >> n >> t;
	vector<long long int> cows;
	for(int i=0;i<n;i++){
		long long int a,b; fin >> a >> b;
		cows.push_back(a + b*t);
	}
	long long int mini=cows.back();
	int ans=1;
	for(int i=n-1;i>=0;i--){
		if(cows[i]<mini){
			ans++;
			mini=cows[i];
		}
	}
	fout << ans;
	


}
