#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 22;
pair<int,string> a[N];
int n,k;
string V[N];

vector<string> vec;

void sol(int res, int state, int last) {
    // cout<<res<<' '<<state<<' '<<last<<'\n';
    if(res > k) return ;
    if(res == k){
        string answer = "";
        for(int i=0;i<state;i++){
            answer += V[i];
            if(i<state-1) answer +=' ';
        }
        vec.push_back(answer);
        return ;
    }
    for(int i=last;i<n;i++){
        V[state] = a[i].second;
        sol(res + a[i].first, state+1, i+1);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>k>>n;
    for(int i=0;i<n;i++){
        string s; int val; cin>>s>>val;
        a[i] = {val,s};
    }
    sort(a,a+n);
    sol(0,0,0);
    cout<<vec.size()<<'\n';
    int cnt = 1;
    for(auto x:vec) cout<<(cnt++)<<' '<<x<<'\n';
    return 0;
}