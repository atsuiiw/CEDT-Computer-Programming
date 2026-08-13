#include<iostream>
#include<math.h>
#include<string>

using ll = long long;

ll power(int n,int x){
    if(x==0) return 1;
    ll cal = power(n,x/2);
    if(x%2) return cal*cal*n;
    else return cal*cal;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string a,b; std::cin>>a>>b;
    int lena = a.size(), lenb = b.size();
    ll sum = 0;
    if(a.size()!=b.size()){
        for(int i=lena+1;i<=lenb-1;i++){
            sum+=(9*power(10,i-1)*i);
        }
        sum+=(power(10,a.size()) - stol(a)) * a.size();
        sum+=(stol(b) - power(10,b.size()-1) + 1) * b.size();
    }
    else {
        sum = (stol(b)-stol(a)+1) * a.size();
    }
    std::cout<<sum;
    // std::string temp = "012345678910111213141516171819";
    // std::cout<<temp.size();
    return 0;
}

/*
1 = 10
2 = 90
3 = 900
4 = 9000
5 = 90000
...
17 = 9 * pow(10,16);

a number with n digits will have 9 * pow(10,n-1) numbers in total (except 1 with 10)
which means there are 


012345678910111213141516171819
*/