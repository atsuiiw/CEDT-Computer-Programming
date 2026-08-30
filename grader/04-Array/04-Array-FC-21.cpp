#include<iostream>

const int N = 1010;
int arr[N];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=0;i<n;i++) std::cin>>arr[i];
    int p = arr[n-1];
    int i = -1, j = 0;
    while(j<n-1){
        if(arr[j] <= p){
            i++;
            std::swap(arr[i],arr[j]);
        }
        j++;
    }
    std::swap(arr[i+1],arr[n-1]);
    std::cout<<"[";
    for(int i=0;i<n;i++){
        std::cout<<arr[i];
        if(i!=n-1) std::cout<<", ";
    }
    std::cout<<"]";
    return 0;
}