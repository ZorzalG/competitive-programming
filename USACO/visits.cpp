#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> adj[100001];
vector<int> val;
bool visited[200001]={};
vector<int> cc;

void dfs(int c){
    cc.push_back(c);
    if(visited[c]){
        
        return;
    }
    visited[c]=true;
    dfs(adj[c][0]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	//ifstream fin("meetings.in");
	//ofstream fout("meetings.out");
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        adj[i+1].push_back(a);
        val.push_back(b);

    }
    long long int subtract=0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
        else{
            continue;
        }
        //for(auto e:cc){
        //    cout << e << " ";
        //}
        int cbegin=-1;
        for(int j=0;j<cc.size()-1;j++){
            if(cc[j] == cc.back()){
                //this is where cycle begins
                cbegin=j;
                break;
            }
        }
        //finding min for subtract
        int temp=2000000000;
        if(cbegin!=-1){
            for(int j=cbegin+1;j<cc.size();j++){
                temp = min(temp , val[cc[j]-1]);
            }
            //dbg(temp);
            subtract+=temp;
        }
        cc.clear();
        
    }
    long long int ans=0;
    for(auto e:val){
        ans+=e;
    }
    cout << ans-subtract;


}