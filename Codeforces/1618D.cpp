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



int main() {
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int score = 0;
		vector<int> a;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int sss;
			cin >> sss;
			score += sss;
			a.push_back(sss);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < k; i++) {
			if (a.at(n - 1 - i) == a.at(n - 1 - i - k)) {
				score++;
			}
			score -= a.at(n - 1 - i);
			score -= a.at(n - 1 - i - k);

		}
		cout << score << endl;
	}
}




//3 4 1 1