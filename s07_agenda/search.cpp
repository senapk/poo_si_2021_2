#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

class Fone {
};

template <typename T>
std::string to_string(T t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

class Contato {
    std::string nome;
    friend std::ostream& operator<<(std::ostream& os, const Contato& c){
        os << c.nome;
        return os;
    }
};
class Agenda {
    std::vector<Contato> contatos;
    void addContato(Contato contato) {

        //vector
        std::sort()
    }

    void rmContato(std::string nome) {
        //lista é melhor para remover
    }
    
    Contato* getContato(std::string nome) {
        //vector é melhor para buscar
    }

    std::vector<Contato> procurar(std::string pattern) {
        std::vector<Contato> result;
        for (auto contato : this->contatos) {
            auto texto = to_string(contato);
            if (texto.find(pattern) != std::string::npos) {
                result.push_back(contato);
            }
        }
    }
};

int main() {
    Agenda agenda;
    agenda.add(Contato("Joao"));
    agenda.add(Contato("Joao"));
    agenda.add(Contato("Joao"));


    auto contato = agenda.getContato("Joao");
    if(contato != nullptr)
        contato->addFone(Fone("oi", "123"));
}