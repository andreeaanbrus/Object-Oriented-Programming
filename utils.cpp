//
// Created by andreea on 22.04.2018.
//

#include <sstream>
#include <iostream>
#include "utils.h"

std::vector<std::string> tokenize(const std::string &s, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string token;
    while(std::getline(ss, token, delimiter))
        result.push_back(token);
    return  result;
}
