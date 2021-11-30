#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int main() {
    std::unordered_set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(5);

    {
        auto [it, res] = s.insert(5);
        if (res) {
            std::cout << "inserted" << std::endl;
            std::cout << "na posicao" << it << "\n";
        } else {
            std::cout << "not inserted" << std::endl;
            std::cout << "ja tinha esse valor na posicao" << it << "\n";
        }
    }
    {
        s.insert(9);
    }
    
    for (auto i : s) {
        std::cout << i << std::endl;
    }

    auto it = s.find(5);
    if (it == s.end()) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "Found 5" << std::endl;
        s.erase(it);
    }

}