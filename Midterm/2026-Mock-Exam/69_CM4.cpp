#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int GCD(int a,int b){
    if(a==b) return a;
    if(b%a==0) return a;

    int result = min(a,b);
    while(result > 1){
        if(a % result == 0 && b % result == 0){
            break;
        }
        result--;
    }
    return result;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> vec(n);
    for(auto& x:vec) cin>>x;

    vector<int> best = vec;
    int idBest = 1;
    // cout<<GCD(6,8)<<'\n';
    for(int i=2;i<n;i++){
        // cout<<i<<' '<<GCD(i,n)<<'\n';
        if(GCD(i,n) != 1) continue;
        
        vector<int> temp;
        
        // jump n times
        int jump = 0;
        for(int j=1;j<=n;j++){
            temp.push_back(vec[jump]);
            jump = (jump + i) % n;
        }
        if(temp > best){
            best = temp;
            idBest = i;
        }
    }
    cout<<idBest<<'\n';
    for(auto x:best) cout<<x<<' ';
    return 0;
}