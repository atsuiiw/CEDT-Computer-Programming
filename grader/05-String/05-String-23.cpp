#include<iostream>
#include<string>

void plus(std::string s,std::string m) {
    int last = stoi(s.substr(4));
    int firstDigit = s[2]-'A';
    int secondDigit = s[1]-'A';
    int front = stoi(s.substr(0,1));

    int temp = last + stoi(m);

    // calculating middle part
    int tod1 = temp / 1000;
    firstDigit += tod1;
    secondDigit += firstDigit/26;
    front += firstDigit/26;
    secondDigit %= 26;
    firstDigit %= 26;

    // output
    std::cout<<std::min(9,front)<<(char)(secondDigit+'A')<<(char)(firstDigit+'A')<<"-";
    if(temp%1000 < 10) std::cout<<"00"<<temp%1000;
    else if(temp%1000 < 100) std::cout<<"0"<<temp%1000;
    else std::cout<<temp%1000;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,m;
    std::cin>>s>>m;

    plus(s,m);

    return 0;
}