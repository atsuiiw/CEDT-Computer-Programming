#include<iostream>
#include<stack>

const int N = 60;
int arr[N],sum=0;
int R[N],L[N]; // max from L/R

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>arr[i];
    
    L[1] = arr[1];
    R[n] = arr[n];
    for(int i=2;i<=n;i++){
        L[i] = std::max(L[i-1],arr[i]);
    }
    for(int i=n-1;i>=1;i--){
        R[i] = std::max(R[i+1],arr[i]);
    }

    for(int i=1;i<=n;i++){
        int cal = std::min(L[i],R[i]) - arr[i];
        if(cal < 0) continue;
        sum+=cal;
    }
    std::cout<<sum;

    return 0;
}