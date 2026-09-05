#include<iostream>
#include<string>
#include<map>
#include<set>

// THIS CODE IS REALLY BAD.
// PRACTICALLY THIS IS THE WORSE CODE POSSIBLE FOR THIS PROBLEM.
// THE OPTIMAL SOLUTION WOULD BE A DSU BUT WE'RE NOT IN DATA-ALGO YET.
// For references, this code runs at around NMlogN (idk i made tf up it might just be NM)


const int N = 1010;
int n,m;

std::map<std::string,std::set<std::string>> mp; // map into integer
std::map<std::string,bool> del; // map into integer
std::map<std::string,std::string> p;


int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::string id,dpt; std::cin>>id>>dpt;
        mp[dpt].insert(id);
        p[id] = dpt;
    }

    while(m--){
        int opr; std::cin>>opr;
        std::string a,b; std::cin>>a>>b;
        if(opr==1){
            std::set<std::string> newVec;
            if(del[b]) del[b] = false;
            for(auto x:mp[p[a]]){
                if(x==a) continue;
                newVec.insert(x);
            }
            mp[p[a]] = newVec;
            p[a] = b;
            mp[b].insert(a);
        } else {
            for(auto x:mp[a]){
                mp[b].insert(x);
            }
            mp[a].clear();
            del[a] = true;
        }
    }
    for(auto x:mp){
        if(del[x.first]) continue;
        std::cout<<x.first<<": ";
        for(auto c:x.second) std::cout<<c<<' ';
        std::cout<<'\n';
    }
    return 0;
}