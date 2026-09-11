#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

struct A{
    std::string id;
    double val;
    bool operator < (const A&o) const{
        if(val!=o.val) return val > o.val;
        return id < o.id;
    }
};
std::vector<A> vec;
std::unordered_map<std::string,double> mp,cnt;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,res="";
    while(getline(std::cin,s)){
        if(s=="END") break;
        std::string id = s.substr(0,s.find(' '));
        double val = stod(s.substr(s.find(' ')));
        // std::cout<<id<<' '<<val<<'\n';
        mp[id] = val;
    }
    getline(std::cin,s);
    s+=' ';
    for(auto x:s){
        if(x==' '){
            if(mp.find(res) != mp.end()) cnt[res] += mp[res];
            res = "";
            continue;
        }
        res += x;
    }
    for(auto x:cnt) vec.push_back({x.first,x.second});
    sort(vec.begin(),vec.end());
    if(vec.size()==0) std::cout<<"No Sales";
    else 
        for(int i=0;i<std::min(3,(int)vec.size());i++) std::cout<<vec[i].id<<' '<<vec[i].val<<'\n';
    return 0;
}