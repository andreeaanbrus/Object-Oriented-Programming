//
// Created by andreea on 24.04.2018.
//

#include "dog_validator.h"

void DogValidator::validate(const Dog &d) {
    // error if the size of breed < 3
    std::vector<std::string> errors;
    if (d.getBreed().size() < 3)
        errors.push_back("Invalid breed!");
    if(d.getName().size() < 2)
        errors.push_back("Invalid name!");
    if(d.getAge() < 0 || d.getAge() > 10)
        errors.push_back("Invalid age!");
    if(d.getPhoto().find("http") != 0 && d.getPhoto().find("www") != 0)
        errors.push_back("Invalid photo link");
    if(errors.size() > 0)
        throw Exception(errors);
}

