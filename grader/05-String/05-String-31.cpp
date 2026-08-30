#include<iostream>
#include<string>
#include<vector>

std::string p,q;

std::vector<int> base_2(int n) {
    std::vector<int> vec;
    int res = 0;
    while(n){
        vec.push_back(n%2);
        n/=2;
    }
    while(vec.size()<4) vec.push_back(0);
    reverse(vec.begin(),vec.end());
    return vec;
}

void sol() {
    int opr = (q[0]=='E' ? 0 : 1);
    std::string res = "";
    for(int i=2;i<q.size();i++){
        if(q[i]==' ') continue;
        res+=q[i];
    }
    if(opr){
        std::string temp="";
        res += ' ';
        for(int i=0;i<res.size();i++){
            if(temp.size()==4){
                // std::cout<<temp<<' ';
                int acc = 0;
                for(int j=0;j<=3;j++){
                    acc = (acc << 1);
                    acc += islower(temp[j]);
                }
                if(acc>=10){
                    if(acc==10) std::cout<<"-";
                    else std::cout<<",";
                } else std::cout<<acc;
                temp = "";
            }
            if(isalpha(res[i])) temp+=res[i];
            
        }
    }
    else {
        int cnt = 0;
        for(auto x:res){
            std::vector<int> l;
            if(isdigit(x)) l=base_2(x-'0');
            else if(x=='-') l=base_2(10);
            else if(x==',') l=base_2(11);
            for(auto c:l){
                // std::cout<<c;
                if(!isalpha(p[cnt])){
                    std::cout<<p[cnt];
                    cnt = (cnt+1)%p.size();
                }
                if(c) std::cout<<(char)tolower(p[cnt]);
                else std::cout<<(char)toupper(p[cnt]);
                cnt = (cnt+1)%p.size();
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