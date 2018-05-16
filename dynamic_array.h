#pragma once
#include "domain.h"

//typedef Dog TElement;
template <typename TElement>
class DynamicArray
{
private:
    TElement* elems;
    int len;
    int capacity;

public:
    DynamicArray& operator- (const TElement& t);
    explicit DynamicArray(int capacity = 10);
    DynamicArray(const DynamicArray& v);
    ~DynamicArray();
    DynamicArray& operator=(const DynamicArray& v);
    TElement& operator[](int pos);
    int getSize() const;
    TElement* getAllElems() const;
    void add(const TElement& e);
    void addToPosition(int index, const TElement& e);
    void remove(int index);
    void update(int index, const TElement& e);
    void removeElem(const TElement& e);

private:
    void resize(double factor = 2);
};


#include <iostream>
#include"dynamic_array.h"

template <typename TElement>
DynamicArray<TElement>::DynamicArray(int capacity) {
    this -> len = 0;
    this -> capacity = capacity;
    this -> elems = new TElement[capacity];
}

template <typename TElement>
DynamicArray<TElement>::DynamicArray(const DynamicArray<TElement>& v) {
    this -> len = v.len;
    this -> capacity = v.capacity;
    this -> elems = new TElement[this -> capacity];
    for (int i = 0; i < this -> len; i++)
        this -> elems[i] = v.elems[i];
}


template <typename TElement>
DynamicArray<TElement>::~DynamicArray()
{
    delete[] this -> elems;
}

template <typename TElement>
DynamicArray<TElement>& DynamicArray<TElement>::operator=(const DynamicArray<TElement>& v)
{
    if (this == &v)
        return *this;

    this -> len = v.len;
    this -> capacity = v.capacity;

    delete[] this -> elems;
    this -> elems = new TElement[this -> capacity];
    for (int i = 0; i < this -> len; i++)
        this -> elems[i] = v.elems[i];
    return *this;
}

template <typename TElement>
void DynamicArray<TElement>::add(const TElement& e)
{
    if (this -> len == this -> capacity)
        this -> resize();
    this -> elems[this -> len] = e;
    this -> len++;
}

template <typename TElement>
void DynamicArray<TElement>::resize(double factor)
{
    this -> capacity *= static_cast<int>(factor);

    auto aux = new TElement[this -> capacity];
    for (int i = 0; i < this -> len; i++)
        aux[i] = this -> elems[i];
    delete[] this -> elems;
    this -> elems = aux;
}

template <typename TElement>
TElement* DynamicArray<TElement>::getAllElems() const
{
    return this -> elems;
}

template <typename TElement>
int DynamicArray<TElement>::getSize() const
{
    return this -> len;
}

template <typename TElement>
void DynamicArray<TElement>::remove(int index) {
    if (index < 0 || index > this -> len)
        return;
    for(int i = index; i < this -> len - 1; i++)
        this -> elems[i] = this -> elems[i + 1];
    this -> len--;
}

template <typename TElement>
void DynamicArray<TElement>::update(int index, const TElement &e) {
    this -> elems[index] = e;
//    remove(index);
//    std::cout << index;
//    addToPosition(index, e);
}

template <typename TElement>
void DynamicArray<TElement>::addToPosition(int index, const TElement &e) {
    if(this -> len == this -> capacity)
        resize();
    this -> len ++;
    for(int i = this -> len - 1; i >= index; i--)
        this -> elems[i+1] = this -> elems[i];
    this -> elems[index] = e;
}

template <typename TElement>
void DynamicArray<TElement>::removeElem(const TElement &e) {
    //== overloaded in Dogs
    int index = 0;
    for(int i = 0; i < this -> len; i++)
        //used ==
        if (e == this -> elems[i])
            index = i;
    remove(index);
}

template <typename TElement>
DynamicArray<TElement>& DynamicArray<TElement>::operator-( const TElement &t) {
    removeElem(t);
    return *this;
}

template<typename TElement>
TElement & DynamicArray<TElement> ::operator[](int pos) {
    return this-> elems[pos];
}

