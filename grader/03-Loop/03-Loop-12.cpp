#include<iostream>
#include<math.h>

bool compare(double a, double x) {
    return abs(a-x) <= 1.0 / pow(10,10) * std::max(a,x);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double a; std::cin>>a;
    double l=0,r=10,mid=5;
    while(!compare(a,pow(10,mid))){
        mid = (l+r)/2.0;
        double cal = pow(10,mid);
        if(cal > a) r=mid;
        else l=mid;
    }
    std::cout<<l;

    return 0;
}