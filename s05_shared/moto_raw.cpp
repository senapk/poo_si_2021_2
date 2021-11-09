#include <iostream>
#include <utility>
#include <sstream>
using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string name = "", int age = 0) : name(name), age(age) {}
    string getName() { return name; }
    int getAge() { return age; }
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << ":" << p.age;
        return os;
    }
};

class Bike {
    Person * person;
public:
    Bike(Person * pessoa = nullptr) : person(pessoa) {}
    ~Bike() { 
        delete person; 
    }

    bool subir(Person * person) {
        if (this->person == nullptr) {
            this->person = person;
            return true;
        }
        return false;
    }

    Person * descer() {
        return std::exchange(this->person, nullptr);
    }

    friend ostream& operator<<(ostream& os, const Bike& b) {
        os << "[" << *b.person << "]";
        return os;
    }
};

int main() {
    Bike bike;
    while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "exit") {
            Person * p = bike.descer();
            if (p != nullptr)
                delete p;
            break;
        } else if (cmd == "show") {
            cout << bike << endl;
        } else if (cmd == "subir") {
            string name {};
            int age {};
            ss >> name >> age;
            Person * p = new Person(name, age);
            if(!bike.subir(p))
                delete p;
        } else if (cmd == "descer") {
            Person * p = bike.descer();
            if (p != nullptr) {
                delete p;
            }
        }
    }
    return 0;
}