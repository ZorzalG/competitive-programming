#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	ifstream fin("maxcross.in");
	ofstream fout("maxcross.out");

    int n,k,b; fin >> n >> k >> b;
	vector<int> tl(100001);
	for(int i=0;i<b;i++){
		int a; fin >> a;
		tl[a]=1;
	}

	



	int ans=k;
	int rtotal=0;
	int l=1;
	int r=1;
	for(r=1;r<=k;r++){

		rtotal+=tl[r];	
	}
	ans=min(ans,rtotal);


	

	while(r<=n){
		
		rtotal+=tl[r];
		rtotal-=tl[l];
		l++;
		r++;
		ans=min(ans,rtotal);
	}
	fout << ans;



}
