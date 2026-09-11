#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,res=""; getline(std::cin,s);
    std::vector<int> e;
    s += ' ';
    for(auto x:s){
        if(x==' '){
            if(find(e.begin(),e.end(),stoi(res)) == e.end()){
                e.push_back(stoi(res));
            }
            res = "";
            continue;
        }
        res += x;
    }
    std::cout<<e.size()<<'\n';
    sort(e.begin(),e.end());
    for(int i=0;i<std::min((int)e.size(),10);i++){
        std::cout<<e[i]<<' ';
    }
    return 0;
}