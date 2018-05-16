//
// Created by andreea on 02.04.2018.
//

#ifndef LAB5_7_ADOPTION_LIST_H
#define LAB5_7_ADOPTION_LIST_H


#include <vector>
#include "domain.h"

class AdoptionList {
private:
    std::vector<Dog> list;
    int current;
public:
    void add(const Dog& d);
    bool isEmpty();
    void next();
    std::vector<Dog> getList(){return this->list;}
    const Dog & getCurrentDog(int pos);
    const int getSize();
    bool findByName(std::string name);
};


#endif //LAB5_7_ADOPTION_LIST_H
