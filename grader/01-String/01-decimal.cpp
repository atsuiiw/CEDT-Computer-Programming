#include<iostream>
#include<math.h>
using ll = long long;

ll divider,frac;
ll gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string a,b,c; std::cin>>a>>b>>c;
    ll lenB = b.size();
    ll lenC = c.size();

    frac = std::stoi(a+b+c) - std::stoi(b+c);
    divider = pow(10,lenB + lenC) - pow(10,lenB);
    
    ll GCD = gcd(frac,divider);

    std::cout<<frac/GCD<<" / "<<divider/GCD;
    return 0;
}