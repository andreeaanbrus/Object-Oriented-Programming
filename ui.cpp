//
// Created by Andreea on 3/22/2018.
//

#include <iostream>
#include "ui.h"
#include "dog_validator.h"
#include "CSV_adoption_list.h"
#include "HTMLAdoptionList.h"


void UI::printMenuAdmin() {
    std::cout << "1 -> Display the dogs\n";
    std::cout << "2 -> Add dog\n";
    std::cout << "3 -> Remove dog\n";
    std::cout << "4 -> Update dog's information\n";
    std::cout << "5 -> Undo\n";
    std::cout << "0 -> Exit\n";
}

void UI::printMainMenu() {
    std::cout << "1 -> Admin mode\n";
    std::cout << "2 -> User mode\n";
    std::cout << "0 -> Exit\n";
}

void UI::printMenuUser() {
    std::cout << "1 -> Display dogs one by one\n";
    std::cout << "2 -> Print the adoption list\n";
    std::cout << "3 -> Display dogs by age\n";
    std::cout << "4 -> Save list\n";
    std::cout << "5 -> Show list\n";
    std::cout << "0 -> Exit\n";
}

void UI::printStatisticsMenu() {
    std::cout << "1 -> Save to CSV file\n";
    std::cout << "2 -> Save to HTML file\n";

}

void UI::printMenuChooseToAdopt() {
    std::cout << "1 -> Adopt the dog\n";
    std::cout << "2 -> Next\n";
    std::cout << "0 -> Exit\n";
}

void UI::addDog() {
    std::string breed, name, link;
    int age;
    std::cout << "Give the breed: ";
    std::cin>>breed;
    std::cout << "Give the name: ";
    std::cin >> name;
    std::cout << "Give the age: ";
    std::cin >> age;
    std::cout << "Give the photo link: ";
    std::cin >> link;
    controller.add(breed, name, age, link);
    std::cout << "The dog was added\n";
}

void UI::printDogs() {
    for(const auto& value: controller.getRepo().getDogs())
     {
        std::string s = value.toString();
        std::cout << s << '\n';
    }
}

void UI::removeDog() {
    std::cout << "Give the dog's name: ";
    std::string name;
    std::cin >> name;
    controller.remove(name);
    std::cout << "The dog was removed!\n";
}

void UI::updateDog() {
    std::cout << "Give the dog's name: ";
    std::string name, breed, link;
    int age;
    std::cin >> name;
    std::cout << "Give the new breed: ";
    std::cin >> breed;
    std::cout << "Give the new age: ";
    std::cin >> age;
    std::cout << "Give the new photo link: ";
    std::cin >> link;
    controller.update(name, breed, age, link);
    std::cout << "The dog's info was updated!\n";
}

void UI::displayDogsOneByOne() {
    Repository list = controller.getRepo();
    if (list.getLen() == 0) {
        std::cout << "There are no dogs\n";
        return;
    }
    int i = 0;
    std::vector<Dog> d = list.getDogs();
    unsigned long times = list.getDogs().size();
    while(i != -1) {
        std::string s = d[i % times].toString();
        std::cout << s << '\n';
        d[i % times].play();
        int cmd = -1;
        this->printMenuChooseToAdopt();
        std::cin >> cmd;
        if(cmd == 0) {
            i = -1;
            break;
        }
        switch(cmd) {
            case 1:
                if(!this -> controller.getList()->findByName(d[i% times].getName()))
                    this -> controller.addToList(d[i % times]);
                break;
            case 2:
                break;
            default:break;
        }
        i++;
    }

}

void UI::displayDogsByAge(int nr) {
    std::vector<Dog> list = controller.filterByAge(nr);
    if (list.size() == 0) {
        std::cout << "There are no dogs\n";
        return;
    }
    int i = 0;
    unsigned long times = list.size();
    while(i != -1) {
        std::string s = list[i % times].toString();
        std::cout << s << '\n';
        list[i % times].play();
        int cmd = -1;
        this->printMenuChooseToAdopt();
        std::cin >> cmd;
        if(cmd == 0) {
            i = -1;
            break;
        }
        switch(cmd) {
            case 1:
                if(!controller.getList()->findByName(list[i% times].getName()))
                    controller.addToList(list[i % times]);
                break;
            case 2:
                break;
            default:break;
        }
        i++;
    }
}

void UI::printAdoptionList() {
    AdoptionList* l = controller.getList();
    if (l->getSize() == 0) {
        std::cout << "There are no dogs in the adoption list";
        return;
    }
    for(const auto& value:l->getList())
    {
        std::string s = value.toString();
        std::cout << s << '\n';
    }
}

void UI::run() {
    while (true) {
        this -> printMainMenu();
        int command = 0;
        std::cin >> command;
        if (command == 0)
            break;
        if (command == 1){
            while (true) {
                try {
                    this -> printMenuAdmin();
                    int cmd = 0;
                    std::cin >> cmd;
                    std::cin.ignore();
                    if (cmd == 0)
                        break;
                    switch (cmd) {
                        case 1:
                            this -> printDogs();
                            break;
                        case 2:
                            this -> addDog();
                            break;
                        case 3:
                            this -> removeDog();
                            break;
                        case 4:
                            this -> updateDog();
                            break;
                            default:break;

                    }
                }
                catch (Exception &e) {
                    for (auto &s: e.getErrors())
                        std::cout << s << '\n';
                }
            }
        }
        if (command == 2) {
            printStatisticsMenu();
            int cmd1;
            std::cin >> cmd1;
            if (cmd1 == 1) {
                FileAdoptionList *p = new CSVAdoptionList{"list.csv"};
                controller.setList(p);
            }
            else {
                FileAdoptionList *p = new HTMLAdoptionList{"list.html"};
                controller.setList(p);
            }
            while(true) {
                try {
                    int cmd = -1;
                    this -> printMenuUser();
                    std::cin >> cmd;
                    if(cmd == 0) {
                        for(const auto&value:controller.getList()->getList())
                            controller.remove(value.getName());
                        break;
                    }

                    switch (cmd) {
                        case 1:
                            this -> displayDogsOneByOne();
                            break;
                        case 2:
                            this -> printAdoptionList();
                            break;
                        case 3:
                        {
                            int nr = -1;
                            std::cin >> nr;
                            this -> displayDogsByAge(nr);
                            break;
                        }
                        case 4: {

                            this->controller.saveList();
                            break;
                        }
                        case 5:
                            this -> controller.showList();
                            break;
                        default:break;
                    }
                }
                catch (Exception &e) {
                    for (auto &s: e.getErrors())
                        std::cout << s << '\n';
                }
            }
        }
    }
}





