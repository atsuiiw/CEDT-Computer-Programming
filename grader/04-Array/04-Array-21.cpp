#include<iostream>
#include<vector>
#include<iomanip>

int n;
double sum = 0;
std::vector<int> arr;
double recur(int state,int end) {
    if(state == end) return arr[state];
    return arr[state] + 1.0/(recur(state+1,end));
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) std::cin>>arr[i];
    for(int i=0;i<n;i++) std::cout<<std::setprecision(10)<<recur(0,i)<<'\n';
    return 0;
}