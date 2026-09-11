#include<iostream>

const int N = 210;
int qs[N],cnt;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>qs[i], qs[i]+=qs[i-1];
    for(int len=1;len<n;len++){
        int target = (1+len) * len / 2;
        for(int i=1;i<=n-len+1;i++){
            if(qs[i+len-1]-qs[i-1] == target){
                cnt++;
            }
        }
    }
    std::cout<<cnt;
    return 0;
}