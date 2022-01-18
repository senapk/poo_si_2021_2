#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP
#include <iostream>
#include <map>

#include "aluno.hpp"

class Disciplina {
    std::string nome;
    std::map<std::string, Aluno*> alunos;
public:
    Disciplina(std::string nome);
    std::string getNome();

    void addAluno(Aluno * aluno) {
        auto key = aluno->getNome();
        if(this->alunos.find(key) == this->alunos.end()) {
            this->alunos[key] = aluno;
            aluno->addDisciplina(this);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Disciplina discp) {
        os << discp.getNome() << " [ ";
        for (const auto& pair : discp.alunos)
            os << pair.first << " ";
        os << "]";
        return os;
    }
};

#endif // DISCIPLINA_HPP
