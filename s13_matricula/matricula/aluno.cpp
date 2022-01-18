#include "aluno.hpp"
#include "disciplina.hpp"



Aluno::Aluno(std::string nome): nome{nome}
{
}

void Aluno::addDisciplina(Disciplina *discp) {
    auto key = discp->getNome();
    if (this->disciplinas.find(key) == this->disciplinas.end()){
        this->disciplinas[key] = discp;
        discp->addAluno(this);
    }
}

std::string Aluno::getNome() const {
    return this->nome;
}

std::ostream& operator<<(std::ostream &os, const Aluno& aluno) {
    os << aluno.getNome() << " [ ";
    for (const auto& pair : aluno.disciplinas)
        os << pair.first << " ";
    os << "]";
    return os;
}
