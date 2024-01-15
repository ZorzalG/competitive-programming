#include <bits/stdc++.h>

using namespace std;

long long int modul=998244353;

long long int shitproblem(long long int x){
    long long int m=modul;
    long long int a = 1;
    long long int b = 0;
    if(m==1){
        return 0;
    }
    while(x>1){
        long long int q = x/m;
        long long int p=m;

        m=x%m;
        x=p;
        p=b;
        b=a-q*b;
        a=p;


    }
    if(a<0){
        a+=modul;
    }
    return a;
}

long long int combo(long long int n){
    long long int val=1;
    for(int i=n/2+1;i<=n;i++){
        val*=i;
        val = val%modul;
        val*=shitproblem(i-n/2);
        val=val%modul;
    }
    //cout << val%modul << " ";
    return val%modul;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("swap.in");
    //ofstream fout("swap.out");
    int n; cin >> n;
    vector<pair<multiset<int>,int>> tris;
    for(int i=0;i<n/3;i++){
        multiset<int> tmp;
        
        int a,b,c; cin >> a >> b >> c;
        tmp.insert(a);
        tmp.insert(b);
        tmp.insert(c);
        
        tris.push_back({tmp , tmp.count(*tmp.begin())});
        /*for(auto e:tmp){
            cout << e << " ";
        }
        cout << "\n";*/
    }
    long long int ans=1;
    
    
    for(auto e:tris){
        //cout << e.second << " ";
        ans = ans*e.second;
        ans = ans % modul;
    }
    //cout << ans << " ";
    ans = ans * combo((n/3));
    ans = ans % modul;
    //cout << shitproblem(2) << " ";
    cout << ans;
    

}