#include<iostream>
#include<math.h>
using ll = long long;

const ll B = 1e9, M = 1e6, K =1e3;

double printDecimal(ll x,ll D){
    if(x/D >= 10) return round(1.0*x/D);
    else return round(10.0*x/D)/10.0;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll x; std::cin>>x;
    
    if(x>=B) std::cout<<printDecimal(x,B)<<"B";
    else if(x>=M) std::cout<<printDecimal(x,M)<<"M";
    else if(x>=K) std::cout<<printDecimal(x,K)<<"K";
    else std::cout<<x;
    return 0;
}