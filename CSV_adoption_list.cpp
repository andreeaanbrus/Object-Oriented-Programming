//
// Created by andreea on 23.04.2018.
//

#include <fstream>
#include "CSV_adoption_list.h"
#include "dog_validator.h"

void CSVAdoptionList::writeToFile() {
    std::ofstream f(this ->filename);
    std::vector<std::string> err;
    err.emplace_back("The file can not be opened");
    if(! f.is_open())
        throw Exception(err);
    for (auto &s: this->getList())
        f << s;
    f.close();
}

void CSVAdoptionList::displayList() {
    std::string s = "libreoffice ";
    s += this -> filename;
    const char * cmd = s.c_str();
    FILE * fd = popen(cmd, "w");
    pclose(fd);
}
