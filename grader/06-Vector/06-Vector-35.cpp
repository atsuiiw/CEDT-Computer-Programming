#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> mp;

void setup() {
    mp["soon"] = 0;
    mp["neung"] = 1;
    mp["song"] = 2;
    mp["sam"] = 3;
    mp["si"] = 4;
    mp["ha"] = 5;
    mp["hok"] = 6;
    mp["chet"] = 7;
    mp["paet"] = 8;
    mp["kao"] = 9;

    mp["et"] = 1;
    mp["yi"] = 2;
    mp["sip"] = 10;
    mp["roi"] = 100;
    mp["phan"] = 1000;
    mp["muen"] = 10000;
    mp["saen"] = 100000;
    mp["lan"] = 1000000;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);
    setup();

    while (true) {
        std::string s;
        if (!std::getline(std::cin, s)) break;
        if (s == "q") break;

        std::vector<std::string> vec;
        std::string res = "";
        s += ' ';
        for (auto x : s) {
            if (x == ' ') {
                if (!res.empty()) {
                    vec.push_back(res);
                    res = "";
                }
                continue;
            }
            res += x;
        }

        if (vec.empty()) continue;

        long long total = 0;
        long long subtotal = 0;
        long long current_val = 0;

        for (int i = 0; i < vec.size(); i++) {
            std::string word = vec[i];

            if (word == "lan") {
                subtotal += current_val;
                if (subtotal == 0) subtotal = 1;
                total += subtotal * 1000000;
                subtotal = 0;
                current_val = 0;
            } else if (word == "sip" || word == "roi" || word == "phan" || word == "muen" || word == "saen") {
                long long mult = mp[word];
                if (current_val == 0) {
                    current_val = 1; // Handles cases like "sip" meaning 10 instead of 0 * 10
                }
                current_val *= mult;
                subtotal += current_val;
                current_val = 0;
            } else {
                current_val = mp[word];
            }
        }
        subtotal += current_val;
        total += subtotal;

        std::cout << total << "\n";
    }

    return 0;
}
