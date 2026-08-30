#include<iostream>
#include<string>
#include<math.h>

int divide (std::string s,int div){
    int tod = 0;
    int n = s.size();
    if(s=="0") return 0;
    // std::cout<<s<<' '<<n<<'\n';
    for(int i=0;i<n;i++){
        int format = tod*10 + (s[i]-'0');
        if(format < div) {tod = format; continue;}
        tod = format % div;
    }
    // std::cout<<"Final Expo "<<tod<<'\n';
    if(tod==0) return div;
    else return tod;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s;
    while(getline(std::cin,s)){

        std::string res="";
        // extracting
        int A;
        std::string B;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c==' '){
                A = s[i-1]-'0';
                res = "";
                continue;
            }
            res+=c;
        }
        B = res;

        // calculate answer
        std::cout<<">> ";
        if(A==1 || A==5 || A==6 || A==0) {
            std::cout<<A<<'\n'; continue;
        }
        if(A==2 || A==3 || A==7 || A==8){
            int finalExpo = divide(B,4);
            std::cout<<(int)pow(A,finalExpo) % 10;
        }
        else if(A==4 || A==9){
            int finalExpo = divide(B,2);
            std::cout<<(int)pow(A,finalExpo) % 10;
        }
        std::cout<<'\n';
    }
    return 0;
}

/*
1
2 4 8 6, 1 2 3 4
3 9 7 1, 1 2 3 4
4 6
5
6
7 9 3 1
8 4 2 6
9 1
*/