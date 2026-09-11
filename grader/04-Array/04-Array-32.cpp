#include<iostream>

const int N = 1010;
struct A{
	int idx,st,en;
} lift[N];

int costCalculate(int S,int T,int st,int en) {
	int dirLift = 0 + (en-st > 0 ? 1 : -1); // 1 means going up and -1 means going down
	int inPath = std::min(st,en) <= S && S<= std::max(st,en);
	int dirPerson = 0 + (T-S > 0 ? 1 : -1); // 1 means going up and -1 means going down
	
	// case inPath and going in the same direction
	if(inPath && dirLift!=0 && dirLift == dirPerson){
		if(dirLift == 1) return std::max(0,T-en);
		else return std::max(0,en-T);
	}

	// other cases like, the person isn't inPath, the lift and person is going on a different direction
	return abs(en-S) + abs(T-S);
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(0);
	int n; std::cin>>n;
	for(int i=1;i<=n;i++) std::cin>>lift[i].idx>>lift[i].st>>lift[i].en;
	int q; std::cin>>q;
	while(q--){
		int S,T; std::cin>>S>>T;
		
		int best=-1,costBest=2e9;
		for(int i=1;i<=n;i++){
			int cost = costCalculate(S,T,lift[i].st,lift[i].en);
			if(cost <= costBest){
				if(costBest == cost){
					best = std::min(best,lift[i].idx);
				}
				else best = lift[i].idx;
				costBest = cost;
			}
		}

		std::cout<<">> "<<best<<'\n';
	}
	return 0;
}