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
	int n;
	cin >> n;
	vector<int> weights;
	for (int i = 0; i < 2 * n; i++) {
		int a;
		cin >> a;
		weights.push_back(a);
	}
	sort(weights.begin(), weights.end());
	int mini = 1000000000;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = i + 1; j < 2 * n; j++) {
			int adder = 0;
			vector<int> igotlazy;

			for (int k = 0; k < 2 * n; k++) {
				if (k != i && k != j) {
					igotlazy.push_back(weights.at(k));
				}
			}

			for (int k = 0; k < 2 * n - 2; k++) {
				if (k % 2 == 0) {
					adder -= igotlazy.at(k);
				}
				else if (k % 2 == 1) {
					adder += igotlazy.at(k);
				}
			}
			mini = min(mini, adder);

		}
	}
	cout << mini;

}




//3 4 1 1