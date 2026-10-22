#include<iostream>
#include<vector>

struct A{
    std::pair<int,int> mn,mx;
	
    A () {
	mn.first = mn.second = 1e9;
	mx.first = mx.second = -1e9;
    }
} vec[4];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;

    for(int i=1;i<=n;i++){
	int x,y; std::cin>>x>>y;
	if(x==0 || y==0) continue;

	int id = 0;
	if(x>0 && y>0) id = 0;
	else if(x<0 && y>0) id = 1;	
	else if(x<0 && y<0) id = 2;
	else id = 3;		

	vec[id].mn.first = std::min(vec[id].mn.first,x);
	vec[id].mn.second = std::min(vec[id].mn.second,y);
	vec[id].mx.first = std::max(vec[id].mx.first,x);
	vec[id].mx.second = std::max(vec[id].mx.second,y);
    }

    bool exist = false;
    for(int i=0;i<4;i++){
	std::pair<int,int> mn=vec[i].mn,mx=vec[i].mx;
	if(abs(vec[i].mn.first) >= 1e9 && abs(vec[i].mn.second) >= 1e9 &&  abs(vec[i].mx.first) >= 1e9 && abs(vec[i].mx.second) >= 1e9) continue;
	int cal = abs(mx.first-mn.first) * abs(mx.second-mn.second); 
	std::cout<<"Q"<<(i+1)<<": ";
	std::cout<<"("<<vec[i].mn.first<<", "<<vec[i].mn.second<<") ("<<vec[i].mx.first<<", "<<vec[i].mx.second<<") "<<cal<<'\n';
    	exist = true;
    }
    if(!exist) std::cout<<"No point in any quadrant";
    return 0;
}
