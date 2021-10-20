#include <iostream>
#include <vector>
#include <vector>
#include <vector>
#include "testador.hpp"
#include "testador.hpp"

//retorna "empate", "primeira" ou "segunda"
std::string qual_metade(std::vector<int> vet) {
    int primeira { 0 };
    for(int i = 0; i < (int) vet.size() / 2; i++)
            primeira += vet[i] > 0 ? vet[i] : -vet[i];
    
    int segunda { 0 };
    int inicio { (int) vet.size() / 2 };
    if(vet.size() % 2 == 1)
        inicio++;
    for(int i = inicio; i < (int) vet.size(); i++)
            segunda += vet[i] > 0 ? vet[i] : -vet[i];
        
    if(primeira == segunda)
        return "empate";
    return primeira > segunda ? "primeira" : "segunda";
}

void testar_qual_metade() {
    std::cout << "Testando qual_metade()" << std::endl;
    testar(qual_metade({1, 2, 3, 4, 5, -6, -7, -8}), std::string{"segunda"});
    testar(qual_metade({-15, -6, -7, -8}), std::string{"primeira"});
    testar(qual_metade({-10, -6, 7, -9}), std::string{"empate"});
    testar(qual_metade({-10, -6, 10}), std::string{"empate"});
}

//retorna os valores positivos
std::vector<int> pegar_homens(std::vector<int> vet) {
    std::vector<int> positivos;
    for (auto value : vet)
        if (value > 0)
            positivos.push_back(value);
    return positivos;
}

void testar_pegar_homens() {
    std::cout << "Testando pegar_homens()" << std::endl;
    testar(pegar_homens({1, 2, 3, 4, 5, -6, -7, -8}), std::vector<int>{1, 2, 3, 4, 5});
    testar(pegar_homens({-15, -6, -7, -8}), std::vector<int>{});
    testar(pegar_homens({-10, -6, 7, -9}), std::vector<int>{7});
    testar(pegar_homens({10, -6}), std::vector<int>{10, 10});
}

//empate homens, mulherse
std::string mais_quem(std::vector<int> vet) {
    int homens { 0 };
    int mulheres { 0 };
    for (auto value : vet) {
        if (value > 0)
            homens++;
        else
            mulheres++;
    }
    if (homens == mulheres)
        return "empate";
    return homens > mulheres ? "homens" : "mulheres";
}

int buscar_menor_positivo(std::vector<int> vet) {
    int atual { -1 };
    for (int i = 0; i < (int) vet.size(); i++)
        if (vet[i] > 0 && (atual == -1 || vet[i] < vet[atual]))
            atual = i;
    return atual;
}


int main() {
    testar_qual_metade();
    testar_pegar_homens();
}