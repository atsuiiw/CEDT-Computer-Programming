#include<iostream>
#include<string>

const int N = 1010;

bool check(std::string s){
    bool preCheck = true;
    for(char x:s){
        preCheck &= isdigit(x);
    }
    if(s.size() != 2 || !preCheck) return 0;

    int code = std::stoi(s);
    if(code<0 || (code>40 && code<51) || (code>2 && code<20) || (code==52 || code==54 || code==56 || code==57) || code>58) return 0;
    return 1;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    std::cout<<(check(s) ? "OK" : "Error");
    return 0;
}