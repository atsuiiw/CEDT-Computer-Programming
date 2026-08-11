#include<iostream>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double n; std::cin>>n;
    if(n>=80) std::cout<<"A";
    else if(n>=70) std::cout<<"B";
    else if(n>=60) std::cout<<"C";
    else if(n>=50) std::cout<<"D";
    else std::cout<<"F";
    return 0;
}