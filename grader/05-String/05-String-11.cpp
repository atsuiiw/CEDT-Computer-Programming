#include<iostream>
#include<string>

std::string s;
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    while(getline(std::cin,s)){
        bool isValid = false;
        char decoder = '#';
        for(int i=s.size()-1;i>=0;i--){
            if(!isalpha(s[i])){
                decoder = s[i];
                break;
            }
        }
        for(char x:s){
            if(x==decoder){
                isValid ^= 1;
                continue;
            }
            if(isValid) std::cout<<x;
        }
        std::cout<<'\n';
    }
    return 0;
}