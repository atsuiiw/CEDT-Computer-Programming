#include<iostream>
#include<string>
#include<vector>

using pci = std::pair<char,int>;
std::vector<pci> vec;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    int n; std::cin>>n;
    for(char x:s){
        if(vec.empty()) vec.push_back({x,1});
        else{
            if(vec.back().first == x){
                int cnt = vec.back().second;
                vec.pop_back();
                vec.push_back({x,cnt+1});
            }
            else vec.push_back({x,1});
        }
    }
    for(pci x:vec){
        std::cout<<x.first<<' '<<x.second<<' ';
    }

    return 0;
}