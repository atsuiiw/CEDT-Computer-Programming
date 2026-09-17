#include<iostream>
#include<vector>
#include<algorithm>

struct A{
    std::vector<int> store;
    int sum;
    bool operator < (const A&o) const {
        if(sum!=o.sum) return sum>o.sum;
        else if(store.size()!=o.store.size()) return store.size() < o.store.size();
        return store < o.store;
    }
};
std::vector<A> vec;

void fillFirst(int val) {
    bool filled = false;
    for(auto &x:vec){
        if(x.sum + val <= 100){
            x.store.push_back(val);
            x.sum+=val;
            filled = true;
            break;
        }
    }
    if(!filled){
        vec.push_back({{val},val});
    }
}

void fillBest(int val) {
    int best = 0;
    int idx = -1;
    for(int i=0;i<vec.size();i++){
        if(vec[i].sum + val <= 100){
            if(best < vec[i].sum + val){
                best = vec[i].sum + val;
                idx = i;
            }
        }
    }
    if(idx==-1){
        vec.push_back({{val},val});
    }
    else {
        vec[idx].store.push_back(val);
        vec[idx].sum += val;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,data,res=""; std::cin>>s;
    std::cin.ignore();
    getline(std::cin,data);
    data += ' ';
    for(auto x:data){
        if(x==' '){
            if(s=="first") fillFirst(stoi(res));
            else fillBest(stoi(res));
            res = "";
            continue;
        }
        res += x;
    }
    for(auto& x:vec){
        sort(x.store.begin(),x.store.end());
    }
    sort(vec.begin(),vec.end());
    for(auto x:vec){
        for(auto v:x.store){
            std::cout<<v<<' ';
        }
        std::cout<<'\n';
    }

    return 0;
}