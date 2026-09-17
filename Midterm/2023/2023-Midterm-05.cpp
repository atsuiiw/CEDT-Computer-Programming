#include<iostream>

const int N = 1445;
int qs[N],mx=-1;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=1;i<=n;i++){
        int st,en; std::cin>>st>>en;
        qs[st]++;
        qs[en]--;
    }
    for(int i=1;i<N;i++) qs[i] += qs[i-1], mx = std::max(mx,qs[i]);
    std::cout<<mx;
    return 0;
}