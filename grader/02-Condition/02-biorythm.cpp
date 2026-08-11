#include<iostream>

int dom[] = {0,31,59,90,120,151,181,212,243,273,304,334,365}; // quicksum for normal year
int dom2[] = {0,31,60,91,121,152,182,213,244,274,305,335,366}; // quicksum for leap year

bool isLeap(int y){ // check if year is leap
    int gy = y-543;
    return (gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0);
}

double cal(int x,int div){
    return round(sin((2*M_PI*x)*1.0/div)*100.0)/100.0;
}

int blue(int d,int m,int y) {
    if(isLeap(y)) return (dom2[12] - dom2[m] + (dom2[m]-dom2[m-1]-d)) + 1;
    else return (dom[12] - dom[m] + (dom[m]-dom[m-1]-d)) + 1;
}
int black(int y1,int y2) {
    return std::max(0,365 * (y2-y1 + 1));
}
int red(int d,int m,int y) {
    if(isLeap(y)) return (dom2[m-1] + d) - 1;
    else return (dom[m-1] + d) - 1;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int d,m,y, D,M,Y;
    std::cin>>d>>m>>y>>D>>M>>Y;
    int sum = blue(d,m,y)+black(y+1,Y-1)+red(D,M,Y);
    // cout<<isLeap(y)<<' '<<isLeap(Y)<<'\n';
    // cout<<blue(d,m,y)<<'\n';
    // cout<<black(y+1,Y-1)<<'\n';
    // cout<<red(D,M,Y)<<'\n';
    double p=cal(sum,23),e=cal(sum,28),i=cal(sum,33);
    std::cout<<sum<<' '<<p<<' '<<e<<' '<<i;
    return 0;
}