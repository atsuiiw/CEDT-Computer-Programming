#include<iostream>
using ll = long long;

void sol(){
    int n; std::cin>>n;
    ll mn = 1e18, sum = 0;
    for(int i=1;i<=n;i++){
        ll x; std::cin>>x;
        sum+=x;
        mn = std::min(mn,x);
    }
    std::cout<<sum-mn<<'\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int q; std::cin>>q;
    while(q--) sol();
    return 0;
}