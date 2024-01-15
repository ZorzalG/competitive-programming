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
   ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            arr.at(i+1)= arr.at(i) | arr.at(i+1);
            arr.at(i)=0;
        }
        cout << arr.at(n-1) << "\n";



    }
}
 
 
 
 
 