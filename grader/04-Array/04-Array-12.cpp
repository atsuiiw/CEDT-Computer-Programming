#include<iostream>
#include <unordered_map>
#include<string>

std::unordered_map<std::string,std::string> mp;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;

    mp["Robert"] = "Dick";
    mp["Dick"] = "Robert";
    mp["William"] = "Bill";
    mp["Bill"] = "William";
    mp["James"] = "Jim";
    mp["Jim"] = "James";
    mp["John"] = "Jack";
    mp["Jack"] = "John";
    mp["Margaret"] = "Peggy";
    mp["Peggy"] = "Margaret";
    mp["Edward"] = "Ed";
    mp["Ed"] = "Edward";
    mp["Sarah"] = "Sally";
    mp["Sally"] = "Sarah";
    mp["Andrew"] = "Andy";
    mp["Andy"] = "Andrew";
    mp["Anthony"] = "Tony";
    mp["Tony"] = "Anthony";
    mp["Deborah"] = "Debbie";
    mp["Debbie"] = "Deborah";

    while(n--){
        std::string s; std::cin>>s;
        if(mp.find(s)!=mp.end()) std::cout<<mp[s]<<'\n';
        else std::cout<<"Not found\n";
    }
    return 0;
}