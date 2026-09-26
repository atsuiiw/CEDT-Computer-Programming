#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
bitset<N> bs;

int mx,sum;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,g,r; cin>>g>>r>>n;

	for(int i=g;i<N;i+=g+r) for(int j=0;i+j<N && j<r;j++) bs[i+j] = true;

	int idx =0;
	for(int i=1;i<=n;i++){
		int val; cin>>val;
		idx = val;
		while(bs[idx]) idx++;
		bs[idx] = 1;
		sum += idx-val;
		mx = max(mx,idx-val);
	}
	cout<<sum<<'\n'<<mx;


	return 0;
}
