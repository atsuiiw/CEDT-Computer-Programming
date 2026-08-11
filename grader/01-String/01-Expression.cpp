#include<iostream>
#include<math.h>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double y = (M_PI - (3628800 / pow(8,8)) + pow(log(9.7)/log(M_E),7/sqrt(71)-sin(40 * M_PI / 180))) / pow(1.2,pow(2.3,1.0/3.0));
    std::cout<<y<<'\n';
    return 0;
}