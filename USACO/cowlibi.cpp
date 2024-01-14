#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<pair<long long int,pair<long long int,long long int>>> pts;
    long long int g,n; cin >> g >> n;
    for(int i=0;i<g;i++){
        long long int x,y,time; cin >> x >> y >> time;
        pts.insert({time,{x,y}});
    }
    vector<pair<long long int,pair<long long int,long long int>>> cows;
    for(int i=0;i<n;i++){
        long long int x,y,time; cin >> x >> y >> time;
        cows.push_back({time,{x,y}});
    }
    //sort(pts.begin(),pts.end());
    long long int ans=0;
    /*for(int i=0;i<n;i++){
        dbg(pts.size());
        pts.insert(cows[i]);
        auto ita = pts.find(cows[i]);
        if(ita == pts.begin()){
            //only check from starting point

            ita++;
            auto a = *ita;
            int dta = cows[i].first - a.first;
            int dax = abs(cows[i].second.first-a.second.first);
            int day = abs(cows[i].second.second-a.second.second);
            pts.erase(pts.find(cows[i]));
            if(dta*dta < dax*dax + day*day){
                ans++;
                dbg(i);
                continue;
            }
        }
        
        ita--;
        auto itb = pts.find(cows[i]);
        itb++;
        if(itb == pts.end()){
            //only check back
        }
        auto a=*ita;
        auto b=*itb;
        pts.erase(pts.find(cows[i]));
        int dta = cows[i].first - a.first;
        int dax = abs(cows[i].second.first-a.second.first);
        int day = abs(cows[i].second.second-a.second.second);
        int dtb=b.first-cows[i].first;
        int dbx = abs(cows[i].second.first-b.second.first);
        int dby = abs(cows[i].second.second-b.second.second);
        if(dta*dta < dax*dax + day*day){
            ans++;
            dbg(i);
            continue;
           
        }
        if(dtb*dtb < dbx*dbx + dby*dby){
            ans++;
            dbg(i);
            continue;
        }  
    }*/
    for(int i=0;i<n;i++){
        auto a = pts.lower_bound(cows[i]);
        
        
        //pts.insert(cows[i]);
        if(a == pts.begin()){
            //cout << "x";
            //check start only
            auto ita=*pts.begin();
            long long int dat=abs(ita.first-cows[i].first);
            long long int dax = abs(ita.second.first - cows[i].second.first);
            long long int day = abs(ita.second.second - cows[i].second.second);
            /*dbg(dat);
            dbg(dax);
            dbg(day);
            dbg(dat*dat);
            dbg(dax*dax);
            dbg(day*day);*/
            long long int t2=dat*dat;
            long long int x2=dax*dax;
            long long int y2=day*day;
            //cout << t2 - x2 - y2;
            if(t2 < x2 + y2){
                ans++;
                continue;
            }

        }
        else if(a == pts.end()){
            //cout << "x";
            auto ita=*pts.rbegin();
            long long int dat=abs(ita.first-cows[i].first);
            long long int dax = abs(ita.second.first - cows[i].second.first);
            long long int day = abs(ita.second.second - cows[i].second.second);
            //dbg(dat*dat);
            //dbg(day*day);
            //dbg(dax*dax);
            if(dat*dat < dax*dax + day*day){
                ans++;
                continue;
            }
            //check end only
        }
        else{
            //dbg(i);
            //b--;
            auto ita=*a;
            auto b = pts.lower_bound(cows[i]);
            b--;
            auto itb=*b;

            long long int dat=abs(ita.first-cows[i].first);
            long long int dax = abs(ita.second.first - cows[i].second.first);
            long long int day = abs(ita.second.second - cows[i].second.second);
            if(dat*dat < dax*dax + day*day){
                ans++;
                continue;
            }
            long long int dbt=abs(itb.first-cows[i].first);
            long long int dbx = abs(itb.second.first - cows[i].second.first);
            long long int dby = abs(itb.second.second - cows[i].second.second);
            if(dbt*dbt < dbx*dbx + dby*dby){
                ans++;
                continue;
            }
           // dbg(i);

        }
    }

    cout << ans;


    

}