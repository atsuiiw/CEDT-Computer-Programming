#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

std::string p,q;

std::vector<int> base_2(int n) {
    std::vector<int> vec;
    while(n){
        vec.push_back(n%2);
        n/=2;
    }
    while(vec.size()<4) vec.push_back(0);
    reverse(vec.begin(),vec.end());
    return vec;
}

void sol() {
    int opr = (q[0]=='E' ? 1 : 0);
    std::string res = "";
    for(int i=2;i<q.size();i++){
        if(q[i]==' ') continue;
        res+=q[i];
    }
    if(opr){ // E
        int cnt = 0 ;
        for(auto c:res){
            // convert to binary
            std::vector<int> converted = base_2(isdigit(c) ? c-'0' : c==',' ? 11 : 10);
            // for(auto x:converted) std::cout<<x;
            // std::cout<<'\n';
            for(auto x:converted){
                while(!isalpha(p[cnt])){
                    std::cout<<p[cnt];
                    cnt = (cnt+1)%p.size();
                }
                std::cout<<(char)(x ? tolower(p[cnt]) : toupper(p[cnt]));
                cnt++;
            }
        }
    }
    else { // D
        int cnt = 0, bin = 0;
        for(auto x:res){
            if(!isalpha(x)) continue;
            // std::cout<<islower(x);
            bin = (bin<<1) + (islower(x) ? 1 : 0);
            cnt++;
            if(cnt==4){
                if(bin==10) std::cout<<"-";
                else if(bin==11) std::cout<<",";
                else if(bin<=9) std::cout<<bin;
                cnt = 0;
                bin = 0;
            }
        }
    }
    std::cout<<'\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    getline(std::cin,p);
    while(getline(std::cin,q)) sol();
    return 0;
}