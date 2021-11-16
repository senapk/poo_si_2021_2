#include <iostream>
#include <memory>
#include <list>

struct Pessoa {
    std::string nome;
    int idade;
    Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {}
    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
        os << p.nome << ":" << p.idade;
        return os;
    }
};

int main() {
    std::list<std::shared_ptr<Pessoa>> pessoas;
    pessoas.push_back(std::make_shared<Pessoa>("Joao", 20));
    pessoas.push_back(std::make_shared<Pessoa>("Maria", 25));
    pessoas.push_back(std::make_shared<Pessoa>("Jose", 30));
    pessoas.push_back(std::make_shared<Pessoa>("Pedro", 35));
    pessoas.push_back(std::make_shared<Pessoa>("Ana", 40));

    for (auto p : pessoas) {
        std::cout << p->nome << std::endl;
    }

    for (auto it = std::next(pessoas.begin()); it != std::prev(pessoas.end()); ++it) {
        std::cout << (*it)->nome << std::endl;
    }

}