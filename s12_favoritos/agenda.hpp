#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include "auxiliar.hpp"
#include "contact.hpp"

class Agenda {
    std::map<std::string, Contact> contacts;
    std::map<std::string, Contact*> starred;

    Contact* at(std::string name) {
        auto it = contacts.find(name);
        if (it == contacts.end())
            throw std::runtime_error("fail: nao existe esse contato");
        return &it->second;
    }

public:
    Agenda() {}
    void add(std::string name, std::vector<Fone> fones) {
        auto it = contacts.find(name);
        if (it == contacts.end()) { //nao existe contato
            contacts.insert({name, Contact(name, fones)});
        } else { //existe o contato
            Contact& contact = it->second;
            for (auto& fone : fones)
                contact.addFone(fone);
        }
    }

    Contact get(std::string name) {
        return *at(name);
    }

    std::vector<Contact> getStarred() {
        return aux::map(starred, aux::map_values_ptr);
    }

    void star(std::string name, bool value) {
        at(name)->setStar(value);
        if (value) {
            starred[name] = at(name);
        } else {
            starred.erase(name);
        }
    }

    void remove(std::string name) {
        contacts.erase(name);
        starred.erase(name);
    }

    std::vector<Contact> search(std::string pattern) {
        std::vector<Contact> result;
        for (auto& [key, contact] : contacts)
            if (aux::to_string(contact).find(pattern) != std::string::npos)
                result.push_back(contact);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Agenda& agenda);
};

std::ostream& operator<<(std::ostream& os, const Agenda& agenda) {
    return os << aux::join(agenda.contacts, "\n", aux::map_values);
}

