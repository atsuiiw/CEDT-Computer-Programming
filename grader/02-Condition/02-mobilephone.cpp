#include<iostream>
#include<string>

bool check(std::string s){
    if(s.size()!=10) return 0;
    if(s[0]=='0' && ((s[1]=='6') || (s[1]=='9') || (s[1]=='8'))) return 1;
    else return 0;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    std::cout<<(check(s) ? "Mobile number" : "Not a mobile number");
    return 0;
}
