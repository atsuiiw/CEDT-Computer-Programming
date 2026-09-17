#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<math.h>
using ll = long long;


std::unordered_map<std::string,int> mp;
struct A{
    std::string id;
    ll num;
    ll final;
    bool operator < (const A&o) const {
        if(final!=o.final) return final > o.final;
        if(num != o.num) return num > o.num;
    }
};

struct B{
    std::string id;
    double decimal;
    bool operator < (const B&o) const {
        return decimal > o.decimal;
    }
};
std::vector<A> all;
std::vector<B> decimalSort;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    ll sum = 0;
    double divider = 0;
    while(1){
        std::string id; std::cin>>id;
        if(id=="END") break;
        ll num; std::cin>>num;
        sum+=num;
        all.push_back({id,num,0});
    }

    int member_cnt = 0;
    for(auto& x:all){
        // std::cout<<x.num/(sum/100.0)<<'\n';
        double avg = x.num/(sum/100.0);
        member_cnt += floor(avg);
        decimalSort.push_back({ x.id, avg - floor(avg) });
        x.final = floor(avg);
    }
    // std::cout<<member_cnt<<'\n';
    sort(decimalSort.begin(),decimalSort.end());
    // for(auto x:decimalSort){
    //     std::cout<<x.id<<' '<<x.decimal<<'\n';
    // }
    for(int i=0;member_cnt+i<100;i++){
        // std::cout<<decimalSort[(i-1)%all.size()].id<<'\n';
        mp[decimalSort[(i)%all.size()].id]++;
    }
    for(auto& x:all){
        if(mp[x.id]){
            x.final+=mp[x.id];
        }
    }
    sort(all.begin(),all.end());
    for(auto x:all){
        if(x.final==0) continue;
        std::cout<<x.id<<' '<<x.final<<' '<<x.num<<'\n';
    }

    return 0;
}