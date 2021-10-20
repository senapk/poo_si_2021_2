#pragma once

#include <iostream>
#include <vector>

template <typename Tipo>
void testar(Tipo A, Tipo B) {
    if (A == B) {
        std::cout << "  OK" << std::endl;
    } else {
        std::cout << "  " << A << " != " << B << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vet) {
    os << "[";
    for (int i = 0; i < (int) vet.size(); i++) {
        os << vet[i];
        if (i != (int) vet.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}