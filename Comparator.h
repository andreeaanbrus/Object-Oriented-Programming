//
// Created by andreea on 04.04.2018.
//

#ifndef LAB5_7_COMPARATOR_H
#define LAB5_7_COMPARATOR_H

#include <string>
#include "dynamic_array.h"

template <typename T>
class Comparator {
public:
    Comparator(){};
    virtual bool compare(const T& e1, const T& e2) const = 0;
    virtual ~Comparator(){}
};

class CompareAscendingByAge : public Comparator<Dog> {
private:
public:
    CompareAscendingByAge() = default;
    bool compare(const Dog &e1, const Dog &e2) const override { return  e1.getAge() < e2.getAge() ;}
    ~CompareAscendingByAge(){}
};

class CompareDescendingByName : public Comparator<Dog> {
public:
    CompareDescendingByName() = default;
    bool compare(const Dog &e1, const Dog & e2) const override {return e1.getName() > e2.getName();}
    ~CompareDescendingByName(){}
};

template <typename T>
void sortDogs(DynamicArray<T> & v, Comparator<T> * c) {
    for(int i = 0; i < v.getSize() - 1; i++)
        for(int j = i + 1; j < v.getSize(); j++)
            if(!c -> compare(v.getAllElems()[i], v.getAllElems()[j])) {
                Dog aux = v.getAllElems()[i];
                v.getAllElems()[i] = v.getAllElems()[j];
                v.getAllElems()[j] = aux;
            }
}

#endif //LAB5_7_COMPARATOR_H
