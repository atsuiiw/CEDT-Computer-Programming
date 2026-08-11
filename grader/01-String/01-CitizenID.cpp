#include<iostream>
#include<string>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    int len = s.size(),sum=0;
    for(int i=0;i<len;i++){
        std::cout<<s[i];
        sum += (s[i]-'0')*(13-i);
        if(i==0 || i==4 || i==9) std::cout<<"-";
    }
    std::cout<<"-"<<(11-sum%11)%10;
    return 0;
}