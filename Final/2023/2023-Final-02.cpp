#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

std::unordered_map<std::string,int> mp;
std::vector<std::string> vec[110];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=1;i<=n;i++){
        std::string s; int x;
        std::cin>>s>>x;
        mp[s] = std::max(mp[s],x);
    }
    for(auto x:mp){
        vec[x.second].push_back(x.first);
    }
    int m; std::cin>>m;
    for(int i=100;i>=0 && m;i--){
        if(vec[i].empty()) continue;
        std::cout<<i<<' ';
        for(auto x:vec[i]) std::cout<<x<<' ';
        std::cout<<'\n';
        m--;
    }


    return 0;
}