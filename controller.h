//
// Created by Andreea on 3/22/2018.
//

#ifndef LAB5_7_CONTROLLER_H
#define LAB5_7_CONTROLLER_H


#include "repository.h"
#include "adoption_list.h"
#include "file_adoption_list.h"
#include "UndoAction.h"

class Controller {
private:
    Repository repo;
    FileAdoptionList * list;
//    std::vector <UndoAction*> undoList;
public:
    explicit Controller(const Repository& r, FileAdoptionList *l) : repo{ r }, list { l } {};
    ~Controller(){};
    Repository& getRepo();
    AdoptionList* getList() const { return list; };
    void add(std::string breed, std::string name, int age, std::string photo);
    void remove(const std::string& name);
    void update(const std::string& name, const std::string& breed, const int& age, const std::string& photo);
    int findInRepo(const std::string &name);
    void addToList(const Dog &d);
    void saveList();
    void showList() const;
    void setList(FileAdoptionList* l) ;
//    void undo();
    Dog findByIndex(int);
    std::vector<Dog> filterByAge(const int age);
};



#endif //LAB5_7_CONTROLLER_H
