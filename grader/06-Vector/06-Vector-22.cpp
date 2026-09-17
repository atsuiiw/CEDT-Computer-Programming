#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> getData (std::string s) {
    s += ' ';
    std::string res = "";
    std::vector<int> vec;
    for(auto x:s){
        if(x==' '){
            vec.push_back(stoi(res));
            res = "";
            continue;
        }
        res += x;
    }
    vec.push_back(-1);
    return vec;
}

struct A{
    int val,st,en;
    bool operator < (const A&o) const{
        if(val!=o.val) return val < o.val;
        if(st!=o.st) return st < o.st;
        return en < o.en;
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; getline(std::cin,s);
    std::vector<int> vec = getData(s);
    std::vector<A> ans;

    int consecutive = 1, mx = 1, last = 0;
    for(int i=1;i<vec.size();i++){
        if(vec[i-1] == vec[i]) consecutive++;
        else {
            mx = std::max(mx,consecutive);
            consecutive = 1;
            ans.push_back({vec[i-1],last,i});
            last = i;
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        if(x.en-x.st == mx){
            std::cout<<x.val<<" --> x[ "<<x.st<<" : "<<x.en<<" ]\n";
        }
    }
    return 0;
}