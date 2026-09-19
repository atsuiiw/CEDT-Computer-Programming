#include<bits/stdc++.h>
using namespace std;

struct A{
	int val, penalties; // val for the final question time and penalties for amount of penalties
	bool valid; // check if this question will be considered for calculation

	A() {
		val = penalties = 0;
		valid = false;
	}
};

unordered_map<string,vector<A>> mp;
// store team name -> solved questions

struct B{
	string s;
	int c, penalties;
	bool operator < (const B&o) const {
		if(c!=o.c) return c > o.c;
		else if(penalties != o.penalties) return penalties < o.penalties;
		return s<o.s;
	}
};
vector<B> ans;

void sol() {
	int time,id;
	string team;
	char answer;
	cin>>time>>team>>id>>answer;
	if(mp[team].size() <= id) mp[team].resize(id+1);
	if(answer=='F'){
		if(mp[team][id].valid) return ;
		mp[team][id].penalties++;
	}
	else {	
		if(mp[team][id].valid) return ;
		mp[team][id].valid = true;
		mp[team][id].val = time;
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin>>q;
	while(q--) sol();

	// final calculation
	for(auto x:mp) {
		int c = 0;
		int penalties = 0;
		for(auto v:x.second){
			if(v.valid){
				c++;
				penalties += v.val + v.penalties*20;
			}
		}
		ans.push_back({x.first,c,penalties});
	}

	// output
	sort(ans.begin(),ans.end());
	bool ch = true;
	for(int i=0;i<min(3,(int)ans.size());i++){
		auto x = ans[i];
		if(x.c==0){
			ch = false;
			break;
		}
		cout<<x.s<<' '<<x.c<<' '<<x.penalties<<'\n';
	}
	for(int i=3;ch & i<ans.size();i++){
		auto x = ans[i];
		if(x.c != ans[2].c || x.penalties != ans[2].penalties) break;
		cout<<x.s<<' '<<x.c<<' '<<x.penalties<<'\n';
	}
	return 0;
}
