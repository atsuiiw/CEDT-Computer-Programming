#include<iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,res="";
    std::cin>>s;
    for(auto x:s){
        if(isupper(x) || isdigit(x)){
            std::cout<<res<<' ';
            res = "";
        }
        res+=x;
    }
    return 0;
}