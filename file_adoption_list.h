//
// Created by andreea on 23.04.2018.
//

#ifndef LAB5_7_FILE_ADOPTION_LIST_H
#define LAB5_7_FILE_ADOPTION_LIST_H


#include "adoption_list.h"

class FileAdoptionList : public AdoptionList {
public:
    explicit FileAdoptionList(const std::string & filename) {this -> filename = filename;}
    virtual ~FileAdoptionList() {}
    virtual void writeToFile() = 0;
    virtual void displayList() = 0;

protected:
    std::string filename;
};


#endif //LAB5_7_FILE_ADOPTION_LIST_H
