#include<iostream>
#include<math.h>
#include<vector>

using ll = long long;
std::vector<ll> ans;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll n; std::cin>>n;
    ll temp = n;
    while(temp%2==0){
        temp/=2;
        ans.push_back(2);
    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(temp%i==0){
            temp/=i;
            ans.push_back(i);
        }
    }
    if(temp!=1) ans.push_back(temp);
    for(int i=0;i<ans.size();i++) std::cout<<ans[i]<<(i==ans.size()-1 ? "" : "*");

    return 0;
}