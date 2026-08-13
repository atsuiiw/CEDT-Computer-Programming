#include<iostream>
#include<string>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s;
    while(getline(std::cin,s)) {
        bool lower=false,upper=false,num=false,special=false;
        int len = s.size();
        for(auto x:s){
            if(isdigit(x)) num|=1;
            else if(isupper(x)) upper|=1;
            else if(islower(x)) lower|=1;
            else special|=1;
        }
        if(lower && upper && num && special && len>=12) std::cout<<"strong\n";
        else if(lower && upper && num && len>=8) std::cout<<"weak\n";
        else std::cout<<"invalid\n";
    }
    return 0;
}