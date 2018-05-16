//
// Created by andreea on 09.05.2018.
//

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include "MyGui.h"

void MyGui::initGUI() {
    QWidget::setWindowTitle("Adopt a dog!");

    QHBoxLayout * mainLayout = new QHBoxLayout(this);
    QVBoxLayout * leftLayout = new QVBoxLayout;
    QVBoxLayout * rightLayout = new QVBoxLayout;
    QHBoxLayout * middleLayout = new QHBoxLayout;
    QHBoxLayout * bottomLeftLayout = new QHBoxLayout;
    QHBoxLayout *bottomRightLayout = new QHBoxLayout;
    this -> list = new QListWidget();
    this -> displayDog = new QLineEdit();
    this -> adoptionList = new QListWidget();

    leftLayout->addWidget(list);

    this -> labelName = new QLabel ("Name");
    auto *name = new QLineEdit();
    labelName -> setBuddy(name);
    leftLayout -> addWidget(labelName);
    leftLayout -> addWidget(name);

    labelBreed = new QLabel ("Breed");
    auto *breed = new QLineEdit();
    labelBreed -> setBuddy(breed);
    leftLayout -> addWidget(labelBreed);
    leftLayout -> addWidget(breed);

    labelAge = new QLabel ("Age");
    auto *age = new QLineEdit();
    labelName -> setBuddy(age);
    leftLayout -> addWidget(labelAge);
    leftLayout -> addWidget(age);

    labelPhoto = new QLabel ("Photo Link");
    auto *photo = new QLineEdit();
    labelName -> setBuddy(photo);
    leftLayout -> addWidget(labelPhoto);
    leftLayout -> addWidget(photo);

    this -> addButton = new QPushButton("Add");
    this -> removeButton = new QPushButton("Remove");
    this -> updateButton = new QPushButton("Update");
    this -> exitButton = new QPushButton("Exit");
    this -> showButton = new QPushButton("Show dog");
    this -> nextButton = new QPushButton("Next");
    this -> chooseDogButton = new QPushButton("Choose");
    this -> userModeButton = new QPushButton("User\n >");
    this -> adminModeButton = new QPushButton("Admin\n <");

    this -> displayDog -> setReadOnly(true);
    this -> displayDog -> setText("primul caine");

    bottomLeftLayout->addWidget(addButton);
    bottomLeftLayout->addWidget(removeButton);
    bottomLeftLayout->addWidget(updateButton);

    leftLayout -> addLayout(bottomLeftLayout);
    leftLayout->addWidget(exitButton);

    bottomRightLayout -> addWidget(showButton);
    bottomRightLayout -> addWidget(nextButton);
    bottomRightLayout -> addWidget(chooseDogButton);

    rightLayout -> addWidget(displayDog);
    rightLayout -> addLayout(bottomRightLayout);
    rightLayout -> addWidget(adoptionList);

    middleLayout -> addWidget(adminModeButton);
    middleLayout -> addWidget(userModeButton);

    mainLayout -> addLayout(leftLayout);
    mainLayout -> addLayout(middleLayout);
    mainLayout -> addLayout(rightLayout);
}

void MyGui::addDogsIntoList() {
    for (const auto &i : c.getRepo().getDogs()) {
        std::string s = i.toString();
        this -> list -> addItem(QString::fromStdString(s));
    }

}

MyGui::MyGui(const Controller &ctrl) : c {ctrl} {
    this -> initGUI();
    this -> addDogsIntoList();
    QObject::connect(this->exitButton, SIGNAL(clicked()), this, SLOT(close()));
}
