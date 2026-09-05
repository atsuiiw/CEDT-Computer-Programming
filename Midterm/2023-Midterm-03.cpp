#include<iostream>
#include<math.h>
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

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);

    int n; std::cin>>n;
    for(int i=1;i<=n;i++){
        ll a,N,b,M;
        std::cin>>a>>N>>b>>M;
        ll res = 0;
        for(int i=1;i<=N;i++) res = res*10 + a;
        for(int i=1;i<=M;i++) res = res*10 + b;
        std::cout<<(isPrime(res) ? "YES" : "NO") <<'\n';
    }
    return 0;
}