// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long int mod = 998244353;

vector<int> factorials;


void solve(){
	long long int l, r; cin >> l >> r;
	long long int exp=2;
	long long int si=1;
	while(l*exp <= r){
		exp*=2;
		si++;
	}
	long long int texp=exp/2;
	cout << si << " ";
	long long int max3 = 0;
	while(l*texp*pow(3,max3) <= r){
		//cout << l*exp*pow(3,max3) << " ";
		texp=max(texp/2, (long long int)1);
		max3++;
	}
	max3--;
	//cout << " " << max3 << "\n";
	long long int ans=0;
	for(int i=0;i<=max3;i++){
		int maxl = r/(pow(2,(si-1-i)))/(pow(3,i));
		if(i>0){
			ans+= (maxl-l+1) * (si-1);
		}
		else{
			ans+= (maxl-l+1);
		}
		
		ans%=mod;
		//cout << maxl << "\n";
	}
	cout << ans << "\n";
}

int main() {
	//ifstream fin("herding.in");
	//ofstream fout("herding.out");
	int t; cin >> t;
	long long int fac=1;
	for(int i=1;i<=2000;i++){
		fac*=i;
		fac%=mod;
		factorials.push_back(fac);
	}
	while(t--){
		solve();
	}
	


	


}