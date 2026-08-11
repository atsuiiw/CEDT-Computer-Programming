#include<iostream>
#include<iomanip>
#include<cmath>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double W,H; std::cin>>W>>H;
    std::cout<<std::setprecision(15);
    std::cout<<sqrt(W*H) / 60<<'\n';
    std::cout<<0.024265 * pow(W,0.5378) * pow(H,0.3964)<<'\n';
    std::cout<<0.0333 * pow(W,0.6157 - (0.0188 * log10(W))) * pow(H,0.3);
    return 0;
}