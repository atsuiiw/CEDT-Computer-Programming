#include<bits/stdc++.h>
using namespace std;
using ll = long long;


const int MOD = 1e9+7;
const int N = 1010;
queue<char> opr;
queue<string> value;
unordered_map<char,ll> mp;
ll sum = 0;

ll convert(string s){
    ll res = 0;
    for(auto x:s){
        ll addition = 0;
        if(!isdigit(x)) addition = mp[x];
        else addition = x-'0';
        res = (res*10 + addition) % MOD;
    }
    return res;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    string s,res; cin>>s;
    s += ' ';
    for(auto x:s){
        if(x=='+' || x=='*' || x=='-' || x==' '){
            value.push(res);
            if(x!=' ') opr.push(x);
            res = "";
            continue;
        }
        res += x;
    }
    int m; cin>>m;
    while(m--){
        char A; ll B;
        cin>>A>>B;
        mp[A] = B;
    }
    sum = convert(value.front()) % MOD; value.pop();
    // cout<<value.size()<<' '<<opr.size()<<'\n';
    while(!opr.empty()){
        char o = opr.front(); opr.pop();
        string v = value.front(); value.pop();
        if(o=='+') sum = ((sum + convert(v)) % MOD + MOD) % MOD;
        else if(o=='-') sum = ((sum - convert(v)) % MOD + MOD) % MOD;
        else if(o=='*') sum = ((sum * convert(v)) % MOD + MOD) % MOD;
    }
    cout<<sum;
    return 0;
}