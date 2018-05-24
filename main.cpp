#include <iostream>
#include <QtWidgets/QApplication>
#include "dynamic_array.h"
#include "repository.h"
#include "controller.h"
#include "ui.h"
#include "tests.h"
#include "utils.h"
#include "CSV_adoption_list.h"
#include "MyGui.h"
#include "dog_validator.h"
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repo {"dogs.txt"};
    FileAdoptionList* list = nullptr;
    Controller controller { repo , list};
    FileAdoptionList *p = new CSVAdoptionList("aux.csv");
    controller.setList(p);
//    UI ui{controller};
//    ui.run();
    MyGui ui{controller};
    ui.show();
    return a.exec();
}

//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
