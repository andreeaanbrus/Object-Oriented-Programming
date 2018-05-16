//
// Created by Andreea on 3/22/2018.
//

#ifndef LAB5_7_REPOSITORY_H
#define LAB5_7_REPOSITORY_H

#include <vector>
#include "domain.h"
//#include <iostream>

class Repository {
private:
    std::vector<Dog> dogs;
    std::string filename;
public:
    Repository() = default;
    explicit Repository(const std::string & filename) {this -> filename = filename; readFromFile();}
    std::string getFilename(){ return  filename;}
    void readFromFile();
    void writeToFile();
    ~Repository() = default;
    void add(const Dog& d);
    void remove(int index);
    void removeElem(const Dog& d);
    void update(int index, const Dog& d);
    const std::vector<Dog> & getDogs()const;
    int getLen();
    int findByName(std::string name);
};


#endif //LAB5_7_REPOSITORY_H
