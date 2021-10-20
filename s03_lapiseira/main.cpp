#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre = 0, std::string dureza = "", int tamanho = 0) : 
        calibre{calibre}, dureza{dureza}, tamanho{tamanho} {
    }

    friend std::ostream& operator<<(std::ostream& os, const Grafite& grafite) {
        os << "Calibre: " << grafite.calibre << " mm, ";
        os << "Dureza: " << grafite.dureza << ", ";
        os << "Tamanho: " << grafite.tamanho << " mm\n";
        return os;
    }
};

struct Lapiseira {
    float calibre; //4 bytes
    Grafite* grafite; //8 bytes
    Lapiseira(float calibre, Grafite* grafite = nullptr) : 
        calibre{calibre}, grafite{grafite} {
    }
    bool inserirGrafite(Grafite* grafite) {
        if(this->grafite != nullptr) {
            std::cout << "Ja tem grafite\n";
            return false;
        }
        if(grafite->calibre != this->calibre) {
            std::cout << "Calibre incompativel\n";
            return false;
        }
        this->grafite = grafite;
        return true;
    }
    //se tiver grafite, retorna o grafite, se nao, retorna nullptr
    //lembre de colocar nullptr no grafite
    Grafite* removerGrafite() {
        if (this->grafite == nullptr) {
            std::cout << "Nao tem grafite\n";
            return nullptr;
        }
        return std::exchange(this->grafite, nullptr);
    }
};

int main() {
    Grafite grafite(0.5, "HC", 10);

    Lapiseira lapiseira(0.5, &grafite);
    lapiseira.grafite->tamanho -= 5;

    std::cout << grafite.tamanho << "\n";
    std::cout << lapiseira.grafite->tamanho << "\n";
    
    return 0;
}