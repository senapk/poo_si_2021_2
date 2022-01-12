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
    bool rebuildStar {true};

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


    std::vector<Contact> getStar() {
        static std::vector<Contact> starred;
        if (rebuildStar) {
            starred.clear();
            for (auto& contact : contacts) {
                if (contact.second.isStar())
                    starred.push_back(contact.second);
            }
            rebuildStar = false;
        }
        return starred;
    }

    Contact get(std::string name) {
        return *at(name);
    }

    void star(std::string name, bool value) {
        at(name)->setStar(value);
        rebuildStar = true;
    }

    void remove(std::string name) {
        contacts.erase(name);
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
    for (auto& [key, contact] : agenda.contacts)
        os << contact << '\n';
    return os;
}