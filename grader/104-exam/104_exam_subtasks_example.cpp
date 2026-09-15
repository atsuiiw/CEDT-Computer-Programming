#include<iostream>
#include<string>
#include<algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    int q; std::cin>>q;
    while(q--){
        int M,K; std::cin>>M>>K;
        K %= s.size()-1;
        std::string exclude = s.substr(0,M) + s.substr(M+1);
        std::string combine = exclude.substr(K) + exclude.substr(0,K);
        combine.insert(combine.begin()+M, s[M]);
        s = combine;
    }
    std::cout<<s;
    return 0;
}