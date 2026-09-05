#include<iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,res="";
    std::cin>>s;
    s+="A";
    res = s[0];
    for(int i=1;i<s.size();i++){
        char x = s[i];
        if(isupper(x) || (isdigit(x) != isdigit(s[i-1]))){
            std::cout<<res<<(i!=s.size()-1 ? ", ": "");
            res = "";
        }
        res+=x;
    }
    return 0;
}