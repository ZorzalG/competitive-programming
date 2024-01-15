#include <bits/stdc++.h>

using namespace std;

bool check=false;

void endgame(){
    cout << "next 0 1 2 3 4 5 6 7 8 9" << "\n";
    cout.flush();
    int n2; cin >> n2;
    string dummy;
    for(int i=0;i<n2;i++){
        cin >> dummy;
    }
    if(n2==1){
        cout << "done" << "\n";
        check=true;
    }
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int amoves=0;
    int bmoves=0;
    //int t=0;
    while(bmoves<3000){
        // move A guy and B guy
        amoves++;
        bmoves++;
        cout << "next " << 0 << " " << 1 << "\n";
        cout.flush();

        int n; cin >> n;
        vector<string> s;
        for(int i=0;i<n;i++){
            string e; cin >> e;
            //cout << e << "!\n";
            s.push_back(e);
        }
        // move B guy
        bmoves++;
        cout << "next " << 1 << "\n";
        cout.flush();
        int n1; cin >> n1;
        vector<string> s1;
        for(int i=0;i<n1;i++){
            string e; cin >> e;
            //cout << e << "!\n";
            s1.push_back(e);
        }
        //check if the same
        //cout << n1;
        //for(auto e: s1){
        //    cout << e << " ";
        //}
        if(find(s1.begin(),s1.end(),"01") != s1.end()){
            //both are at the same place now, start moving the rest until theyre at the same spot
            while(!check){
                endgame();
            }
            break;
        }
        else{
            continue;
        }



    }


}