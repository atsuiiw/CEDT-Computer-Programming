#include<iostream>
#include<string>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int h; std::cin>>h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<h+i;j++){
            if(j==h-i+1 || j==h+i-1 || i==h) std::cout<<"*";
            else std::cout<<".";
        }
        std::cout<<'\n';
    }
    return 0;
}