//
// Created by andreea on 07.05.2018.
//

#ifndef LAB5_7_UNDOACTION_H
#define LAB5_7_UNDOACTION_H


#include "domain.h"
#include "repository.h"

class UndoAction {
public:
    ~UndoAction() {};
    virtual void executeUndo() = 0;
};

class UndoAdd : public UndoAction {
private:
    Dog dog;
    Repository & repo;
public:
    UndoAdd(const Dog &s, Repository &r) : dog {s} , repo {r} {};
    void executeUndo() override ;
};

class UndoRemove : public UndoAction {
private:
    Dog dog;
    Repository &repo;
public:
    UndoRemove(Repository &r, Dog &s): repo { r } , dog { s } {};
    void executeUndo() override ;
};

#endif //LAB5_7_UNDOACTION_H
