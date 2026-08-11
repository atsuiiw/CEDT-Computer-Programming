#include<iostream>
#include<math.h>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double a,b,c,d; std::cin>>a>>b>>c>>d;
    double mx = std::max({a,b,c,d}), mn = std::min({a,b,c,d});
    std::cout<<round((a+b+c+d - mn - mx)/2 * 100.0)/100.0;
    return 0;
}