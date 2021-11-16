#include <iostream>
#include <vector>

enum class Label{
    ABERTURA,
    SAQUE,
    DEPOSITO,
    TARIFA,
    EXTORNO
};

std::string toString(Label op) {
    switch(op) {
        case Label::ABERTURA:
            return "Abertura";
        case Label::SAQUE:
            return "Saque";
        case Label::DEPOSITO:
            return "Deposito";
        case Label::TARIFA:
            return "Tarifa";
        case Label::EXTORNO:
            return "Extorno";
        default:
            return "";
    }
}

class Operacao {
public:
    Label label;
    int indice;
    int valor;
    int saldo;
    Operacao(Label label, int indice, int valor, int saldo) {
        this->label = label;
        this->indice = indice;
        this->valor = valor;
        this->saldo = saldo;
    }
    friend std::ostream& operator<<(std::ostream& os, const Operacao& op) {
        os << toString(op.label) << ":" << op.indice << ":" << op.valor << ":" << op.saldo;
        return os;
    }
};

class Financas {
    std::vector<Operacao> extrato;
    int nextId {0};
    int saldo;
public:
    void efetuarOperacao(Label label, int valor) {
        this->saldo += valor;
        extrato.push_back(Operacao(label, nextId++, valor, this->saldo));
    }
    int getSaldo() {
        return this->saldo;
    }
    std::vector<Operacao> getExtrato() {
        return extrato;
    }
};

class Conta {
    int num;
    Financas financas;
    public: 
    Conta(int num, int saldo) {
        this->num = num;
        this->financas.efetuarOperacao(Label::ABERTURA, saldo);
    }

    bool saque(int valor) {
        if (valor < 0) {
            std::cout << "Valor inválido\n";
            return false;
        }
        if (this->financas.getSaldo() < valor) {
            std::cout << "Saldo insuficiente\n";
            return false;
        }
        this->financas.efetuarOperacao(Label::SAQUE, -valor);
        return true;
    }

    bool deposito(int valor) {
        if (valor < 0) {
            std::cout << "Valor inválido\n";
            return false;
        }
        this->financas.efetuarOperacao(Label::DEPOSITO, valor);
        return true;
    }

    void tarifa(int valor) {
        if (valor < 0) {
            std::cout << "Valor inválido\n";
            return;
        }
        this->financas.efetuarOperacao(Label::TARIFA, -valor);
    }

    bool extornar(int indice) {
        for (auto& op : financas.getExtrato()) {
            if (op.indice == indice && op.label == Label::TARIFA) {
                this->financas.efetuarOperacao(Label::EXTORNO, std::abs(op.valor));
                return true;
            }
        }
        std::cout << "Operação não encontrada\n";
        return false;
    }
};

int main() {
    std::cout << toString(static_cast<Label>(2));
    return 0;
}
