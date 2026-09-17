#include<iostream>
#include<iomanip>
#include<math.h>

const int N = 40;
double arr[N];
int n;

double calculate(double irr) {
    double cnt = 0;
    for(int i=0;i<=n;i++){
        cnt += (arr[i]/pow((1+irr),i));
    }
    return cnt;
}

bool isClose(double x,double a){
    return fabs(a-x) <= 1e-8 * std::max(x,a);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::cin>>n;
    for(int i=0;i<=n;i++) std::cin>>arr[i];
    double l=-0.9999999,r=1.0,mid=0;
    for(int i=0;i<100;i++){
        mid = l+(r-l)/2.0;
        double cal = calculate(mid);
        if(isClose(cal,0.0)){
            break;
        }
        if(cal > 0) l=mid;
        else if(cal < 0) r = mid;
    }
    std::cout<<std::setprecision(8)<<mid;

    return 0;
}