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
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repo {"dogs.txt"};
    FileAdoptionList* list = nullptr;
    Controller controller { repo , list};
    UI ui{controller};
    ui.run();
//    MyGui ui{controller};
//    ui.show();
//    return a.exec();
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
}