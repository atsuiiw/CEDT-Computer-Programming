#include<iostream>
#include<math.h>

const int N = 40;
double arr[N][N];

double avg(int i,int j){
    double res = 0;
    res += arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1];
    res += arr[i][j-1] + arr[i][j] + arr[i][j+1];
    res += arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
    res /= 9;
    return round(100.0*res)/100.0;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; std::cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>arr[i][j];
        }
    }
    for(int i=1;i<n-1;i++) {for(int j=1;j<m-1;j++) std::cout<<avg(i,j)<<' '; std::cout<<'\n';}
    return 0;
}