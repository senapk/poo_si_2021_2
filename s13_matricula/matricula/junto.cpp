#include <iostream>
#include <map>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
//aluno.hpp
//---------------------------------------------------------------------------

class Disciplina; //forward declaration

class Aluno {
    std::string nome;
    std::map<std::string, Disciplina*> disciplinas;
public:
    Aluno(std::string nome);
    void addDisciplina(Disciplina * discp);
    void rmDisciplina(std::string nome_discp);
    std::string getNome() const;
    std::vector<Disciplina*> getDisciplinas();

    friend std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
};

//---------------------------------------------------------------------------
//disciplina completa
//---------------------------------------------------------------------------

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

    void rmAluno(std::string nome_aluno) {
        auto it = this->alunos.find(nome_aluno);

        if(it != this->alunos.end()) {
            auto aluno = it->second;
            //primeiro
            this->alunos.erase(it);
            //depois
            aluno->rmDisciplina(this->nome);
        }
    }

    std::vector<Aluno*> getAlunos() {
        std::vector<Aluno*> alunos;
        for(auto it = this->alunos.begin(); it != this->alunos.end(); it++) {
            alunos.push_back(it->second);
        }
        return alunos;
    }

    friend std::ostream& operator<<(std::ostream& os, Disciplina discp) {
        os << discp.getNome() << " [ ";
        for (const auto& pair : discp.alunos)
            os << pair.first << " ";
        os << "]";
        return os;
    }
};

Disciplina::Disciplina(std::string nome) : nome {nome}
{
}

std::string Disciplina::getNome() {
    return nome;
}

//---------------------------------------------------------------------------
//aluno.cpp
//---------------------------------------------------------------------------

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

void Aluno::rmDisciplina(std::string nome_discp) {
    auto it = this->disciplinas.find(nome_discp);

    if (it != this->disciplinas.end()) {
        auto discp = it->second;
        //primeiro
        this->disciplinas.erase(it);
        //depois
        discp->rmAluno(this->nome);
    }
}

std::vector<Disciplina*> Aluno::getDisciplinas() {
    std::vector<Disciplina*> discps;
    for (auto pair : this->disciplinas)
        discps.push_back(pair.second);
    return discps;
}

std::string Aluno::getNome() const {
    return this->nome;
}

std::ostream& operator<<(std::ostream &os, const Aluno& aluno) {
    os << aluno.getNome()  << " [ ";
    for (const auto& pair : aluno.disciplinas)
        os << pair.first << " ";
    os << "]";
    return os;
}

//---------------------------------------------------------------------------
//manager
//---------------------------------------------------------------------------

template <typename T>
class Manager {
    std::map<std::string, std::shared_ptr<T>> mapa;

    public:
        Manager() = default;


        void add(std::string nome, std::shared_ptr<T> obj) {
            auto [it, inseriu] = mapa.insert(std::make_pair(nome, obj));
            if (!inseriu)
                throw std::string("Erro ao inserir objeto " + nome);
        }

        T* get(std::string nome) {
            auto it = mapa.find(nome);
            if (it == mapa.end())
                throw std::string("Erro ao buscar objeto " + nome);
            return it->second.get();
        }

        void rm(std::string nome) {
            auto qtd = mapa.erase(nome);
            if (qtd == 0)
                throw std::string("Erro ao remover objeto " + nome);
        }

        friend std::ostream& operator<<(std::ostream& os, const Manager<T>& manager) {
            os << "Manager";
            for (const auto& pair : manager.mapa)
                os << "\n" << *pair.second;
            os << "\n";
            return os;
        }
};

//---------------------------------------------------------------------------
//sistema
//---------------------------------------------------------------------------



class Sistema {
    Manager<Disciplina> disciplinas;
    Manager<Aluno> alunos;

public:
    void addAluno(std::string nome) {
        this->alunos.add(nome, std::make_shared<Aluno>(nome));
    }
    void addDiscp(std::string nome) {
        this->disciplinas.add(nome, std::make_shared<Disciplina>(nome));
    }
    void matricular(std::string nome_aluno, std::string nome_discp) {
        alunos.get(nome_aluno)->addDisciplina(disciplinas.get(nome_discp));
    }
    void desmatricular(std::string nome_aluno, std::string nome_discp) {
        alunos.get(nome_aluno)->rmDisciplina(nome_discp);
    }
    void rmAluno(std::string nome_aluno) {
        auto discps = alunos.get(nome_aluno)->getDisciplinas();
        for (auto discp : discps)
            discp->rmAluno(nome_aluno);
        alunos.rm(nome_aluno);
    }
    void rmDiscp(std::string nome_discp) {
        auto alunos = disciplinas.get(nome_discp)->getAlunos();
        for (auto aluno : alunos)
            aluno->rmDisciplina(nome_discp);
        disciplinas.rm(nome_discp);
    }
    friend std::ostream& operator<<(std::ostream& os, const Sistema& sistema) ;
};

std::ostream& operator<<(std::ostream& os, const Sistema& sistema) {
    os << sistema.disciplinas << " ";
    os << sistema.alunos << " ";
    return os;
}

//---------------------------------------------------------------------------
//main
//---------------------------------------------------------------------------

using namespace std;

int main()
{
    Sistema sistema;
    sistema.addAluno("joao");
    sistema.addAluno("maria");
    sistema.addAluno("pedro");

    sistema.addDiscp("matematica");
    sistema.addDiscp("portugues");
    sistema.addDiscp("historia");

    sistema.matricular("joao", "matematica");
    sistema.matricular("joao", "portugues");
    sistema.matricular("maria", "portugues");
    sistema.matricular("maria", "historia");
    sistema.matricular("pedro", "historia");

    cout << sistema << endl;

    sistema.desmatricular("joao", "matematica");
    sistema.rmAluno("maria");

    cout << sistema << endl;


    return 0;
}
