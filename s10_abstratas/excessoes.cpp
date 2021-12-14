#include <iostream>
#include <stdexcept>

//throw para disparar uma excessão
//try cache para pegar a excessão

void funcao1() {
    std::cout << "tal coisa\n";
    throw std::invalid_argument("erro");
    std::cout << "fiz outra coisa";
}

void funcao2() {
    try {
        funcao1(); //trata erro de conexao
    } catch (std::string e) {
        std::cout << "erro: " << e << "\n";
    } catch (float x) {
        std::cout << "passou um erro do tipo float por aqui\n";
        throw x;
    }
    std::cout << "fim da funcao2\n";
}

void funcao3() {
    try {
        funcao2(); //problema de parse
    } catch (int e) {
        std::cout << "funcao3 pegou o erro: " << e << "\n";
    }
    std::cout << "fim da funcao3\n";
}

int main() {
    funcao3(); //avisa pro usuario
    std::cout << "fim do programa\n";
}