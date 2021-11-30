//cpp
#include "fone.hpp"
#include <iostream>

Fone::Fone(std::string label, std::string number) 
    : label(label), number(number) {
}

std::string Fone::getLabel() {
    return label;
}