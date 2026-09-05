#include<iostream>

double avg = 0, x;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n = 0;
    while(1){
        std::cin>>x;
        if(x==-1) break;
        n++;
        avg += x;
    }
    if(n==0) std::cout<<"No Data";
    else std::cout<<round(100.0*avg/n)/100.0;
    return 0;
}