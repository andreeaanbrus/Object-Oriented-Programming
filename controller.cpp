//
// Created by Andreea on 3/22/2018.
//

#include <iostream>
#include <algorithm>
#include "controller.h"
#include "dog_validator.h"
#include "UndoAction.h"

int Controller::findInRepo(const std::string &name) {
    /*  finds if there is a dog with the name "name" in repo
     *  return the index of the dog if found
     *  -1 if not found
     */
    int index = 0;
    for (const auto& value:repo.getDogs())
        if (value.getName() == name)
            return index;
        else
            index ++;
    return -1;
}

Dog Controller::findByIndex(int i) {
    return this -> repo.getDogs()[i];
}

Repository& Controller::getRepo() {
    return repo;
}

void Controller::add(std::string breed, std::string name, int age, std::string photo) {
    /*
     * add a new dog to the list
     * if the name already exists, the dog will not be added
     */
    std::vector<std::string> err;
    err.push_back("Invalid name!");
    if (findInRepo(name) != -1) {
        throw Exception(err);
    }
    Dog d(breed, name, age, photo);
    DogValidator::validate(d);
    this -> repo.add(d);
//    UndoAction *a = new UndoAdd{d, repo};
//    undoList.push_back(a);
}

void Controller::remove(const std::string & name) {
    /*
     * removes a dog from the list, by name
     * if the name does not exist in the list, an exception is thrown
     */
    std::vector<std::string> err;
    err.push_back("Invalid name!");
    int index = this -> repo.findByName(name);
    if (index == -1)
        throw Exception(err);
    //this -> repo.remove(index);
    Dog d = findByIndex(index);
    this -> repo.removeElem(d);
//    UndoAction *a = new UndoRemove{repo, d};
//    undoList.push_back(a);
}

void Controller::update(const std::string &name, const std::string &breed, const int &age, const std::string &photo) {
    /*
     * updates the info of a dog
     * the name does not change
     * if the name does not exist in the list, an exception is thrown
     */
    std::vector<std::string> err;
    err.push_back("Invalid name!");
    int index = this -> repo.findByName(name);
    if (index == -1)
        throw Exception(err);
    Dog d(breed, name, age, photo);
    DogValidator::validate(d);
    this -> repo.update(index, d);
}

std::vector<Dog> Controller::filterByAge(const int age) {
    /*
     * Filters the list by age
     * */
    unsigned long nrDogs = static_cast<unsigned long>(std::count_if(repo.getDogs().begin(), repo.getDogs().end(),
                                                                    [age](const Dog& d) { return d.getAge() == age;}));
    std::vector<Dog> byAge(nrDogs);
    auto it = std::copy_if(repo.getDogs().begin(), repo.getDogs().end(), byAge.begin(), [age](const Dog& d){return d.getAge() == age;});
        for (auto&i :byAge)
            std::cout << i << '\n';
    return byAge;
}

void Controller::addToList(const Dog &d) {
    /*
     * Add a dog to the adoption list
     * */
    for(auto &i: list->getList())
        if(d == i)
            throw "The dog is already in the list!";
    list->add(d);

}

void Controller::saveList() {
    /*
     * Save the current adoption list to the csv file
     * */
    list->writeToFile();
}

void Controller::showList() const{
    /*
     * Open the csv adoption list with libre office
     * */
    return list->displayList();
}

void Controller::setList(FileAdoptionList *l) {
    //free memory
    if (l == nullptr)
        delete(l);
    this -> list = l;
}
//
//void Controller::undo() {
//
//    UndoAction *a = undoList.back();
//    a -> executeUndo();
//    undoList.pop_back();
//    delete a;
//}
//
//Controller::~Controller() {
//    for(auto &i : this -> undoList)
//        delete i;
//}

