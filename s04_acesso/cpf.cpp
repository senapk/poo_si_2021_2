#include <iostream>
#include <vector>




class CPF {
private:
    std::string number;
    
    //"004.123.143-59" -> {0, 0, 4, 1, 2, 3, 1, 4, 3, 5, 9}
    static std::vector<int> filter(std::string cpf) {
        std::vector<int> numbers;
        for (char c : cpf) {
            if (c != '.' && c != '-') {
                numbers.push_back(c - '0'); //convertendo de char para int
            }
        }
        return numbers;
    }

public:
    CPF(std::string number) {
        this->number = number;
    }

    void setCPF(std::string number) {
        this->number = number;
    }

    std::string getCPF() const {
        return this->number;
    }

    bool isValid() const {
        return CPF::validate(this->number);
    }

    //sobrecarga de método
    static bool validate(std::string cpf) {
        return CPF::validate(CPF::filter(cpf));
    }

    static bool validate(std::vector<int> vet) {
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            sum += vet[i] * (10 - i);
        }
        if (sum % 11 == 0 || sum % 11 == 1) {
            if (vet[9] == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if (vet[9] == (11 - (sum % 11))) {
                return true;
            } else {
                return false;
            }
        }
    }
};

