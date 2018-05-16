//
// Created by andreea on 23.04.2018.
//

#ifndef LAB5_7_CSV_ADOPTION_LIST_H
#define LAB5_7_CSV_ADOPTION_LIST_H


#include <string>
#include "file_adoption_list.h"

class CSVAdoptionList : public FileAdoptionList{
public:
    CSVAdoptionList(const std::string &filename) : FileAdoptionList{ filename } {}
    void writeToFile() override ;
    void displayList() override ;

};


#endif //LAB5_7_CSV_ADOPTION_LIST_H
