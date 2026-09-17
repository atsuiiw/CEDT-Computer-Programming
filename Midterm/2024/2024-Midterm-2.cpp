#include<iostream>

int calculate(int n) {
    int cnt_A = 0, sum = 0;
    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        if(s=="A") cnt_A++, sum+=11;
        else if(s=="10" || s=="J" || s=="Q" || s=="K") sum+=10;
        else sum+=stoi(s);
    }
    while(sum>21 && cnt_A){
        cnt_A--;
        sum-=10;
    }
    return sum;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; std::cin>>n>>m;
    int resA = calculate(n);
    int resB = calculate(m);
    if(resA > 21 && resB > 21){
        std::cout<<"Draw\n"<<resA<<' '<<resB;
    }
    else if(resA>21 && resB<=21){
        std::cout<<"A\n"<<resA<<' '<<resB;
    }
    else if(resB>21 && resA<=21){
        std::cout<<"B\n"<<resA<<' '<<resB;
    }
    else{
        if(21-resA < 21-resB) std::cout<<"A\n"<<resA<<' '<<resB;
        else if(21-resA > 21-resB) std::cout<<"B\n"<<resA<<' '<<resB;
        else std::cout<<"Draw\n"<<resA<<' '<<resB;
    }
    return 0;
}