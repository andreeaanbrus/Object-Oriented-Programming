//
// Created by andreea on 24.04.2018.
//

#ifndef LAB5_7_DOG_VALIDATOR_H
#define LAB5_7_DOG_VALIDATOR_H

#include <vector>
#include <string>
#include "domain.h"
#include "repository.h"

class Exception {
private:
    std::vector<std::string> errors;
public:
    explicit Exception(const std::vector<std::string> err) {errors = err;}
    ~Exception(){}
    std::vector<std::string> getErrors() { return errors; }
};


class DogValidator {
public:
    static void validate(const Dog& d);
};

#endif //LAB5_7_DOG_VALIDATOR_H
