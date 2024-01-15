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
        vector<long long int> arr;
        vector<int> peaks;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        peaks.push_back(0);
        for(int i=1;i<n-1;i++){
            if(arr.at(i) > arr.at(i-1) && arr.at(i) > arr.at(i+1)){
                peaks.push_back(1);
            }
            else{
                peaks.push_back(0);
            }
        }
        peaks.push_back(0);
        long long int start=0;
        
        for(int i=1;i<n-1;i++){
            
            if(peaks.at(i)>0 ){
                if(peaks.at(i-1) ==0  && peaks.at(i+1)==0){
                    if(i+1!=n-1){peaks.at(i+1)=2;}
                    else{peaks.at(i-1)=2;}
                    start++;
                }
            }
            
            
        }
        if(n==3){
            cout << start << "\n";
            //cout << arr.at(0) << " " << arr.at(0) << " " << arr.at(2) << "\n";
            if(peaks.at(1)==1){
                cout << arr.at(0) << " " << arr.at(0) << " " << arr.at(2) << "\n";
            }
            else{
                cout << arr.at(0) << " " << arr.at(1) << " " << arr.at(2) << "\n";
            }
        }
        else{
            cout << start << "\n";
            cout << arr.at(0) << " ";
            for(int i=1;i<n-1;i++){
                if(peaks.at(i)==2){
                    arr.at(i)=max(arr.at(i-1),arr.at(i+1));
                }
                cout << arr.at(i) << " ";
            }
            cout << arr.at(n-1);
            cout << "\n";
        }

    }
}
 
 
 
 
 