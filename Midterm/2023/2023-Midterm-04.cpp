#include<iostream>
using ll = long long;

bool isPrime(ll n){
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i<=sqrt(n);i+=2){
        if(n%(i)==0 || n%(i+1)==0) return false;
    }
    return true;
}

void sol() {
    ll A,N,B,M; std::cin>>A>>N>>B>>M;

    // constructing the number
    ll res = 0;
    for(int i=1;i<=N;i++) res = res*10 + A;
    for(int i=1;i<=M;i++) res = res*10 + B;

    if(isPrime(res)) std::cout<<"YES\n";
    else std::cout<<"NO\n";

}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int q; std::cin>>q;
    while(q--) sol();
    return 0;
}