#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

int start_ticket = 0;
int ticket_add = 0;

struct A{
    int id, time;
};
std::vector<A> inQueue;
A current;
int totalQueueTime;
int orderDone;

void sol(){
    std::string s; std::cin>>s;
    if(s=="reset"){
        std::cin>>start_ticket;
    }
    else if(s=="new"){
        int n; std::cin>>n;
        inQueue.push_back({ start_ticket + ticket_add++, n });
        std::cout<<">> ticket "<<start_ticket+ticket_add-1<<'\n';
    }
    else if(s=="next"){
        current = inQueue[0];
        inQueue.erase(inQueue.begin());
        std::cout<<">> call "<<current.id<<'\n';
    }
    else if(s=="order"){
        int time; std::cin>>time;
        std::cout<<">> qtime "<<current.id<<' '<<time - current.time<<'\n';
        orderDone++;
        totalQueueTime += time-current.time;
    }
    else if(s=="avg_qtime"){
        double avg = 1.0 * totalQueueTime / orderDone;
        std::cout<<">> "<<s<<' '<<round(avg * 100.0) / 100.0<<'\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int n; std::cin>>n;
    while(n--) sol();
    return 0;
}