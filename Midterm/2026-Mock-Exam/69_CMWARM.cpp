#include<iostream>
#include<vector>

const int MAXN = 110;

int defense = 0, bossAttack = 5, idx = 0;
double myMultiplier = 1, bossMultiplier = 1;
std::vector<char> op[MAXN];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int myHP, bossHP; std::cin>>myHP >> bossHP;
    int N,M; std::cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char x; std::cin>>x;
            op[i].push_back(x);
        }
    }
    while(1){
        if(myHP<=0 || bossHP<=0) break;

        // reset
        defense = 0;
        bossMultiplier = 1.0;

        // our turn
        int totalAttack = 0;
        for(auto x:op[idx%N]){
            if(x=='S'){
                totalAttack += floor(6 * myMultiplier);
                myMultiplier = 1.0;
            }
            else if(x=='B'){
                totalAttack += floor(8 * myMultiplier);
                myMultiplier = 1.5;
            }
            else if(x=='W'){
                totalAttack += floor(3 * myMultiplier);
                bossMultiplier = 0.25;
                myMultiplier = 1.0;
            }
            else if(x=='D'){
                defense += 5;
            }
        }
        bossHP -= totalAttack;
        if(bossHP <= 0) break;
        
        // boss attack
        int bossFinalAttack = floor(bossAttack * (idx+1) * bossMultiplier);
        myHP -= std::max(bossFinalAttack-defense,0);
        if(myHP <= 0) break;
        
        // std::cout<<myHP<<' '<<bossHP<<' '<<totalAttack<<' '<<std::max(bossFinalAttack-defense,0)<<'\n';
        
        idx++;
    }
    if(myHP<=0) std::cout<<"\"You Lose D:\"";
    else std::cout<<"\"You Win :D\"";
    return 0;
}