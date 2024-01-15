#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> hw;
    for(int i=1;i<=n;i++){
        int a,b; cin >> a >> b;
        if(a>b){
            hw.push_back({{a,b},i});
        }
        else{
            hw.push_back({{b,a},i});
        }
        
    }
    sort(hw.begin(),hw.end());

    //for(auto e:hw){
    //    cout << e.second << " ";
    //}
    //cout << "\n";

    multiset<pair<int,int>> going;
    //sort by largest part
    //vector<pair<pair<int,int>,pair<int,int>>> LOL;
    //for(int i=0;i<n;i++){
    //    LOL.push_back({{hw[i].first.second,i},{hw[i].second , hw[i].first.first}});
    //    //want to sort first by smaller part, then the order they are in
    //}
    //sort(LOL.begin(),LOL.end());
    vector<int> ans(n);
    vector<pair<int,int>> tmp;

    tmp.push_back({hw[0].first.second,hw[0].second});
    
    ans[hw[0].second-1]=-1;
    for(int i=1;i<n;i++){
        //find an element that has a smaller small part and smaller large part
        
        if(hw[i].first.first != hw[i-1].first.first){
            for(auto e:tmp){
                going.insert(e);
            }
            tmp.clear();
        }
        tmp.push_back({hw[i].first.second,hw[i].second});
        auto whatever = *going.begin();
        if(whatever.first < hw[i].first.second){
            if(whatever.first==0 && whatever.second ==0){
                ans[hw[i].second-1]=-1;
            }
            //cout << i << " " << hw[i].second << "\n";
            else{
                ans[hw[i].second-1]=whatever.second;
                //cout << hw[i].second-1 << " " << whatever.first << " " << whatever.second << "\n";
            }
        }
        else{
            ans[hw[i].second-1]=-1;
        }
    }

    for(auto e: ans){
        cout << e << " ";
    }
    cout << "\n";






}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("split.in");
    //ofstream fout("split.out");
    int t; cin >> t;
    while(t--){
        solve();
    }

}