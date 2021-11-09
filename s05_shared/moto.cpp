#include <iostream>
#include <utility>
#include <sstream>
#include <memory>
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
    shared_ptr<Person> person;
public:
    Bike(shared_ptr<Person> pessoa = nullptr) : person(pessoa) {}
    ~Bike() {
    }

    bool subir(shared_ptr<Person> person) {
        if (this->person == nullptr) {
            this->person = person;
            return true;
        }
        return false;
    }

    shared_ptr<Person> descer() {
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
            shared_ptr<Person> p = bike.descer();
            break;
        } else if (cmd == "show") {
            cout << bike << endl;
        } else if (cmd == "subir") {
            string name {};
            int age {};
            ss >> name >> age;
            bike.subir(make_shared<Person>(name, age));
        } else if (cmd == "descer") {
            bike.descer();
        }
    }
    return 0;
}