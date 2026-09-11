#include<iostream>

const int N = 60;
int val[N], sum;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; std::cin>>n>>m;
    for(int i=0;i<n;i++) std::cin>>val[i], sum+=val[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=m;j++){
            if(sum - val[i] - val[j] == m){
                std::cout<<i<<' '<<val[i]<<'\n'<<j<<' '<<val[j];
                return 0;
            }
        }
    }
    return 0;
}