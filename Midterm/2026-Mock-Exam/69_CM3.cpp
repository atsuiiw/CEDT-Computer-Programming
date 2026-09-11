#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

void reduce(double& x){
    x*=0.7;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int MIN,BLOOM,MAX;
    bool alive = true;
    double W,N,P,K; cin>>MIN>>BLOOM>>MAX>>W>>N>>P>>K;
    if(max({W,P,N,K}) > MAX){
        alive = false;
        cout<<"The rose is dead";
    }
    while(1){
        string opr; cin>>opr;
        if(opr=="-1") break;
        double val; cin>>val;
        
        // check wilted
        
        // if dead, dont do sht
        if(!alive) continue;
        
        // value addition
        if(opr=="W") W+=val;
        else if(opr=="K") K+=val;
        else if(opr=="P") P+=val;
        else if(opr=="N") N+=val;

        // conditions
        bool canBloom = (W>BLOOM) & (N>BLOOM) & (K>BLOOM) & (P>BLOOM);
        bool inMin = (W>MIN) & (N>MIN) & (K>MIN) & (P>MIN);
        bool inMax = (W<=MAX) & (N<=MAX) & (K<=MAX) & (P<=MAX);

        if(!inMax){
            alive = false;
            cout<<"The rose is dead\n";
        }
        else if(!inMin && inMax) cout<<"The rose is wilted\n";
        else if(canBloom && inMax) cout<<"The rose is blooming\n";
        else if(inMin && !canBloom) cout<<"Not bloom yet\n";

        // cout<<W<<' '<<N<<' '<<P<<' '<<K<<'\n';
        // value adjustment
        reduce(W);
        reduce(K);
        reduce(P);
        reduce(N);

        // cout<<'\n';
    }
    return 0;
}