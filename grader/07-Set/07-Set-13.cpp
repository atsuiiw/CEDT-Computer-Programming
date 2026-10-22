#include<iostream>
#include<set>
#include<string>

std::set<std::string> W,L;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string team;
    while(getline(std::cin,team)){
        std::string winner = team.substr(0,team.find(' '));
        std::string loser = team.substr(team.find(' ')+1);
        W.insert(winner);
        L.insert(loser);
    }
    for(auto x:L){
        if(W.find(x)!=W.end()) W.erase(x);
    }
    if(W.size()==0) std::cout<<"None";
    else for(auto x:W) std::cout<<x<<' ';
    return 0;
}