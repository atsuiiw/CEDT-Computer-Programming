#include<iostream>
#include<vector>
#include<algorithm>

std::string shift (std::string s,int idx) {
    std::string first = s.substr(0,idx),last = s.substr(idx);
    return last + first;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    s += "$";
    std::vector<std::string> vec;
    int n = s.size();

    for(int i=0;i<n;i++){
        vec.push_back(shift(s,i));
    }
    sort(vec.begin(),vec.end());
    for(auto x:vec) std::cout<<x[n-1];
    return 0;
}