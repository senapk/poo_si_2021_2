#include <iostream>

class Cliente {
public:
    Cliente(std::string nome, int idade) : nome(nome), idade(idade) {}
    std::string nome;
    int idade;
};

class Agenda {
    std::map<std::string, Contato> contatos;

    void adicionar(Contato contato) {
        auto it = contatos.find(contato.nome);
        if (it == contatos.end()) {
            contatos[contato.nome] = contato;
        } else {
            it->second.addFones(contato.fones); 
        }
    }
}