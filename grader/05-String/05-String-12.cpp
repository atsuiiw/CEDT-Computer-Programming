#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

const int N = 1010;
std::vector<char> result(N,'0');
int mx=1;

void plus(std::string s) {
    int tod = 0;
    int n = s.size();
    mx = std::max(mx,n);
    for(int i=0;i<std::min(mx,n);i++){
        int sum = (s[i]-'0') + (result[i]-'0');
        result[i] = ('0' + ((sum + tod) % 10));
        tod = (sum+tod) / 10;
    }
    if(tod){
        for(int i=std::min(mx,n);i<=mx;i++){
            int sum = (result[i]-'0');
            result[i] = ('0' + ((sum + tod) % 10));
            tod = (sum+tod) / 10;
        }
        if(result[mx]!='0') mx = mx+1;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    while(1){
        std::string s="";
        std::cin>>s;
        if(s=="END") break;
        reverse(s.begin(),s.end());
        plus(s);
    }
    for(int i=mx-1;i>=0;i--) std::cout<<result[i];
    return 0;
}