#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,m,n; cin >> k >> m >> n;
    vector<pair<long long int,long long int>> patches;
    for(int i=0;i<k;i++){
        long long int a,b; cin >> a >> b;
        patches.push_back({a,b});
    }
    sort(patches.begin(),patches.end());

    vector<long long int> nhoj(m);
    for(int i=0;i<m;i++){
        cin >> nhoj[i];
    }
    sort(nhoj.begin(),nhoj.end());

    vector<vector<pair<long long int,long long int>>> interval;
    vector<pair<long long int,long long int>> tmp;

    int r=0;
    int ind=0;
    while(r<=m){
        while(ind<k && patches[ind].first<=nhoj[r]){
            tmp.push_back(patches[ind]);
            ind++;
        }
        interval.push_back(tmp);
        tmp.clear();
        r++;
    }
    for(int i=ind;i<k;i++){
        interval.back().push_back(patches[i]);
    }
    
    vector<long long int> ans;


    for(int i=1;i<m;i++){

        if(interval[i].size()<1){
            continue;
        }

        long long int ileft = nhoj[i-1];
        long long int iright=nhoj[i];
        long long int isize = (iright-ileft); // div 2
        long long int msum=interval[i][0].second;
        long long int tsum=0;
        long long int rsum=msum;
        int il=0;
        int ir=0;
       while(il<interval[i].size() && ir<interval[i].size()){
            ir++;
            if(ir<interval[i].size()){
                rsum+=interval[i][ir].second;
                while((interval[i][ir].first - interval[i][il].first)*2 >= isize){
                    rsum-=interval[i][il].second;
                    il++;
                }
                msum=max(msum,rsum);
            }
        }
        for(int j=0;j<interval[i].size();j++){
            tsum+=interval[i][j].second;
        }
        ans.push_back(msum);
        ans.push_back(tsum-msum);
        //dbg(msum);
        //dbg(tsum);
       
    }
    long long int teemp=0;
    for(auto e:interval[0]){
        teemp+=e.second;
    }
    ans.push_back(teemp);
   
    teemp=0;
    for(auto e:interval.back()){
        teemp+=e.second;
    }
    ans.push_back(teemp);
    

    sort(ans.begin(),ans.end(),greater<int>());
    long long int superans=0;
    for(int i=0;i<n;i++){
        superans+=ans[i];
    }
    cout << superans;

    vector<long long int> thing;
    for(auto e:interval){
      
        for(auto p:e){
            //cout << p.first << " " << p.second << " | ";
            
        }
        
    }

    /*for(auto e:ans){
        cout << e << " ";
    }*/

    


}
