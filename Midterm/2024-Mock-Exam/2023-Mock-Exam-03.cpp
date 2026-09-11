#include<iostream>
#include<string>

using ll = long long;
ll cnt;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll cost; std::cin>>cost;
    std::string s,res="";
    std::cin.ignore();
    getline(std::cin,s);
    s += ' ';
    for(auto x:s){
        if(x == ' '){
            cnt += stoi(res.substr(1));
            res = "";
            continue;
        }
        res += x;
    }
    std::cout<<cost * cnt;
    return 0;
}