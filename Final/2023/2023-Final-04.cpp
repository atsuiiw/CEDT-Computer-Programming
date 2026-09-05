#include<iostream>
#include<string>

void sol(){
    std::string country_a,country_b;
    std::cin>>country_a>>country_b;

    std::vector<int> veca,vecb;
    int score_a=0,score_b=0;
    while(1){
        std::string temp; std::cin>>temp;
        if(temp=="*") break;
        int idx = temp.find("-");
        bool compare = (stoi(temp.substr(0,idx)) > stoi(temp.substr(idx+1)));
        if(compare) score_a++;
        else score_b++;
        veca.push_back(stoi(temp.substr(0,idx)));
        vecb.push_back(stoi(temp.substr(idx+1)));
    }
    if(score_a > score_b){
        std::cout<<"*"<<country_a<<' '<<score_a<<" [ ";
        for(auto x:veca) std::cout<<x<<' ';
        std::cout<<"]\n";

        std::cout<<country_b<<' '<<score_b<<" [ ";
        for(auto x:vecb) std::cout<<x<<' ';
        std::cout<<"]\n";
    } else{
        std::cout<<"*"<<country_b<<' '<<score_b<<" [ ";
        for(auto x:vecb) std::cout<<x<<' ';
        std::cout<<"]\n";

        std::cout<<country_a<<' '<<score_a<<" [ ";
        for(auto x:veca) std::cout<<x<<' ';
        std::cout<<"]\n";
    }

}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int q; std::cin>>q;
    while(q--) sol();
    return 0;
}