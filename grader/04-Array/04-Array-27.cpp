#include<iostream>

const int N = 1010;
using pii = std::pair<int,int>;
pii arr[N];
int mn=1e9,mx=-1e9;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>arr[i].first>>arr[i].second;
    std::string s; std::cin>>s;
    if(s=="Zig-Zag"){
        for(int i=1;i<=n;i++){
            if(i%2){
                mn = std::min(mn,arr[i].first);
                mx = std::max(mx,arr[i].second);
            } else {
                mn = std::min(mn,arr[i].second);
                mx = std::max(mx,arr[i].first);
            }
        }
        std::cout<<mn<<' '<<mx;
    } else {
        for(int i=1;i<=n;i++){
            if(i%2){
                mx = std::max(mx,arr[i].first);
                mn = std::min(mn,arr[i].second);
            } else {
                mx = std::max(mx,arr[i].second);
                mn = std::min(mn,arr[i].first);
            }
        }
        std::cout<<mn<<' '<<mx;
    }
    return 0;
}