#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int> x1(n),y1(n),x2(n),y2(n);
    for(int i=0;i<n;i++) cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];

    int best = 0;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int w = min(x2[i],x2[j]) - max(x1[i],x1[j]);
            int h = min(y2[i],y2[j]) - max(y1[i],y1[j]);
            if(w>0 && h>0){
                int area = w*h;
                if(area > best){
                    best = area;
                    vec.clear();
                    vec.push_back({i,j});
                }
                else if(area==best){
                    vec.push_back({i,j});
                }
            }
        }
    }
    if(best==0){
        cout<<"No overlaps\n";
    }
    else {
        cout << "Max overlapping area = " << best << '\n';
        for (auto x:vec) {
            cout << "rectangles " << x.first << " and " << x.second << '\n';
        }
    }
    return 0;
}