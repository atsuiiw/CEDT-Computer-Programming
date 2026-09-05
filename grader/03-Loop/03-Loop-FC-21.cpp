#include<iostream>


double t=1,k=1;
double cal(double t){
    return (1.0*t*(365.0-(k-1)))/365.0;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double p; std::cin>>p;
    t = cal(t);
    while(1-t<p){
        k++;
        t = cal(t);
    }
    std::cout<<k;
    return 0;
}