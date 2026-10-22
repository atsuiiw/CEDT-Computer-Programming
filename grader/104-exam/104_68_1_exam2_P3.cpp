#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
struct A{
    int v,id;
};
vector<A> vec[N];
string players[N];
pair<string,int> answer[N];

unordered_map<string,pair<string,int>> mp;

struct B{
    string name;
    pair<string,int> answer;
    bool operator < (const B&o) const {
        return answer.second > o.answer.second;
    }
};
vector<B> ranking;

int en[N];

void run(int initial){
    queue<A> qu;
    qu.push({initial,0});
    while(!qu.empty()){
        auto front = qu.front(); qu.pop();
        int u = front.v, id = front.id;
        bool ch = false;
        // auto idx = upper_bound(vec[u].begin(),vec[u].end(),id);
        // if(idx!=vec[u].end()){
        //     qu.push(vec[u][idx - vec[u].begin()]);
        //     ch = true;
        //     en[initial] = id;
        // }
        for(auto x:vec[u]){
            if(x.id > id){
                qu.push(x);
                ch = true;
                en[initial] = id;
                break;
            }
        }
        if(!ch){
            en[initial] = u;
            return ;
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>players[i];
    for(int i=1;i<=n;i++) cin>>answer[i].first>>answer[i].second;
    for(int i=1;i<=m;i++){
        int u; cin>>u;
        vec[u].push_back({u+1,i});
        vec[u+1].push_back({u,i});
    }

    for(int i=1;i<=n;i++){
        run(i);
        mp[players[i]] = answer[en[i]];
        ranking.push_back({players[i],answer[en[i]]});
    }

    sort(ranking.begin(),ranking.end());
    
    while(q--){
        string o; cin>>o;
        if(o=="rank"){
            int x; cin>>x;
            cout<<ranking[x-1].name<<' '<<ranking[x-1].answer.first<<'\n';
        }
        else {
            string x; cin>>x;
            cout<<mp[x].first<<' '<<mp[x].second<<'\n';
        }
    }

    return 0;
}