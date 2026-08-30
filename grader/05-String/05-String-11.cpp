#include<iostream>
#include<string>

std::string s;
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    while(getline(std::cin,s)){
        bool isValid = false;
        for(char x:s){
            if(!isalpha(x) && x!=' '){
                isValid ^= 1;
                continue;
            }
            if(isValid) std::cout<<x;
        }
        std::cout<<'\n';
    }
    return 0;
}