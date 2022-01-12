#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include "auxiliar.hpp"
#include "fone.hpp"

class Contact {
    std::string name;
    bool star {false};
    std::vector<Fone> fones;
public:
    Contact(std::string name, std::vector<Fone> fones = {}) : name(name){
        this->fones = fones;
    }
    void addFone(Fone fone) {
        fones.push_back(fone);
    }
    void setStar(bool star) {
        this->star = star;
    }
    bool isStar() { return star; }
    std::string getName() { return name; }
    std::vector<Fone> getFones() { return fones; }
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
};

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    return os << (contact.star ? "@ " : "- ") << contact.name << " [" << aux::join(contact.fones, ", ") << "]";
}