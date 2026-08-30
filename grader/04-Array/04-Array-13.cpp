#include<iostream>
#include<vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    std::vector<int> vec(n);
    for(int i=0;i<n;i++) std::cin>>vec[i];

    int res = 0;
    for(int i=1;i<n-1;i++) if(vec[i]>vec[i-1] && vec[i]>vec[i+1]) res++;
    std::cout<<res;
    return 0;
}