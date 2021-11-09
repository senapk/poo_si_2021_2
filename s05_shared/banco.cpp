#include <iostream>
#include <memory>
#include <vector>
#include <list>

using namespace std;

class Person {
public:
    string name;
    Person(string name) : name(name) {}
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name;
        return os;
    }
};

class Bank {
    vector<shared_ptr<Person>> caixas;
    list  <shared_ptr<Person>> espera;

    bool validarIndice(int indice) {
        if (indice < 0 || indice >= (int) this->caixas.size()) {
            cout << "caixa inexistente\n";
            return false;
        }
        return true;
    }

public:
    Bank(int qtdCaixas): caixas(qtdCaixas, nullptr) {
    }
    
    void entrar(const shared_ptr<Person>& person) {
        this->espera.push_back(person);
    }

    bool chamarCaixa(int indice) {
        if(!this->validarIndice(indice))
            return false;
        if (this->caixas[indice] != nullptr) {
            cout << "caixa ocupado\n";
            return false;
        }
        if (this->espera.empty()) {
            cout << "sem clientes\n";
            return false;
        }
        this->caixas[indice] = this->espera.front();
        this->espera.pop_front();
        return true;
    }
    bool finalizarAtendimento(int indice) {
        if(!this->validarIndice(indice))
            return false;
        if (this->caixas[indice] == nullptr) {
            cout << "caixa vazio\n";
            return false;
        }
        this->caixas[indice] = nullptr;
        return true;
    }

    friend ostream& operator<<(ostream& os, const Bank& b) {
        os << "Caixas: | ";
        for (int i = 0; i < (int) b.caixas.size(); i++) {
            auto& caixa = b.caixas[i];
            os << i << ":" ;
            if (caixa != nullptr)
                os << *caixa;
            else
                os << "----";
            os << " | ";
        }
        os << "\nEspera: ";
        for (auto cliente : b.espera) {
            os << *cliente << " ";
        }
        return os;
    }
};

int main() {
    Bank bank(3);
    bank.entrar(make_shared<Person>("Joao"));
    bank.entrar(make_shared<Person>("Maria"));
    bank.entrar(make_shared<Person>("Pedro"));
    bank.entrar(make_shared<Person>("Jose"));
    bank.entrar(make_shared<Person>("Paulo"));

    bank.chamarCaixa(0);
    bank.chamarCaixa(1);
    bank.chamarCaixa(2);
    bank.chamarCaixa(0); //caixa ocupado

    bank.finalizarAtendimento(0);
    bank.finalizarAtendimento(1);

    cout << bank << '\n';
}

