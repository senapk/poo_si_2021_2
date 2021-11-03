#include <iostream>




class Tempo {
private:
    int hora;
    int minuto;
    int segundo;

    //FUNCAO PURA
    //muda esse atributo para esse valor
    //se o valor estiver [inf, sup]
    //senao coloca zero
    static void setIntervalo(int& atr, int value, int inf, int sup) {
        if (value >= inf && value <= sup) {
            atr = value;
        } else {
            atr = 0;
        }
    }

public:
    void setHora(int value) {
        Tempo::setIntervalo(this->hora, value, 0, 23);
    }
    void setMinuto(int value) {
        Tempo::setIntervalo(this->minuto, value, 0, 59); 
    }
    void setSegundo(int value) {
        Tempo::setIntervalo(this->segundo, value, 0, 59);
    }

    Tempo(int h, int m, int s) {
        this->setHora(h);
        this->setMinuto(m);
        this->setSegundo(s);
    }

    int getHora() {
        return this->hora;
    }
    int getMinuto() {
        return this->minuto;
    }
    int getSegundo() {
        return this->segundo;
    }

    friend std::ostream& operator<<(std::ostream& os, Tempo tempo) {
        os << tempo.hora << ":" << tempo.minuto << ":" << tempo.segundo;
        return os;
    }
};

int main() {
    Tempo tempo(11, 222, 3);
    int gas = 0;
    int gasMax = 50;

    // tempo.setHora(12);
    // tempo.setMinuto(43);
    // tempo.setSegundo(67);

    std::cout << tempo << std::endl;


    return 0;
}