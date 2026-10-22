#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 12;

struct pointer{
    int r,c;
    int sum;
    pointer() {
        r=c=sum=0;
    }
} a,b;
int overlap;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    vector<vector<int>> vec(n, vector<int> (n,0));
    for(auto& x:vec) for(auto& y:x) cin>>y;

    int q = n*n;
    while(q--){
        bool isOverlap = false;
        if(a.r==b.r && a.c==b.c) isOverlap = true;
        pointer nextA = a, nextB = b;
        int valueA = vec[a.r][a.c];
        int valueB = vec[b.r][b.c];

        nextA.sum += ((a.r + a.c) % 2 ? valueA : -valueA);
        if(!isOverlap) nextB.sum += (valueB % 2 ? -valueB : valueB);

        // calculate nextA
        if(nextA.r % 2){
            if(nextA.c != 0) nextA.c--;
            else nextA.r+=1;
        }
        else {
            if(nextA.c != n-1) nextA.c++;
            else nextA.r+=1;
        }

        // calculate nextB
        nextB.r = ((b.r + valueB) % n + n) % n;
        if(valueB % 2) nextB.c = ((b.c - valueB - 1) % n + n) % n;
        else nextB.c = ((b.c + valueB + 1) % n + n) % n;

        a = nextA, b = nextB;
        overlap += isOverlap;
    }
    int mode; cin>>mode;
    if(mode==1){
        cout<<(a.sum > b.sum ? "A" : a.sum < b.sum ? "B" : "EQUAL")<<' ';
        cout<<a.sum<<' '<<b.sum;
    }
    else cout<<overlap;

    return 0;
}