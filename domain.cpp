//
// Created by Andreea on 3/22/2018.
//

#include "domain.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <vector>

Dog::Dog(const std::string& breed, const std::string& name, const int& age, const std::string& photo) {
    this ->breed = breed;
    this -> name = name;
    this -> age = age;
    this -> photo = photo;
}

Dog::Dog(): breed(""), name(""), age(0), photo("") {}

std::string Dog::toString() const{
    std::string s;
    s += "Breed: "+ this->getBreed() + " | Name: " + this -> getName() + " | Age: "+ std::to_string(this -> getAge());
    return s;
}

bool Dog::operator==(Dog &other) const {
    return this -> name == other.getName();
}

void Dog::play() {
    /*
     * opens the photo link
     */
    std::string s = "firefox ";
    s += this -> getPhoto();
    const char * cmd = s.c_str();
    FILE * fd = popen(cmd, "w");
    pclose(fd);
}

std::istream &operator>>(std::istream &is, Dog &d) {
    std::string line;
    std::getline(is, line);
    std::vector<std::string> tokens = tokenize(line, ',');
    if(tokens.size() != 4 )
        return is;
    d.breed=tokens[0];
    d.name=tokens[1];
    d.age = std::stoi(tokens[2]);
    d.photo=tokens[3];
    return is;
}

std::ostream &operator<<(std::ostream &os, const Dog &d) {
    os << d.breed << "," << d.name << "," << d.age << "," << d.photo << "\n";
    return os;
}
