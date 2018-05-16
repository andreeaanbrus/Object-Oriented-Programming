//
// Created by andreea on 01.05.2018.
//

#include <fstream>
#include "HTMLAdoptionList.h"

void HTMLAdoptionList::displayList() {
    std::string s = "firefox ";
    s += filename;
    const char * cmd = s.c_str();
    FILE * fd = popen(cmd, "w");
    pclose(fd);

}
void HTMLAdoptionList::writeToFile() {
    std::ofstream fout (filename);
    fout << "\n"
            "<!DOCTYPE html>\n"
            "<html>\n"
            "<head>\n"
            "<title>Adoption List</title>\n"
            "</head>\n"
            "<body>\n"
            "<table border=\"1\">\n"
            "              <tr>\n"
            "              <td>Dog's breed</td>\n"
            "<td>Dog's name</td>\n"
            "<td>Dog's age</td>\n"
            "<td>Dog's photo</td>\n"
            "</tr>\n";

    for(auto &i : this -> getList()) {
        std::string s = "<tr>\n "
                              "<td>"+i.getBreed()+"</td>\n"
                              "<td>"+i.getName()+"</td>\n"
                              "<td>"+std::to_string(i.getAge())+"</td>\n"
                              "<td>"+i.getPhoto()+"</td>\n"
                              "</tr>\n"
                              "\n";
        fout << s;
    }
    fout << "</table>\n"
            " </body>\n";

}
