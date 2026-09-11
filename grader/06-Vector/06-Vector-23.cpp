#include<iostream>
#include<vector>

struct A{
    int id;
    double x,y;
    bool operator < (const A&o) const{
        return x*x + y*y <= o.x*o.x + o.y*o.y;
    }
};
std::vector<A> vec;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=1;i<=n;i++){
        double x,y; std::cin>>x>>y;
        vec.push_back({i,x,y});
    }
    sort(vec.begin(),vec.end());
    std::cout<<"#"<<vec[2].id<<": ("<<vec[2].x<<", "<<vec[2].y<<")";
    return 0;
}