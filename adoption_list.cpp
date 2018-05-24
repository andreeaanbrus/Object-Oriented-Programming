//
// Created by andreea on 02.04.2018.
//

#include "adoption_list.h"

bool AdoptionList::isEmpty() {
    return this->list.empty();
}

void AdoptionList::add(const Dog &d) {
    this->list.push_back(d);
}

const Dog & AdoptionList::getCurrentDog(int pos) {
    return this -> list[pos];
}

void AdoptionList::next() {
    if(this->list.empty())
        return;
    this -> current++;
    Dog d = getCurrentDog(current);
    d.play();
}

const int AdoptionList::getSize() {
    return static_cast<const int>(this ->list.size());
}

bool AdoptionList::findByName(std::string name) {
    for(const auto& value:this->list)
        if(value.getName() == name)
            return true;
    return false;
}


