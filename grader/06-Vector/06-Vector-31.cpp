#include<iostream>
#include<unordered_map>
#include<vector>

std::unordered_map<std::string,std::pair<int,int>> mp;
std::unordered_map<std::string,bool> used;
const int N = 5;
int table[N+5][N+5];
int ch[3*N];
// 1-5 horizontal, 6-10 verticle, 11 diagonal, 12 reverse diagonal

// column hashing
char colChar(int i){
    return (i==1 ? 'B' : i==2 ? 'I' : i==3 ? 'N' : i==4 ? 'G' : 'O');
}

std::vector<int> bingo() {
    std::vector<int> temp;
    for(int i=1;i<=12;i++) if(ch[i]==5) temp.push_back(i);
    return temp;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);

    for(int i=1;i<=N;i++) { char x; std::cin>>x; }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j && i==3){
                char c; std::cin>>c; continue;
            }
            std::string x; std::cin>>x;

            // storing
            table[i][j] = stoi(x);
            // for easier mapping
            std::string mapping = std::string() + colChar(j) + x;
            mp[mapping] = {i,j};
        }
    }

    // random number
    std::string s;
    int idx = 0;
    ch[3] = ch[8] = ch[11] = ch[12] = 1; // middle
    while(std::cin>>s){
        idx++;

        // invalid input
        if(mp.find(s) == mp.end() || used[s]) continue;
        std::pair<int,int> res = mp[s];
        used[s] = true;

        // table update
        ch[res.first]++;
        ch[res.second+5]++;
        if(res.first==res.second) ch[11]++;
        else if(res.first == N-res.second+1) ch[12]++;

        // for(int i=1;i<=5;i++) std::cout<<ch[i]<<' ';
        // std::cout<<'\n';
        // for(int i=6;i<=10;i++) std::cout<<ch[i]<<' ';
        // std::cout<<'\n';
        // std::cout<<ch[11]<<' '<<ch[12]<<'\n';
        
        std::vector<int> vec = bingo();
        if(vec.size()==0) continue;

        std::cout<<idx<<'\n';
        for(auto x:vec){
            if(x<=5){ // horizontal
                for(int i=1;i<=N;i++){
                    if(i==3 && x==3) continue;
                    std::cout<<colChar(i)<<table[x][i];
                    std::cout<<(i==N ? "" : ", ");
                }
                std::cout<<'\n';
            }
            else if(x<=10){ // verticle
                for(int i=1;i<=N;i++){
                    if(i==3 && x-5==3) continue;
                    std::cout<<colChar(x-5)<<table[i][x-5];
                    std::cout<<(i==N ? "" : ", ");
                }
                std::cout<<'\n';
            }
            else if(x==11){
                for(int i=1;i<=N;i++){
                    if(i==3) continue;
                    std::cout<<colChar(i)<<table[i][i];
                    std::cout<<(i==N ? "" : ", ");
                }
                std::cout<<'\n';
            }
            else if(x==12){
                for(int i=1;i<=N;i++){
                    if(i==3) continue;
                    std::cout<<colChar(i)<<table[N-i+1][i];
                    std::cout<<(i==N ? "" : ", ");
                }
                std::cout<<'\n';
            }
        }
        break;
    }

    return 0;
}