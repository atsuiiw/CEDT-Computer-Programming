#include<iostream>
#include<string>
#include<vector>

const int N = 60;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    std::vector<std::string> arr(n+10);
    for(int i=1;i<=n;i++) std::cin>>arr[i];

    std::cin.ignore();
    std::string opr; getline(std::cin,opr);
    for(auto x:opr){
        if(x=='C') {
            for(int i=1;i<=n/2;i++) std::swap(arr[i],arr[i+n/2]);
        }
        else if(x=='S'){
            std::vector<std::string> res(n+10);
            for(int i=1;i<=n/2;i++){
                res[i*2-1] = arr[i];
                res[i*2] = arr[i+n/2];
            }
            arr = res;
        }
    }
    for(int i=1;i<=n;i++) std::cout<<arr[i]<<' ';
    return 0;
}