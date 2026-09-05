#include<bits/stdc++.h>

std::string number[] = {"","one","two","three","four","five","six","seven","eight","nine"};
std::string tenth[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
std::string teen[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
std::string postfix[] = {"","thousand", "million", "billion", "trillion"};

std::vector<std::string> vec;
void store(std::string s,int i) {
    // std::cout<<s<<'\n';
    std::string res = "";
    
    // get the hundredth
    if(s.size()==3 && s[2]!='0'){
        res+=number[s[2]-'0'] + " hundred ";
    }

    // get the tenth
    if(s.size()>=2 && s[1]!='0' && s[1]!='1'){
        res+=tenth[s[1]-'0'] + ' ';
        if(s.size()>=1 && ((s[1]=='0' && s[0]!='0') || s[0]!='0')){
            res+=number[s[0]-'0'] + ' ';
        }
    }
    else if(s.size()>=2 && s[1]=='1'){
        res+=teen[s[0]-'0'] + ' ';
    }
    else {
        // get digit
        if(s.size()>=1 && ((s[1]=='0' && s[0]!='0') || s[0]!='0')){
            res+=number[s[0]-'0'] + ' ';
        }
    }

    if(res!="") res += postfix[i];

    if(res!="") vec.push_back(res);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s; std::cin>>s;
    reverse(s.begin(),s.end());
    if(s=="0"){
        std::cout<<"zero";
        return 0;
    }
    int n = s.size();
    for(int i=0;i<n;i+=3){
        store(s.substr(i,3),i/3);
    }
    reverse(vec.begin(),vec.end());
    for(auto x:vec) std::cout<<x<<' ';
    return 0;
}