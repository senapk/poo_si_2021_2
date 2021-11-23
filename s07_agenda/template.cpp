#include <iostream>
#include <sstream>
#include <vector>


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    for (auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

template <typename T, typename Q>
T soma(T a, Q b) {
    return a + b;
}

float operator+(float a, std::string b) {
    float f;
    std::stringstream(b) >> f;
    return a + f;
}

template <typename T>
T get(istream& is) {
    T t;
    is >> t;
    return t;
}

int main() {
    std::stringstream ss("5 banana 3.4");
    int qtd = get<int>(ss);
    std::string fruta = get<std::string>(ss);
    float preco = get<float>(ss);

    std::cout << qtd << " " << fruta << " " << preco << std::endl;


    int a = soma(1, 2);
    std::string b = soma(std::string("a"), std::string("b"));
    float c = soma(1.0f, std::string("2"));

    std::cout << a << " " << b << " " << c << std::endl;

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << v << std::endl;
}
