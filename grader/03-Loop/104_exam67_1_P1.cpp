#include<iostream>
using ll = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll N,d=2; std::cin>>N;
    if(N<2){
        std::cout<<"No prime factors for numbers less than 2.";
        return 0;
    }
    while(N>1){
        if(d*d > N) break;
        while(N%d==0){
            N/=d;
            std::cout<<d<<' ';
        }
        d++;
    }
    if(N!=1) std::cout<<N;
    return 0;
}