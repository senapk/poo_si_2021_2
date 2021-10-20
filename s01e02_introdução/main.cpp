#include <iostream>
#include <vector>

bool existe(std::vector<int> vet, int value) {
    for(int x : vet)
        if(x == value)
            return true;
    return false;
}


std::vector<int> impares(std::vector<int> vet) {
    std::vector<int> impares;
    for (int x : vet) {
        if (x % 2 == 1) {
            impares.push_back(x);
        }
    }
    return impares;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (int x : v) {
        os << x << " ";
    }
    os << "]";
    return os;
}

int main() 
{
    std::cout << impares({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << '\n';
}