#include<iostream>
#include<vector>

std::vector<int> vec;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    if(n & 1) vec.push_back(n);
    while(n!=1){
        if(n%2==0){
            n/=2;
            vec.push_back(n);
        }
        else {
            n = 3*n + 1;
            vec.push_back(n);
        }
    }
    for(int i=std::max(0,(int)vec.size()-15);i<vec.size();i++) std::cout<<vec[i]<<(i!=vec.size()-1 ? "->" : ""); 
    return 0;
}