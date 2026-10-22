#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

struct A{
    string id;
    double grade; int hour, rev;
};
vector<A> vec[3];

bool qualified(A a, A b){
    if(a.grade != b.grade) return a.grade > b.grade;
    if(a.rev != b.rev) return a.rev < b.rev;
    return a.id < b.id;
}

bool waiting(A a, A b){
    if(a.grade != b.grade) return a.grade > b.grade;
    if(a.hour != b.hour) return a.hour > b.hour;
    return a.id < b.id;
}

bool unqualified(A a, A b){
    return a.id < b.id;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    string id;
    while(1){
        cin>>id;
        if(id=="END") break;
        double grade; int hour, rev;
        cin>>grade>>hour>>rev;

        // qualified
        if(grade >= 3.75 && rev <= 300000){
            vec[0].push_back({id,grade,hour,rev});
        }
        else if(grade >= 3.50 && hour >= 100){
            vec[1].push_back({id,grade,hour,rev});
        }
        else vec[2].push_back({id,grade,hour,rev});
    }

    sort(vec[0].begin(),vec[0].end(),qualified);
    sort(vec[1].begin(),vec[1].end(),waiting);
    sort(vec[2].begin(),vec[2].end(),unqualified);

    if(!vec[0].empty()){
        cout<<"Qualified\n";
        for(auto x:vec[0]) cout<<x.id<<'\n';
    }
    if(!vec[1].empty()){
        cout<<"Waiting List\n";
        for(auto x:vec[1]) cout<<x.id<<'\n';
    }
    if(!vec[2].empty()){
        cout<<"Unqualified\n";
        for(auto x:vec[2]) cout<<x.id<<'\n';
    }

    return 0;
}