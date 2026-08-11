#include<iostream>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    if(n>2000) std::cout<<"Reject";
    else if(n>1000) std::cout<<58;
    else if(n>500) std::cout<<38;
    else if(n>250) std::cout<<28;
    else if(n>100) std::cout<<22;
    else std::cout<<18;
    return 0;
}