#include<iostream>
#include<string>

int alpha[30];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; getline(std::cin,s);
    for(char c:s){
        if(isalpha(c)){
            alpha[tolower(c)-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        if(alpha[i]) std::cout<<(char)('a'+i)<<" -> "<<alpha[i]<<'\n';
    }
    return 0;
}