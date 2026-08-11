#include<iostream>

const int N = 1010;

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    if(n>0) std::cout<<"positive";
    else if(n==0) std::cout<<"zero";
    else std::cout<<"negative";
    std::cout<<'\n'<<(n%2 ? "odd" : "even");
    return 0;
}