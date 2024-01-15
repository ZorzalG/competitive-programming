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
    int t;
    cin >> t;
    for(int sd=0;sd<t;sd++){
        int n,k;
        int arr[501][501];
        cin >> n >> k;
        int lasteven=2;
        int lastodd=1;
        bool good=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                
                if(i%2==0){
                    if(lastodd > n*k){
                        good=false;
                    }
                    arr[i][j]=lastodd;
                    lastodd+=2;
                }
                else{
                    if(lasteven > n*k){
                        good=false;
                    }
                    arr[i][j]=lasteven;
                    lasteven+=2;
                }
                

            }
        }
        
        /*int counter=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                arr[i+counter%2][j/2]=counter;
                counter++;
            }
            i++;
        }*/
        if(good){
            cout << "YES" << endl;
            for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        }
        else{
            cout << "NO" << endl;
        }
        

    }
}
 
 
 
 
 