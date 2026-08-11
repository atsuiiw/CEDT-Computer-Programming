#include<iostream>
#include<math.h>

const int N = 1010;

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int xe,ye,re,rp,xm,ym;
    std::cin>>xe>>ye>>re>>rp>>xm>>ym;
    double A = xm-xe;
    double B = ym-ye;
    double C = sqrt(A*A + B*B);
    double c = re-rp;
    double b = B/C * c;
    double a = A/C * c;
    std::cout << round(xe+a) << ' ' << round(ye+b) << '\n';
    return 0;
}