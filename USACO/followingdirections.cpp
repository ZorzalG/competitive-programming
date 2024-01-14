#include <bits/stdc++.h>

using namespace std;

int grid[1502][1502]={};
int grid2[1502][1502]={};


long long int total=0;

int se=0;

void traverse(int y, int x, int v){
    grid2[y][x]-=v;
    if(grid[y][x]==-1){
        traverse(y,x+1,v);
    }
    if(grid[y][x]==-2){
        traverse(y+1,x,v);
    }
}

void traverse2(int y, int x, int v){
    grid2[y][x]+=v;
    if(grid[y][x]==-1){
        traverse2(y,x+1,v);
    }
    if(grid[y][x]==-2){
        traverse2(y+1,x,v);
    }
}

//-1 = R -2 = D
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++){
            if(s[j]=='R'){
                grid[i][j]=-1;
            }
            else{
                grid[i][j]=-2;
            }
            
        }
        cin >> grid[i][n];
    }

    for(int i=0;i<n;i++){
        cin >> grid[n][i];
    }
    
    //
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            grid2[i][j]=1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==-1){
                grid2[i][j+1]+=grid2[i][j];
            }
            else if(grid[i][j]==-2){
                grid2[i+1][j]+=grid2[i][j];
            }
        }
    }
    
    for(int i=0;i<n;i++){
        //traverse(n,i,grid[i][n]);
        total+=grid[i][n]*grid2[i][n];
    }
    for(int i=0;i<n;i++){
        //traverse(i,n,grid[n][i]);
        total+=grid[n][i]*grid2[n][i];
    }
    cout << total << "\n";
    
    
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        a--;
        b--;
        int temp=grid2[a][b];
        traverse(a,b,grid2[a][b]);
        grid2[a][b]+=temp;
        if(grid[a][b]==-1){
            grid[a][b]=-2;
        }
        else{
            grid[a][b]=-1;
        }

        traverse2(a,b,grid2[a][b]);
        grid2[a][b]-=temp;
        /*for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout << grid2[i][j] << " ";
            }
            cout << "\n";
        }*/
        total=0;
        for(int i=0;i<n;i++){
            //traverse(n,i,grid[i][n]);
            total+=grid[i][n]*grid2[i][n];
        }
        for(int i=0;i<n;i++){
            //traverse(i,n,grid[n][i]);
            total+=grid[n][i]*grid2[n][i];
        }
        cout << total << "\n";

    }
    /*
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        a--;
        b--;

        if(grid[a][b]==-1){
            grid[a][b]=-2;
        }
        else{
            grid[a][b]=-1;
        }

        total=0;
        for(int i=0;i<n;i++){
        traverse(n,i,grid[i][n]);
        }
        for(int i=0;i<n;i++){
            traverse(i,n,grid[n][i]);
        }
        cout << total << "\n";
    }*/


    
    

}
