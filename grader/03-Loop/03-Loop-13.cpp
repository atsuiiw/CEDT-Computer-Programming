#include<iostream>
#include<string>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s;
    int n=0;
    while(getline(std::cin,s)) n++;
    std::cout<<n;
    return 0;
}