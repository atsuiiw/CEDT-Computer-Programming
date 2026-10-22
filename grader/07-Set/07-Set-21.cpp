#include<iostream>
#include<set>

std::set<int> s;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int K,n,cnt=0; std::cin>>K;
    while(std::cin>>n){
        if(s.find(K-n) != s.end()) cnt++;
        s.insert(n);
    }
    std::cout<<cnt;
    return 0;
}