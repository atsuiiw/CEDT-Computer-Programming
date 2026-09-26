#include<iostream>
#include<string>
#include<set>

const int N = 1010;
std::set<int> st[N], U,I,D;

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,res="";
    int idx = 0;
    while(getline(std::cin,s)){
        s += ' ';
        for(auto x:s){
            if(x==' '){
                st[idx].insert(stoi(res));
                res = "";
                continue;
            }
            res += x;
        }
        idx++;
    }
    for(int i=0;i<idx;i++){
        for(auto x:st[i]){
            U.insert(x);
        }
    }
    I = U;
    D = st[0];

    for(auto x:U){
        for(int i=0;i<idx;i++){
            bool ch = (st[i].find(x) == st[i].end());
            if(ch){
                I.erase(x);
                break;
            }
        }
    }

    for(int i=1;i<idx;i++){
        for(auto x:st[i]){
            if(D.find(x) != D.end()){
                D.erase(x);
            }
        }
    }
    std::cout<<"U: ";
    if(U.size()==0) std::cout<<"empty set\n";
    else {
        for(auto x:U) std::cout<<x<<' ';
        std::cout<<'\n';
    }
    std::cout<<"I: ";
    if(I.size()==0) std::cout<<"empty set\n";
    else {
        for(auto x:I) std::cout<<x<<' ';
        std::cout<<'\n';
    }
    std::cout<<"D: ";
    if(D.size()==0) std::cout<<"empty set\n";
    else {
        for(auto x:D) std::cout<<x<<' ';
        std::cout<<'\n';
    }
    return 0;
}
