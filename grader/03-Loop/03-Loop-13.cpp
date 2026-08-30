#include<iostream>
#include<string>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string a,b; 
    getline(std::cin,a);
    getline(std::cin,b);
    int idx = 0, cnt = 0;
    std::string res = "";
    for(auto x:b){
        if(x=='(' || x==')' || x=='\'' || x==',' || x=='.' || x=='\"'){
            res +=' ';
            continue;
        }
        res += x;
    }
    while(true){
        size_t pos = res.find(a, idx);
        if(pos == std::string::npos) break;

        bool leftOk  = (pos == 0) || !isalpha((char)res[pos - 1]);
        bool rightOk = (pos + a.size() == res.size()) || !isalpha((char)res[pos + a.size()]);

        if(leftOk && rightOk) cnt++;
        idx = pos + 1;
    }
    std::cout<<cnt;
    return 0;
}