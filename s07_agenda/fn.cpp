#include <iostream>
#include <functional>

int opera(int a, int b, std::function<int(int, int)> f) {
    return f(a, b);
}

int main() {
    auto soma = [](int a, int b) -> int {
        return a + b;
    };
    auto c = opera(1, 2, soma);
    std::cout << c << std::endl;
    auto d = opera(1, 2, [](int a, int b) -> int {
        return a - b;
    });
    auto e = opera(1, 2, [](int a, int b){return a * b;});
    auto f = opera(1, 2, [](auto a, auto b){return a /b;});

    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
}