#include<iostream>
#include<vector>

const char vowels[] = {'a','e','i','o','u'};
std::vector<std::string> vec;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    std::string s,first="",last="",res="";
    getline(std::cin,s);

    if(s[s.size()-1]!=' ') s = s+' ';

    // find first and last word
    for(char c:s){
        if(c==' '){
            if(first=="") first = res;
            else last = res;
            vec.push_back(res);
            res="";
            continue;
        }
        res+=c;
    }
    vec.pop_back();
    vec.erase(vec.begin());

    // find aeiou
    int idx1 = first.size();
    for(char x:vowels){
        if(first.find(x)!=std::string::npos){
            idx1 = std::min((int)first.find(x),idx1);
        }
    }
    int idx2 = last.size();
    for(char x:vowels){
        if(last.find(x)!=std::string::npos){
            idx2 = std::min((int)last.find(x),idx2);
        }
    }

    // output
    std::cout<<first.substr(0,idx1)<<last.substr(idx2)<<' ';
    for(auto x:vec) std::cout<<x<<' ';
    std::cout<<last.substr(0,idx2)<<first.substr(idx1);
    return 0;
}