#include<bits/stdc++.h>

void output(std::vector<int>& vec) {
    for(int x:vec) std::cout<<x<<' ';
    std::cout<<'\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    std::vector<int> sorted(n), arr(n);
    for(int i=0;i<n;i++) std::cin>>arr[i], sorted[i]=arr[i];
    std::sort(sorted.begin(), sorted.end());

    output(arr);
    if(sorted == arr) return 0;

    for(int i = 0; i < n; i++) {
        int target = sorted[n-1-i];
        if(arr[n-1-i] == target) continue;   // already correct here, nothing to do

        // find target's current position (guaranteed to exist)
        int j = 0;
        while(arr[j] != target) j++;

        if(j > 0) {                                   // only flip/print if it actually moves
            std::reverse(arr.begin(), arr.begin()+j+1); // bring target to front
            output(arr);
        }

        std::reverse(arr.begin(), arr.begin() + (n - i)); // place target at position n-1-i
        output(arr);
    }

    return 0;
}