#include <iostream>

//pessoa.hpp
struct Pessoa {
    std::string nome {""};
    int idade = 0;
    Pessoa(std::string nome = "", int idade = 0): nome(nome), idade(idade) {
        std::cout << nome << "nascendo\n";
    }
    ~Pessoa() {
        std::cout << nome << "morrendo\n";
    }
};


int main() {
    int *p {nullptr};
    {
        int * y = new int(5); //500 heap (new)
        p = y;
        std::cout << *p << '\n'; //5
    }

    std::cout << p << '\n'; //500
    std::cout << *p << '\n'; //indeterminado
    
    *p = 8; //na posicao 500, coloque o 8
    std::cout << p << '\n'; //500
    std::cout << *p << '\n'; //indeterminado

    //delete p; //500 heap (delete)
    p = nullptr;

}