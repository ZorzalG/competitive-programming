#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

long long int combo(int n, int k) {
	long long int x = 1;
	//cout << "XXX" << endl;
	long long int s = max(k + 1, n - k + 1);
	long long int oth = min(k + 1, n - k + 1);
	long long int xx = 1;
	for (int i = s; i <= n; i++) {
		//cout << i;
		x = x * i;
		//cout << x<<endl;

		if (x % xx == 0 && x > xx && xx < oth) {
			x = x / xx;
			xx++;
		}
	}

	//cout << x;
	if (k > n) { return 0; }
	return x;
}

int main() {
	int n, m, t;
	cin >> n >> m >> t;
	long long int total = 0;
	for (int i = 4; i <= t - 1; i++) {
		//cout << n << " " << i << " ";
		//cout << combo(5, 4);

		total += combo(n, i) * combo(m, t - i);

		// total += choose i from boys * choose t-i from girls
		// c(n,k)
		// for(int i=k,i<=n;i++){x*=i}
		// for(int i=1;i<=k;i++){x/=i}

	}
	//cout << combo(30, 15) << endl;
	cout << total;
}




//3 4 1 1