#include<iostream>
#include<string>
#include<unordered_map>

using ll = long long;
ll sum;
std::unordered_map<std::string,int> mp;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll n; std::cin>>n;
    for(int i=1;i<=n;i++){
        std::string s; int x;
        std::cin>>s>>x;
        mp[s] = x;
    }
    std::cin.ignore();
    std::string s,res=""; getline(std::cin,s);
    std::string last="";
    for(char x:s){
        if(x==' '){
            std::string idx = res.substr(4);
            if(last!="" && idx!=last) sum+=mp[idx];
            else if(idx==last) sum+=0;
            last = idx;
            res="";
        } else res+=x;
    }
    if(res!=""){
        std::string idx = res.substr(4);
        if(last!="" && idx!=last) sum+=mp[idx];
        else if(idx==last) sum+=0;
    }
    std::cout<<sum;
    return 0;
}