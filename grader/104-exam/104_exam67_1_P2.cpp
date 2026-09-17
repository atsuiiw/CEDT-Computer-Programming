#include<iostream>

int arr[2][5];

int convert(std::string s){
    if(s.size()==1 && isdigit(s[0])) return s[0]-'0';
    else return 10;
}
int bestSum(int hand[], int n){
    int base = 0, aces = 0;
    for(int i = 1; i <= n; i++){
        if(hand[i] == -1) aces++;
        else base += hand[i];
    }
    int sum = base + aces * 11;
    while(sum > 21 && aces > 0){
        sum -= 10;
        aces--;
    }
    return sum;
}

int sum_a,sum_b;
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::string s; std::cin>>s;
        if(s=="A") arr[0][i] = -1;
        else arr[0][i] = convert(s);
    }
    for(int i=1;i<=m;i++){
        std::string s; std::cin>>s;
        if(s=="A") arr[1][i] = -1;
        else arr[1][i] = convert(s);
    }
    // for(int i=1;i<=n;i++) std::cout<<arr[0][i]<<' ';
    // std::cout<<'\n';
    // for(int i=1;i<=m;i++) std::cout<<arr[1][i]<<' ';
    // std::cout<<'\n';
    sum_a = bestSum(arr[0],n);
    sum_b = bestSum(arr[1],m);
    bool cha=true,chb=true;
    if(sum_a > 21) cha = false;
    if(sum_b > 21) chb = false;
    if(!cha && !chb){
        std::cout<<"Draw\n"<<sum_a<<' '<<sum_b<<'\n';
    }
    else if(cha && !chb) std::cout<<"A\n"<<sum_a<<' '<<sum_b;
    else if(!cha && chb) std::cout<<"B\n"<<sum_a<<' '<<sum_b;
    else {
        std::cout<<(sum_a > sum_b ? "A" : (sum_a==sum_b) ? "Draw" : "B")<<'\n'<<sum_a<<' '<<sum_b;
    }
    return 0;
}