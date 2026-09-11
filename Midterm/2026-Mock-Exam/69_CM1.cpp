#include<bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    double a,b,c; int n;
    cin>>a>>b>>c>>n;
    while(a<=b){
        if(b > c){
            a = expm1(b/a) + 1 + (a/b);
            b = b + c/b;
        }
        else if(a > c){
            b = b * sin(b);
            c = c - (log(a));
        }
        else {
            c = c - b/a;
            a = (1/cos(b)) + a/b;
        }
    }
    a = fabs(a);
    if(a < 1) a = 1/a;
    double l=0,r=a;
    double x;
    while(r-l >= 1e-5){
        x = (l+r)/2;
        if(pow(x,n) < a) l=x;
        else r=x;
    }
    cout<<fixed<<setprecision(5)<<"a: "<<a<<'\n'<<"b: "<<b<<'\n'<<"c: "<<c<<'\n'<<"x: "<<x<<'\n';
    return 0;
}