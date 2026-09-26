#include<iostream>
#include<set>

std::set<int> s;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,idx=0;
    bool ch = false;
    while(std::cin>>n){
        idx++;
        // std::cout<<n<<' '<<idx<<'\n';
        if(s.find(n)!=s.end()){
            std::cout<<idx;
            ch = true;
            break;
        }
        s.insert(n);
    }
    if(!ch) std::cout<<-1;
    return 0;
}