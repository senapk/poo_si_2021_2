#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> amigos;

    std::pair<std::string, int> p1("Juan", 1);

    amigos.insert({"Victor", 40});
    amigos.insert(std::make_pair("Rubens", 44));
    amigos.insert({"Franciel", 47});
    {
        auto [it, res] = amigos.insert({"Victor", 60}); //ele não sobrescreve
    }
    amigos.insert(p1);

    amigos["david"] = 42; //sintaxe de vetor, inserção destrutiva
    amigos["david"] = 43; //sobrescreve o valor
    amigos["fernando"] = 36;

    auto it = amigos.find("fernando");
    if (it == amigos.end()) {
        std::cout << "fernando não encontrado" << std::endl;
    } else {
        it->second = 34;
        std::cout << "fernando encontrado" << std::endl;
        amigos.erase(it);
    }

    for (auto& [nome, idade] : amigos) {
        std::cout << nome << " " << idade << std::endl;
    }

    for (auto& par : amigos) {
        std::cout << par.first << " " << par.second << std::endl;
    }

    for (auto it = amigos.begin(); it != amigos.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}