#include <sstream>
#include <iostream>
#include <cmath>
#include <tuple>

template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

int main(){
    while(true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << '\n';
        if (cmd == "end") {
            break;
        } else if (cmd == "add") {
            auto [num1, num2] = parse<int, int>(ss);
            std::cout << (num1 + num2) << '\n';
        } else if (cmd == "sqrt") {
            auto [num] = parse<int>(ss);
            std::cout << std::sqrt(num) << '\n';
        } else {
            std::cout << "fail: comando invalido" << '\n';
        }
    }
    return 0;
}