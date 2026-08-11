#include<iostream>
#include<math.h>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double a,b,c; std::cin>>a>>b>>c;
    double x1 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    double x2 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    std::cout<<round(x1*1e3)/1e3<<' '<<round(x2*1e3)/1e3<<'\n';
    return 0;
}