#include<iostream>
#include<vector>

const int N = 510;
int arr[N],mx = 0;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    for(int i=0;i<n;i++) std::cin>>arr[i];
    for(int i=0;i<n;i++){ // run normally
        int cnt = 0;
        for(int j=0;j<n;j++){
            int idx = (i+j)%n;
            cnt+=arr[idx];
            if(arr[idx] > arr[(idx+1)%n]){
                break;
            }
        }
        mx = std::max(mx,cnt);
    }
    for (int del=0;del<n;del++) {
        std::vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (i != del) temp.push_back(arr[i]);
        }
        
        int m = temp.size();
        for (int i = 0; i < m; i++) {
            int cnt = temp[i];
            int last = temp[i];
            for (int j = 1; j < m; j++) {
                int next_val = temp[(i + j) % m];
                if (last > next_val) break; // Stop when last > next
                cnt += next_val;
                last = next_val;
            }
            mx = std::max(mx, cnt);
        }
    }
    std::cout<<mx;

    return 0;
}