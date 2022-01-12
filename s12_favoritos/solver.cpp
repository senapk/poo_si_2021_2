#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include "auxiliar.hpp"

#include "fone.hpp"
#include "contact.hpp"
#include "agenda.hpp"

int main(){
    Agenda agenda;
    while(true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << '\n';
        try {
            if (cmd == "end") {
                break;
            } else if (cmd == "add") {//joao oi:123 tim:543
                std::string name = aux::read<std::string>(ss);
                auto words = aux::split(ss, ' ');
                auto fones = aux::map(words, [](auto token) {
                    auto parts = aux::split(token, ':');
                    return Fone(parts[0], parts[1]);
                });
                agenda.add(name, fones);
                // std::string name{};
                // ss >> name;
                // std::string token;
                // std::vector<Fone> fones;
                // while(ss >> token) {
                //     std::string label{}, number{};
                //     std::stringstream ss2(token);
                //     getline(ss2, label, ':');
                //     getline(ss2, number);
                //     fones.push_back(Fone(label, number));
                // }
                // agenda.add(name, fones);
            } else if (cmd == "show") {
                std::cout << agenda << '\n';
            } else if (cmd == "fav") {
                agenda.star(aux::read<std::string>(ss), true);
            } else if (cmd == "unfav") {
                agenda.star(aux::read<std::string>(ss), false);
            } else if (cmd == "favs") {
                auto starred = agenda.getStarred();
                std::cout << aux::join(starred, "\n") << '\n';
            } else {
                std::cout << "fail: comando invalido" << '\n';
            }
        } catch (std::runtime_error &e) {
            std::cout << e.what() << '\n';
        }
    }
    return 0;
}

/*
add ana oi:123 tim:543
add joao oi:34
add ana tim:543
show

*/
