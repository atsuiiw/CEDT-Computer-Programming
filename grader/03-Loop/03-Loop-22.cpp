#include<iostream>
#include<math.h>
#include<bitset>

using ll = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll n; std::cin>>n;
    while(n%2==0){
        n/=2;
        std::cout<<2<<(n==1 ? "":"*");
    }
    ll temp = n;
    for(int i=3;i<=n/2;i+=2){
        while(temp%i==0){
            temp/=i;
            std::cout<<i<<(temp==1 ? "":"*");
        }
    }

    return 0;
}