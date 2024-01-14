// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	string bessie = "bessie";
	long long int ans=0;
	long long int rem=s.length();
	long long int arr[7] = {0,0,0,0,0,0,0};
	for(int i=0;i<s.length();i++){
		arr[0]++;
		for(int j=5;j>=0;j--){
			if(s[i] == bessie[j]){
				
				arr[j+1]+=arr[j];
				arr[j]=0;
			}
			
		}
		//found a new bessie
		if(arr[6]!=0){
			ans+= arr[6]*(rem);
			arr[0]+=arr[6];
			arr[6]=0;
		}
		rem--;
		
	}
	cout << ans;
}
