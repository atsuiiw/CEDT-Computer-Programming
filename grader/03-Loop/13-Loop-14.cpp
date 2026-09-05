#include<iostream>
#include<string>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string a,b;
    getline(std::cin,a);
    getline(std::cin,b);
    if(a.size()!=b.size()) std::cout<<"Incomplete answer";
    else {
        int ans = 0, len = a.size();
        for(int i=0;i<len;i++){
            if(a[i]==b[i]) ans++;
        }
        std::cout<<ans;
    }
    return 0;
}