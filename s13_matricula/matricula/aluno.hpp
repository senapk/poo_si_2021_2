#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <iostream>
#include <map>

class Disciplina; //forward declaration

class Aluno {
    std::string nome;
    std::map<std::string, Disciplina*> disciplinas;
public:
    Aluno(std::string nome);
    void addDisciplina(Disciplina * discp);
    std::string getNome() const;

    friend std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
};

#endif // ALUNO_HPP
