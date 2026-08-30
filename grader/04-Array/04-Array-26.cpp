#include<iostream>
#include<vector>
int N,sum=0,zero_row;

void bubble(int l,int r,std::vector<int>& vec){
    if(l==r) return ;

    int mid = (l+r)/2;
    bubble(l,mid,vec);
    bubble(mid+1,r,vec);
    std::vector<int> temp(N*N-1);

    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(vec[i] < vec[j]){
            temp[k++] = vec[i++];
        }
        else {
            sum += mid-i+1;
            temp[k++] = vec[j++];
        }
    }
    while(i<=mid) temp[k++] = vec[i++];
    while(j<=r) temp[k++] = vec[j++];
    for(int id=l;id<=r;id++){
        vec[id] = temp[id];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::cin>>N;
    std::vector<int> arr[N];
    for(int i=0;i<N;i++) arr[i].assign(N,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin>>arr[i][j];
            if(arr[i][j]==0) zero_row = i;
        }
    }
    std::vector<int> vec;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==0) continue;
            vec.push_back(arr[i][j]);
        }
    }
    bubble(0,N*N-2,vec);

    bool ans = false;
    if(N%2 && sum%2==0) ans = true;
    else if(N%2==0){
        if(sum%2 && zero_row%2==0) ans = true;
        if(sum%2==0 && zero_row%2) ans = true;
    }
    std::cout<<(ans ? "YES" : "NO");
    return 0;
}