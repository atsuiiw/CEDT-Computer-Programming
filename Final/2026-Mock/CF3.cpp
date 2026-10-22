#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 102;
pair<string,int> a[N];

vector<pair<string,string>> best,worst;
int mn=1e7,mx=0;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum = abs(a[i].second + a[j].second - m);
            // cout<<i<<' '<<j<<' '<<sum<<'\n';
            if(sum >= mx){
                if(sum > mx) worst.clear();
                worst.push_back({a[i].first,a[j].first});
                mx = sum;
            }
            if(sum <= mn){
                if(sum < mn) best.clear();
                best.push_back({a[i].first,a[j].first});
                mn = sum;
            }
        }
    }
    cout<<"Best Pair:\n";
    for(auto x:best) cout<<x.first<<' '<<x.second<<'\n';
    cout<<"Worst Pair:\n";
    for(auto x:worst) cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}