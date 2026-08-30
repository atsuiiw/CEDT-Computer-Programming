#include<iostream>
#include<string>

bool isSwap = false;
int mx=0,st=0;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string a,b; std::cin>>a>>b;
    if(b.size() > a.size()) std::swap(a,b), isSwap = true;
    int n=a.size(),m=b.size();
    for(int i=0;i<n;i++){ // offset
        int cnt = 0;
        for(int j=0;j<m;j++){ // run
            if(b[j]==a[i+j]) cnt++;
        }
        if(cnt > mx){
            mx = cnt;
            st = i;
        }
    }
    if(isSwap){
        for(int i=1;i<=st;i++) std::cout<<"-";
        std::cout<<b<<'\n';
        std::cout<<a;
    }
    else {
        std::cout<<a<<'\n';
        for(int i=1;i<=st;i++) std::cout<<"-";
        std::cout<<b;
    }
    std::cout<<'\n'<<mx;
    return 0;
}