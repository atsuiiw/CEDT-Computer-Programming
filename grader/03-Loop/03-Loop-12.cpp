#include<iostream>
#include<math.h>

bool compare(double a, double x) {
    return std::fabs(a-x) <= 1.0 / pow(10,10) * std::max(a,x);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double a; std::cin>>a;
    double l=0,r=17,mid=8;
    while(!compare(a,pow(10,mid))){
        double cal = pow(10,mid);
        if(cal > a) r=mid;
        else if(cal < a) l=mid;
        mid = (l+r)/2.0;
    }
    std::cout<<mid;

    return 0;
}