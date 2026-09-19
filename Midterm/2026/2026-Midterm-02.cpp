#include<bits/stdc++.h>
using namespace std;

int cardRanking(string s) {
	if(s=="A") return 14;
	if(s=="J") return 11;
	if(s=="Q") return 12;
	if(s=="K") return 13;
	return stoi(s);
}

int cardValue(string s){
	if(s=="A") return 1;
	if(s=="K" || s=="Q" || s=="J") return 10;
	return stoi(s);
}

struct A{
	string val;
	int rank;
	bool operator < (const A&o) const {
		return rank > o.rank;
	}
};
vector<A> vec;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);

	string a,b,c; cin>>a>>b>>c;
	if(a==b && b==c){
		cout<<"Three of a Kind: "<<a<<"-"<<a<<"-"<<a;
		return 0;
	}
	int sum = (cardValue(a) + cardValue(b) + cardValue(c)) % 10;
	vec.push_back({a,cardRanking(a)});
	vec.push_back({b,cardRanking(b)});
	vec.push_back({c,cardRanking(c)});

	sort(vec.begin(),vec.end());
	cout<<sum<<": "<<vec[0].val<<"-"<<vec[1].val<<"-"<<vec[2].val;
	return 0;
}
