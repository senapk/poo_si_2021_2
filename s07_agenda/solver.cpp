#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Coisa {
    int data;
public:
    int getData() const {
        return data;
    }
    Coisa(int d) : data(d) {}

    friend std::ostream& operator<<(std::ostream& os, const Coisa& c);
    friend bool vemPrimeiro(Coisa a, Coisa b);
};

std::ostream& operator<<(std::ostream& os, const Coisa& c) {
    os << c.data;
    return os;
}

bool vemPrimeiro(Coisa a, Coisa b) {
    return b.data < a.data;
}


int main() {
    Coisa c1(1);
    std::cout << c1 << std::endl;
//    operator<<(std::cout, c1) << std::endl;


    // std::vector<Coisa> v = {Coisa(7), Coisa(2), Coisa(6), Coisa(4), Coisa(5)};

    // auto imprime = [&v]() {
    //     for (auto i : v) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // };

    // std::sort(v.begin(), v.end(), [](auto a, auto b) {
    //     return a.data < b.data;
    // });
    // imprime();
    // std::sort(v.begin(), v.end(), [](auto a, auto b) {
    //     return b.data < a.data;
    // });
    // imprime();
    // std::sort(v.begin(), v.end(), [](auto a, auto b) {
    //     (void) a;
    //     (void) b;
    //     return rand() % 2;
    // });
    // imprime();


}