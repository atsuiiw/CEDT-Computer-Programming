#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sign(int x) { return (x>0)-(x<0); }

ll extraCost(int C, int D, int S, int T) {
    bool inPath = min(C, D) <= S && S <= max(C, D);
    int dirElev = sign(D - C);
    int dirPerson = sign(T - S);

    if (inPath && dirElev != 0 && dirElev == dirPerson) {
        if (dirElev == 1)  return max(0, T - D);
        else               return max(0, D - T);
    }
    return abs(D - S) + abs(S - T);
}

int main() {
    ll n; cin >> n;
    vector<ll> C(n), D(n), IDX(n);
    for (int i = 0; i < n; i++) cin>>IDX[i]>>C[i]>>D[i];

    
    int q; cin>>q;
    while(q--){
        ll S, T; cin>>S>>T;
        ll best = -1, bestCost = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cost = extraCost(C[i], D[i], S, T);
            if(cost <= bestCost){
                if(bestCost==cost){
                    best = min(best,IDX[i]);
                }
                else best = IDX[i];
                bestCost = cost;
            }
        }
        cout<<">> "<<best<<'\n';
    }
    
}