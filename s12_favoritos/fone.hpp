#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>

class Fone {
    std::string label;
    std::string number;
public:
    Fone(std::string label, std::string number) : label(label), number(number) {}
    std::string get_label() { return label; }
    std::string get_number() { return number; }
    friend std::ostream& operator<<(std::ostream& os, const Fone& fone);
};

std::ostream& operator<<(std::ostream& os, const Fone& fone) {
    return os << fone.label << ":" << fone.number;
}
