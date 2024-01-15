#include <bits/stdc++.h>

using namespace std;





string burger; 
int b,s,c; 
int pb,ps,pc; 
long long int r; 
vector<int> ing(3);


bool check(long long int x){
    long long int z=0;
    long long int total = max(z,ing[0]*x-b)*pb + max(z,ing[1]*x-s)*ps + max(z,ing[2]*x-c)*pc;
    if(total > r){
        return false;
    }
    else{
        return true;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> burger;
    cin >> b >> s >> c;
    cin >> pb >> ps >> pc;
    cin >> r;

    

    for(int i=0;i<burger.length();i++){
        if(burger[i]=='B'){
            ing[0]++;
        }
        if(burger[i]=='S'){
            ing[1]++;
        }
        if(burger[i]=='C'){
            ing[2]++;
        }
    }


    long long int l = 0;
    long long int r = 1000000000000000;
    while(l<r){
        long long int m = l + (r-l+1)/2;

        if(check(m)){
            l=m;
        }
        else{
            r=m-1;
        }


    }
    cout << l;
    


}