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
       int n;
       long long int oddstore=0;
       long long int count=0;
       bool good=true;
       cin >> n;
       long long int arr[100001];
       for(int i=0;i<n;i++){
           cin >> arr[i];
       }
        bool repeat=true;
        if(n-2 == 1 && arr[1]%2==1){
            repeat=false;
            count=-1;
        }

       
       while(repeat){
           repeat=false;
            //cout << 's';
            for(int i=1;i<n-1;i++){
                //cout << oddstore << " ";
                if(arr[i]>1){
                    oddstore+= (arr[i]-(arr[i]%2))/2;
                    count +=(arr[i]-(arr[i]%2))/2;
                    arr[i] = arr[i]-arr[i]+(arr[i]%2);
                    //cout << 
                    //for(int i=0;i<n;i++){
                    //    cout << arr[i] << " ";
                    //}
                    //cout << "\n";
                    repeat=true;
                }
                if(arr[i]==1){
                    if(oddstore>=1){
                        //cout << 's';
                        repeat=true;
                        arr[i]++;
                        //count++;
                        oddstore--;
                        
                    }
                    
                }
            }
       
            
       
       }
       //for(int i=0;i<n;i++){
        //   cout << arr[i] << " ";
       //}
       for(int i=1;i<n-1;i++){
           if(arr[i]==1){
                    count=-1;
                }
       }
       cout << count << "\n";
   }
}
 
 
 
 
 