#include<iostream>

// no vector allowed :(

bool isZigZag = 1;
struct A{
    int a,b,c,d; //zigzag mx,mn - zagzig mx,mn
    A() {
        a=c = 2e9;
        b=d = -2e9;
    }
} zz;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    for(int i=1;1;i++){
        int x,y; std::cin>>x;
        if(x==-998 || x==-999){
            isZigZag = (x==-998);
            break;
        }
        std::cin>>y;

        // store
        zz.a = std::min(zz.a, (i&1 ? x : y));
        zz.b = std::max(zz.b, (i&1 ? y : x));
        zz.c = std::min(zz.c, (i&1 ? y : x));
        zz.d = std::max(zz.d, (i&1 ? x : y));
    }
    if(isZigZag) std::cout<<zz.a<<' '<<zz.b;
    else std::cout<<zz.c<<' '<<zz.d;
    return 0;
}