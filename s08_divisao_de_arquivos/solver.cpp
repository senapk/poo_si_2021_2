#include <iostream>
#include "fone.hpp"

//contato.hpp
//#include <iostream>
//#include "fone.hpp"
class Contato {
    Fone fone;
    std::string nome;
    static int value;
public:
    Contato(std::string nome = "", Fone fone = Fone("", ""));
    void imprime();
};

int Contato::value { 0 };

//contato.cpp
//#include <iostream>
//#include "fone.hpp"
//#include "contato.hpp"

Contato::Contato(std::string nome, Fone fone) : nome(nome), fone(fone) {}
void Contato::imprime() {
    std::cout << nome << ": " << fone.getNumber() << std::endl;
}



int main() {
    Fone fone("home", "123456789");
    std::cout << fone.getLabel() << " " << fone.getNumber() << std::endl;
    return 0;
}


//compilação
// g++ -std=c++14 -Wall -Wextra solver.cpp fone.cpp contato.cpp -o solver