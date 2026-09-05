#include <iostream>
#include <string>
#include <vector>

int score(char s) {
    if (s == 'R') return 1;
    if (s == 'Y') return 2;
    if (s == 'G') return 3;
    if (s == 'N') return 4;
    if (s == 'B') return 5;
    if (s == 'P') return 6;
    if (s == 'K') return 7;
    return 0;
}

void sol() {
    std::string line;
    if (!std::getline(std::cin, line)) return;
    std::string s = "";
    for (char c : line) {
        if (c != ' ') s += c;
    }
    if (s.empty() || s[0] != 'R') {
        std::cout << "WRONG_INPUT\n";
        return;
    }

    std::vector<std::string> groups;
    std::string current = "";
    for (char c : s) {
        if (c == 'R') {
            if (!current.empty()) {
                groups.push_back(current);
            }
            current = "R";
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        groups.push_back(current);
    }

    const std::string final_sequence = "YGNBPK";
    int cnt = 0;
    bool isValid = true;

    for (size_t i = 0; i < groups.size(); i++) {
        std::string g = groups[i];
        
        if (g[0] != 'R') {
            isValid = false;
            break;
        }

        if (g == "R") {
            if (i != groups.size() - 1) {
                isValid = false;
                break;
            }
            cnt += score('R');
        } 
        else if (g.size() == 2) {
            cnt += score(g[0]) + score(g[1]);
        } 
        else {
            if (i != groups.size() - 1) {
                isValid = false;
                break;
            }
            cnt += score(g[0]) + score(g[1]);
            std::string tail = g.substr(2);
            if (tail.size() > final_sequence.size() || final_sequence.substr(0, tail.size()) != tail) {
                isValid = false;
                break;
            }

            for (char c : tail) {
                cnt += score(c);
            }
        }
    }

    if (isValid) {
        std::cout << cnt << "\n";
    } else {
        std::cout << "WRONG_INPUT\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int q;
    if (std::cin >> q) {
        std::cin.ignore();
        while (q--) {
            sol();
        }
    }
    return 0;
}