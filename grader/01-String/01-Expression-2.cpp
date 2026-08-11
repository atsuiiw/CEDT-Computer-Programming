#include<iostream>
#include<math.h>
#include<iomanip>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double n; std::cin>>n;
    double power = sqrt(log((n+1)*(n+1))/log(M_E));
    double y = pow(n,power) / (10-n);
    std::cout<<std::fixed<<std::setprecision(6)<<y;
    return 0;
}