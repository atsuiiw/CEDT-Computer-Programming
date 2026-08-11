#include<iostream>

int dom[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
int dom2[] = {0,31,60,91,121,152,182,213,244,274,305,335,366};

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int d,m,y; std::cin>>d>>m>>y;
    int gy = y-543;
    if((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) std::cout<<dom2[m-1] + d;
    else std::cout<<dom[m-1] + d;

    return 0;
}