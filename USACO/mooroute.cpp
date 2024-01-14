#include <bits/stdc++.h>

using namespace std;




//void gener(){
//    
//}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<string> subproblems;
    vector<int> p;
    vector<int> poi;
    int mini=10000000;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        p.push_back(a);
        mini=min(mini,a);
        
    }
    int si=0;
    int ei=0;
    for(int i=0;i<n;i++){
        if(p[i]==mini){
            poi.push_back(i);
        }
    }
    //poi.push_back(-1);
    //for(int i=poi.length()-1;i>=0;i--){
    //    gener(poi[i])
    //}
	vector<int> fs;
	int curret=p[p.size()-1];
	for(int i=p.size()-2;i>=0;i--){
		if(p[i]<curret){
			fs.push_back(i);
		}
	}
    int pos=0;
	int firstsmaller=fs[fs.size()-1];
	int cmax=n;
	while(p[0]!=0){
		if(pos<cmax){
			//cout << "x" << "\n";
			
			pos++;
			cout << "R";
			p[pos-1]--;

		}


		if(pos==cmax){
			int c=0;
			while(p[cmax-1]!=0){
				if(c%2==0){
					pos--;
					cout << "L";
					p[pos]--;
					if(p[pos-1]<p[cmax-1]){
						c++;
					}
				}
				else{
					pos++;
					cout << "R";
					p[pos-1]--;
					if(pos==cmax){
						c++;
					}
				}
				
			}
			cmax=pos;
			//cout << cmax << "\n";
			//if(p[pos]<firstsmaller){
			//	fs.pop_back();
			//	firstsmaller=fs[fs.size()-1];
			//}
		}
	}



    
    

}
