#include<bits/stdc++.h>
using namespace std;

int mx,en,last,cnt;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);

	string opr; int n;
	cin>>opr>>n;
	vector<int> vec;
	vec.resize(n);
	for(auto& x:vec) cin>>x;
	vec.push_back(vec[n-1]);

	for(int i=1;i<n;i++){
		int now = 0;
		if(vec[i] > vec[i-1] && vec[i] > vec[i+1]) now = 1;
		else if(vec[i] < vec[i-1] && vec[i] < vec[i+1]) now = -1;
		if(now==0 || last==now){
			if(cnt!=0 && cnt+2 > mx){
				mx = cnt+2;
				en = i;
			}
			cnt = 0;
			if(now != 0) cnt = 1;
		}
		else{
			cnt++;
			last = now;
		}
	}
	if(opr=="LENGTH") cout<<mx;
	else if(opr=="SEQUENCE" && mx!=0) for(int i=en-mx+1;i<=en;i++) cout<<vec[i]<<' ';
	else cout<<"None";
	return 0;
}
