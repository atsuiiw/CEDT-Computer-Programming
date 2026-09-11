#include<iostream>
#include<vector>

const int N = 510;
int val[N], mx=0;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=0;i<n;i++) std::cin>>val[i];
    for(int i=0;i<n;i++){
        // basic step
        int cnt = val[i];
        for(int j=1;j<n;j++){
            int idx = (i+j)%n;
            if(val[idx] < val[(idx+n-1)%n]) break;
            cnt += val[idx];
        }
        mx = std::max(mx,cnt);
    }
    
    std::vector<int> vec;
    for(int skip=0;skip<n;skip++){ // skip this index
        for(int start=0;start<n;start++){
            vec.clear();
            for(int end=0;end<n;end++){
                int idx = (start+end) % n;
                if(idx==skip) continue;
                vec.push_back(val[idx]);
            }
            int cnt = vec[0];
            for(int i=1;i<n-1;i++){
                if(vec[i] < vec[i-1]) break;
                cnt += vec[i];
            }
            mx = std::max(mx,cnt);
        }
    }

    std::cout<<mx;

    return 0;
}