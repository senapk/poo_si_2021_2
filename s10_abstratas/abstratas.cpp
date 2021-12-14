#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <memory>

class Corredor {
protected:
    std::string nome;
    float x { 0 };
public:
    Corredor(std::string nome) : nome(nome) {}
    //funcao virtual pura
    virtual void correr() = 0;
    float getX() { return x; }
    std::string getNome() { return nome; }
    friend std::ostream& operator<<(std::ostream& os, Corredor& corredor);
};
std::ostream& operator<<(std::ostream& os, Corredor& corredor) {
    return (os << corredor.getNome() << ":" << corredor.getX());
}

class Consistente : public Corredor {
public:
    Consistente(std::string nome) : Corredor(nome) {}
    void correr() override {
        x++;
    }
};

class Instavel : public Corredor {
public:
    Instavel(std::string nome) : Corredor(nome) {}
    void correr() override {
        if(rand() % 2)
            x += 2;
    }
};

class DickVigarista : public Instavel {
public:
    DickVigarista() : Instavel ("Vigarista") {}
};


class Progressivo : public Corredor {
protected:
    float inc { 0.1 };
public:
    Progressivo(std::string nome, float inc) : Corredor(nome), inc(inc) {}
    void correr() override {
        x += inc;
        if(rand() % 2 == 0)
            inc *= 2;
    }
};

class Corrida {
    std::vector<std::shared_ptr<Corredor>> corredores;
    float distancia { 0 };
public:
    Corrida(float distancia) : distancia(distancia) {}
    void addCorredor(std::shared_ptr<Corredor> corredor) {
        corredores.push_back(corredor);
    }
    void largada() {
        while (!acabou()) {
            this->correr();
            this->imprimir();
            getchar();
        }
    }
    void correr() {
        for(auto corredor : corredores) {
            corredor->correr();
        }
    }
    bool acabou() {
        for(auto corredor : corredores) {
            if(corredor->getX() >= distancia) {
                //verify is corredor is a instance of DickVigarista
                auto answer = dynamic_cast<DickVigarista*>(corredor.get());
                if(answer) {
                    std::cout << "Vigarista ganhou!" << std::endl;
                    return true;
                }
                distancia = corredor->getX() + 1;                
            }
        }
        return false;
    }

    void imprimir() {
        for(auto corredor : corredores) {
            std::cout << *corredor << ";";
        }
        std::cout << std::endl;
    }
};

int main () {
    srand(time(NULL));
    Corrida corrida(10);
    corrida.addCorredor(std::make_shared<Consistente>("Joao"));
    corrida.addCorredor(std::make_shared<Instavel>("Maria"));
    corrida.addCorredor(std::make_shared<Progressivo>("Pedro", 0.1));
    corrida.addCorredor(std::make_shared<DickVigarista>());
    corrida.largada();
    return 0;
}