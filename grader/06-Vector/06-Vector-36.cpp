#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

struct A{
    std::string id,s;
    bool operator < (const A&o) const {
        if(s[0] == o.s[0]) return s.size() > o.s.size();
        return s[0] < o.s[0];
    }
};
std::vector<A> vec;
std::unordered_map<std::string,int> mp; // map indexes

std::string upgrade(std::string s) {
    if(s.size()==1){
        if(s=="F") return "D";
        if(s=="A") return "A";
        return s+'+';
    }
    else {
        if(s[0]=='B') return "A";
        if(s[0]=='C') return "B";
        if(s[0]=='D') return "C";
    }
}
std::string downgrade(std::string s) {
    if(s.size()==1){
        if(s=="F") return s;
        if(s=="D") return "F";
        else return std::string() + (char)(s[0]+1) + '+';
    }
    else {
        return std::string() + s[0];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=0;i<n;i++){
        std::string id,s; std::cin>>id>>s;
        vec.push_back({id,s});
        mp[id] = i;
    }
    std::string s,temp,res="";
    while(std::cin>>s){
        int index = mp[s.substr(0,s.size()-1)];
        int ud = (s[s.size()-1] == '+') ? 1 : 0;
        if(ud){
            vec[index].s = upgrade(vec[index].s);
        }
        else {
            vec[index].s = downgrade(vec[index].s);
        }
    }
    sort(vec.begin(),vec.end());
    for(auto x:vec){
        std::cout<<x.id<<' '<<x.s<<'\n';
    }
    return 0;
}