//hpp
#pragma once
#include <iostream>
class Fone {
    std::string label;
    std::string number;
public:
    Fone(std::string label, std::string number);
    std::string getLabel();
    std::string getNumber() {
        return number;
    }
};