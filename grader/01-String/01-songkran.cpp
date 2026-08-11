#include<iostream>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int y; std::cin>>y;
    y-=543;
    y%=100;
    std::cout<<(y + y/4 +11) % 7;
    return 0;
}