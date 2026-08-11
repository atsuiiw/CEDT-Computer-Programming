#include<iostream>
#include<string>

struct A{
    char a,b,c; // comProg, cal1, cal2
} grade[2];
std::string a,b;
double gpa,gpb;

bool pass(int i){
    return (grade[i].a=='A' && grade[i].b<='C' && grade[i].c<='C');
}

int check () {

    // 1
    int pass1 = pass(0);
    int pass2 = pass(1);

    if(!pass1 && !pass2) return 3;
    else if(pass1 && !pass2) return 0;
    else if(!pass1 && pass2) return 1;

    if(gpa!=gpb) return (gpa>gpb ? 0 : 1);
    if (grade[0].b != grade[1].b) return (grade[0].b < grade[1].b ? 0 : 1);
    if (grade[0].c != grade[1].c) return (grade[0].c < grade[1].c ? 0 : 1);
    return 2;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::cin>>a>>gpa>>grade[0].a>>grade[0].b>>grade[0].c;
    std::cin>>b>>gpb>>grade[1].a>>grade[1].b>>grade[1].c;

    int ans = check();
    if(ans==0) std::cout<<a;
    else if(ans==1) std::cout<<b;
    else if(ans==2) std::cout<<"Both";
    else std::cout<<"None";
    
    return 0;
}