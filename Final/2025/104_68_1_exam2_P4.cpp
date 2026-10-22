#include<iostream>
#include<vector>
#include<algorithm>

const int N = 2010;
int dp[N]; // number of ways number i can be achieve
int temp[N];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; std::cin>>m>>n;
    std::vector<std::pair<int,int>> vec(m);
    for(auto& x:vec) std::cin>>x.first>>x.second;
    sort(vec.begin(),vec.end());
    
    dp[0] = 1;
    for(auto [x,c]:vec){
        for(int i=0;i<=n;i++){
            if(!dp[i]) continue;
            for(int mul=1;mul<=c;mul++){
                if(i + mul*x > n) continue;
                temp[mul*x + i] += dp[i];
            }
        }
        for(int i=0;i<=n;i++) dp[i] += temp[i], temp[i] = 0;
    }
    std::cout<<dp[n];
    return 0;
}