#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

struct A{
    int id;
    std::string s;
};
std::vector<A> vec;
std::unordered_map<int,int> mp; // map indexes

std::string upgrade(std::string s) {
    if(s.size()==1){
        if(s=="F") return "D";
        if(s=="A") return s;
        return s+'+';
    }
    else {
        if(s[0]=='B') return "A";
        if(s[0]=='C') return "B";
        if(s[0]=='D') return "C";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int idx = 0;
    while(1){
        std::string id,s; std::cin>>id;
        if(id=="q") break;
        std::cin>>s;
        vec.push_back({stoi(id),s});
        mp[stoi(id)] = idx;
        idx++;
    }
    std::string s,res="";
    std::cin.ignore();
    getline(std::cin,s);
    s+=' ';
    for(auto x:s){
        if(x==' '){
            int index = mp[stoi(res)];
            vec[index].s = upgrade(vec[index].s);
            res = "";
            // std::cout<<index<<'\n';
            continue;
        }
        res+=x;
    }
    for(auto x:vec){
        std::cout<<x.id<<' '<<x.s<<'\n';
    }
    return 0;
}