#include <iostream>

int main() {
    int contador = 2;
    
    auto dobra = [&contador](auto& a) -> void {
        for (; contador > 0; contador--)
            a += a;
    };

    int x = 6;
    dobra(x);
    std::string s = "abc";
    dobra(s);
    std::cout << x << " " << s << std::endl;
}