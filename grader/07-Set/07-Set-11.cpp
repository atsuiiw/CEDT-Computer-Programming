#include<iostream>
#include<string>
#include<set>

std::multiset<char> msa, msb;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string a,b;
    getline(std::cin,a);
    getline(std::cin,b);
    for(auto x:a){
        if(x==' ') continue;
        if(isalpha(x) && isupper(x)) msa.insert(tolower(x));
        else msa.insert(x);
    }
    for(auto x:b){
        if(x==' ') continue;
        if(isalpha(x) && isupper(x)) msb.insert(tolower(x));
        else msb.insert(x);
    }

    if(msa==msb) std::cout<<"YES";
    else std::cout<<"NO";
    return 0;
}