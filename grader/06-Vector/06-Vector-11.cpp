#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> vec,ans;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    while(1){
        int x; std::cin>>x;
        if(x==-1) break;
        vec.push_back(x);
    }
    reverse(vec.begin(),vec.end());
    int idx = 0;
    ans.assign(vec.size(),0);
    if(vec.size()%2 == 0){
        for(auto x:vec){
            if(idx%2){
                ans[vec.size()-idx/2-1] = x;
                idx++;
            }
            else {
                ans[idx/2] = x;
                idx++;
            }
        }
    }
    else{
        for(auto x:vec){
            if(idx%2==0){
                ans[vec.size()-idx/2-1] = x;
                idx++;
            }
            else {
                ans[idx/2] = x;
                idx++;
            }
        }
    }
    std::cout<<"[";
    for(auto itr=ans.begin();itr!=ans.end();itr++){
        std::cout<<*itr;
        if(itr!=ans.end()-1) std::cout<<", ";
    }
    std::cout<<"]";
    
    
    return 0;
}