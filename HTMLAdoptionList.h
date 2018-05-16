//
// Created by andreea on 01.05.2018.
//

#ifndef LAB5_7_HTMLADOPTIONLIST_H
#define LAB5_7_HTMLADOPTIONLIST_H


#include "file_adoption_list.h"

class HTMLAdoptionList : public FileAdoptionList {
public:

    HTMLAdoptionList(const std::string &filename) : FileAdoptionList{ filename } {}
    void writeToFile() override ;
    void displayList() override ;

};


#endif //LAB5_7_HTMLADOPTIONLIST_H
