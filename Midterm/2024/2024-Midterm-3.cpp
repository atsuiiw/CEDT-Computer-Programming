#include<iostream>
#include<iomanip>

const int N = 35;
double val[N];

bool check(double a,double x) {
    return fabs(a-x) <= std::max(a,x) * 1e-8;
}

double power(double base,int m) {
    double res = 1;
    for(int i=1;i<=m;i++){
        res *= base;
    }
    return res;
}

double sum(double IRR,int n) {
    double res = 0;
    for(int i=0;i<=n;i++){
        res += (val[i] / power(1.0+IRR,i));
    }
    return res;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n;
    std::cin>>n;
    for(int i=0;i<=n;i++) std::cin>>val[i];
    double l=-0.9999999, r=1.0, mid = (l+r)/2;
    for(int i=0;i<100;i++){
        mid = l+(r-l)/2;
        double sumFinal = sum(mid,n);
        bool ch = check(0.0,sumFinal);
        if(ch){
            std::cout<<mid;
            break;
        }
        if(sumFinal > 0) l = mid;
        else if(sumFinal < 0) r = mid;
    }
    std::cout<<std::setprecision(8)<<mid<<'\n';
    return 0;
}