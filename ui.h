//
// Created by Andreea on 3/22/2018.
//

#ifndef LAB5_7_UI_H
#define LAB5_7_UI_H


#include "controller.h"

class UI {
private:
    Controller controller;
    void printMenuAdmin();
    void printMainMenu();
    void printMenuUser();
    void printMenuChooseToAdopt();
    void printStatisticsMenu();
    void addDog();
    void printDogs();
    void removeDog();
    void updateDog();
    void displayDogsOneByOne();
    void printAdoptionList();
    void displayDogsByAge(int nr);

public:
    UI(const Controller& c) : controller(c) {}
    void run();
};


#endif //LAB5_7_UI_H
