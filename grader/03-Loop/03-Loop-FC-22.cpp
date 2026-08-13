#include<iostream>

int sum_a,sum_b,sum_c,m;
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,k; std::cin>>n>>k;
    if(n & 1){
        while(m<k){
            int a,b,c; std::cin>>a>>b>>c;
            if(a==b){
                if(a==b && b==c){
                    if(a+b > k){
                        sum_a += 1;
                        sum_b += 2;
                        sum_c -= 3;
                    }
                    else {
                        sum_a -= 3;
                        sum_b -= 2;
                        sum_c += 1;
                    }
                }
                else {
                    sum_a += 2;
                    sum_b -=3;
                }
            }
            m+=1;
        }
        std::cout<<sum_a<<' '<<sum_b<<' '<<sum_c;
    }
    else {
        int s,t; std::cin>>s>>t;
        int x=s,y=t;
        if(s>t) x = s-t;
        else if(s<t) y = 2*(t-s);
        if(x+y>k){
            std::swap(x,y);
            x = y+s*s;
        }
        std::cout<<x<<' '<<y;
    }
    return 0;
}