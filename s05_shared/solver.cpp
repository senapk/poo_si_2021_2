#include <iostream>
using namespace std;

// int * pegar_inteiro() {
//     int i {42}; //estatico
//     return &i;
// }

// new int(42); //criando um bloco de memória e colocando o valor 42
// new int{42};
// new int[42]; //criando 42 blocos de memória para armazenar os valores

int main() {
    // string s {}; //""
    // int i {}; //0
    // double d {}; //0.0
    // bool b {}; //false
    // char c {}; //'\0'
    // int * p {}; //nullptr



    int * p {nullptr};
    {
//        int * q {  }; //500
        p = new int(42); //invoca o contrutor // malloc não inicializa
    }

    cout << "valor    " << p << endl;  //500
    cout << "conteudo " << *p << endl; //42
    *p = 57; //57
    cout << "conteudo " << *p << endl; //57
    
    delete p; //invoca o destructor           // free não faz a destruição
    p = nullptr; //0

    cout << "valor    " << p << endl;  //500
    cout << "conteudo " << *p << endl; //apagou o conteúdo
    return 0;
}