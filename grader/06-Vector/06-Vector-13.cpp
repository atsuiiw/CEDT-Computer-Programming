#include <iostream>
#include <vector>

std::vector<std::string> split(std::string line, char delimiter) {
    line += delimiter;
    std::vector<std::string> vec;
    std::string res = "";
    for(auto x:line){
        if(x==delimiter){
            if(res=="") continue;
            vec.push_back(res);
            res = "";
            continue;
        }
        res += x;
    }
    return vec;
}
int main() {
    std::string line;
    getline(std::cin, line);
    std::string delim;
    getline(std::cin, delim);
    for (std::string e : split(line, delim[0])) {
        std::cout << '(' << e << ')';
    }
}