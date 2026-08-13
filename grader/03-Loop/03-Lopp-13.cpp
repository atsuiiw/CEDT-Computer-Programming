#include<iostream>
#include<string>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s;
    getline(std::cin,s);
    for(auto x:s){
        if(x=='[') std::cout<<'(';
        else if(x=='(') std::cout<<'[';
        else if(x==')') std::cout<<']';
        else if(x==']') std::cout<<')';
        else std::cout<<x;
    }
    return 0;
}