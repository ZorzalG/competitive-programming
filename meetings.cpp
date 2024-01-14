#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


int l;

bool cmp(pair<pair<int,int>,pair<int,int>> &a, pair<pair<int,int>,pair<int,int>> &b){
	int atime;
	if(a.second.first == 1){
		atime = l-a.first.second;
	}
	else if (a.second.first == -1){
		atime = a.first.second;
	}


	int btime;
	if(b.second.first == 1){
		btime = l-b.first.second;
	}
	else if (b.second.first == -1){
		btime = b.first.second;
	}

	return atime < btime;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ifstream fin("meetings.in");
	ofstream fout("meetings.out");
    int n; fin >> n >> l;
	// w, x, d
	vector<pair<pair<int,int>,int>> cows;
	int weight=0;
	for(int i=0;i<n;i++){
		int w,x,d; fin >> w >> x >> d;
		cows.push_back({{x,w},d});
		weight+=w;
	}

	sort(cows.begin(),cows.end());

	//wxdn
	vector<pair<pair<int,int>,pair<int,int>>> cows2;

	for(int i=0;i<n;i++){
		if(cows[i].second == -1){
			cows2.push_back({{cows[i].first.second , cows[i].first.first},{cows[i].second,i}});
		}
		else{
			cows2.push_back({{cows[i].first.second , cows[i].first.first},{cows[i].second,n-i-1}});
		}

		
	}

	//now, sort the cows based on time to reach the ends
	sort(cows2.begin(),cows2.end(),cmp);



	//for(auto e:cows2){
	//	cout << e.first.second << " " << e.second.first << "| ";
	//}
	//cout << '\n';
	multiset<pair<int,int>> weird;
	for(auto e:cows){
		weird.insert({e.first.first, e.first.second});
	}
	
	/*for(auto e:weird){
		cout << e.first << " ";
	}*/
	int cweight=0;
	int answer=0;
	//cout << weight;
	int bigt=0;
	for(int i=0;i<n;i++){
		//cout << cweight;
		if(cows2[i].second.first == 1){
			//add the rightmost to the total
			auto it = *weird.rbegin();
			cweight+=it.second;
			weird.erase(weird.find(it));
		}
		else if(cows2[i].second.first == -1){
			//add the leftmost to the total
			auto it = *weird.begin();
			cweight+=it.second;
			weird.erase(weird.find(it));
		}
		//cout << cweight << " ";
		if(cweight*2 >= weight){
			//cout << cows2[i].first.second << " " << cows2[i].second.first;
			if(cows2[i].second.first == -1){
				bigt=cows2[i].first.second;
			}
			else{
				bigt = l-cows2[i].first.second;
			}
			break;
		}
	}

	queue<int> leftgoers;
	for(int i=0;i<n;i++){
		if(cows[i].second == 1){
			leftgoers.push(cows[i].first.first);
		}
		else{
			while(leftgoers.front() + 2*bigt < cows[i].first.first && !leftgoers.empty()){
				leftgoers.pop();
			}
			answer+=leftgoers.size();
		}
	}
	fout << answer;
	//cout << '\n' << bigt;


	


}