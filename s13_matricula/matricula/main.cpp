#include <iostream>
#include "aluno.hpp"
#include "disciplina.hpp"
using namespace std;

int main()
{
    Aluno a1("Joao");
    Aluno a2("Maria");
    Aluno a3("Jose");

    Disciplina d1("FUP");
    Disciplina d2("POO");
    Disciplina d3("ED");

    a1.addDisciplina(&d1);
    a1.addDisciplina(&d2);
    a1.addDisciplina(&d3);

    a2.addDisciplina(&d1);

    a3.addDisciplina(&d2);

    cout << a1 << endl;
    cout << d1 << endl;

    return 0;
}
