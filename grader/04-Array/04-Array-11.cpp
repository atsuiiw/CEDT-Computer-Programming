#include<iostream>
#include<string>
#include<vector>

bool bs[10];
std::vector<int> ans;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; getline(std::cin,s);
    for(char x:s){
        if(isdigit(x)) bs[x-'0'] = true;
    }
    for(int i=0;i<10;i++) if(!bs[i]) ans.push_back(i);
    if(ans.size()==0) std::cout<<"None";
    for(int i=0;i<ans.size();i++) std::cout<<ans[i]<<(i!=ans.size()-1 ? "," : "");
    return 0;
}