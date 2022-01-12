#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <map>

namespace aux {
    auto fn_id = [](auto x) { return x; };
    auto fn_ptr = [](auto x) { return *x; };
    auto fn_keys = [](auto x) { return x.first; };
    auto fn_values = [](auto x) { return x.second; };
    auto fn_values_ptr = [](auto x) { return *x.second; };

    std::string join(const auto& container, const std::string& delimiter, auto fn) {
        if(container.size() == 0)
            return "";
        std::ostringstream ss;
        for (const auto& item : container)
            ss << delimiter << fn(item);
        return ss.str().substr(delimiter.size());
    }

    auto join(const auto& container, const std::string& delimiter) {
        return join(container, delimiter, [](auto& x){ return x; });
    }

    auto map(const auto& container, auto fn) {
        using output_type = decltype(fn(container.front()));
        std::vector<output_type> result;
        for (const auto& item : container)
            result.push_back(fn(item));
        return result;
    }

    template <typename T>
    T filter(const T& container, auto predicate) {
        T result;
        for (auto& item : container)
            if (predicate(item))
                result.push_back(item);
        return result;
    }

    // separa em um vetor de strings ignorando strings vazias
    std::vector<std::string> split(std::istream& is, char delimit) {
        std::vector<std::string> output;
        std::string token;
        while(std::getline(is, token, delimit))
            if(token.size() > 0)
                output.push_back(token);
        return output;
    }

    std::vector<std::string> split(const std::string& line, char delimit) {
        std::istringstream ss(line);
        return split(ss, delimit);
    }

    template <typename... Args>
    auto parse(std::istream& is) {
        std::tuple<Args...> t;
        std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
        return t;
    }

    template <typename T>
    T read(std::istream& ss) {
        T t;
        ss >> t;
        return t;
    }

    template <typename T>
    std::string to_string(T& t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }

    //convert from string to int or float
    template <typename K>
    K convert(std::string t) {
        std::stringstream ss;
        ss << t;
        K k;
        ss >> k;
        return k;
    }
}