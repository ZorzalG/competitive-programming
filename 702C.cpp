#include <bits/stdc++.h>
using namespace std;






int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    //ifstream fin("helpcross.in");
    //ofstream fout("helpcross.out");
    int n,m; cin >> n >> m;
    vector<long long int> cit;
    vector<long long int> tow;
    tow.push_back(-10000000000);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        cit.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a; cin >> a;
        tow.push_back(a);
    }
    tow.push_back(10000000000);
    int c=1;
    long long int r=0;
    for(int i=0;i<n;i++){
        while(tow[c]<cit[i]){
            c++;
        }
        r=max( r , min( abs(tow[c]-cit[i]),abs(tow[c-1]-cit[i]) ) );
    }
    cout << r;



    
}
 
 
 