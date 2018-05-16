//
// Created by Andreea on 3/22/2018.
//

#include <fstream>
#include "repository.h"
#include "dog_validator.h"

void Repository::add(const Dog &d) {
    this -> dogs.push_back(d);
    this -> writeToFile();
}

void Repository::remove(int index) {
    if(index < 0) return;
    if(index > this -> dogs.size()) return;
    auto it = this->dogs.begin() + index;
    this -> dogs.erase(it);
    this -> writeToFile();
}

const std::vector<Dog> & Repository::getDogs()const {
    return dogs;
}

void Repository::update(int index, const Dog& d) {
    this -> dogs[index] = d;
    this -> writeToFile();
}

//void Repository::addToPosition(int i, const Dog& dog) {
//    this -> dogs.addToPosition(i, dog);
//}

int Repository::getLen() {
    return static_cast<int>(this -> dogs.size());
}

int Repository::findByName(std::string name) {
    int index = 0;
    for(auto const & value : this->dogs)
        if(value.getName() != name)
            index ++;
        else
            return index;
    return -1;
}

void Repository::removeElem(const Dog &d) {
//    this -> dogs = this->dogs - d;
    int i = findByName(d.getName());
    auto it = this -> dogs.begin() + i;
    this -> dogs.erase(it);
    this -> writeToFile();
}

void Repository::readFromFile() {
    std::vector<std::string> err;
    err.push_back("The file can not be opened");
    std::ifstream fin(this -> filename);
    if(!fin.is_open())
        throw Exception(err);
    Dog d;
    while(fin >> d) {
        this -> dogs.push_back(d);
    }
    fin.close();
}

void Repository::writeToFile() {
    std::vector<std::string> err;
    err.push_back("The file can not be opened");
    std::ofstream fout(this -> filename);
    if(!fout.is_open())
        throw Exception(err);
    for( auto & d: this->dogs)
        fout << d;
    fout.close();
}
