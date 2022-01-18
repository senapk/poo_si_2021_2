#include "disciplina.hpp"

Disciplina::Disciplina(std::string nome) : nome {nome}
{
}

std::string Disciplina::getNome() {
    return nome;
}
