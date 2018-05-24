//
// Created by andreea on 09.05.2018.
//

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QApplication>
#include <iostream>
#include <QtCore/QMutex>
#include <QtCore/QEventLoop>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>
#include <QtCore/QThread>
#include <QDebug>
#include <QtWidgets/QErrorMessage>
#include <QtWidgets/QAction>
#include "MyGui.h"
#include "HTMLAdoptionList.h"
#include "CSV_adoption_list.h"
#include "dog_validator.h"

void MyGui::initGUI() {
    QWidget::setWindowTitle("Adopt a dog!");

    QHBoxLayout * mainLayout = new QHBoxLayout(this);
    QVBoxLayout * leftLayout = new QVBoxLayout;
    QVBoxLayout * rightLayout = new QVBoxLayout;
    QHBoxLayout * middleLayout = new QHBoxLayout;
    QHBoxLayout * bottomLeftLayout = new QHBoxLayout;
    QHBoxLayout *bottomRightLayout = new QHBoxLayout;

    this -> list = new QListWidget();
    this -> options = new QComboBox();
    this -> displayDog = new QLineEdit();
    this -> adoptionList = new QListWidget();

    this -> options->addItem("detailed");
    this -> options->addItem("short");

    leftLayout->addWidget(options);
    leftLayout->addWidget(list);

    this -> labelName = new QLabel ("Name");
    this -> name = new QLineEdit();
    labelName -> setBuddy(name);
    leftLayout -> addWidget(labelName);
    leftLayout -> addWidget(name);

    labelBreed = new QLabel ("Breed");
    this -> breed = new QLineEdit();
    labelBreed -> setBuddy(breed);
    leftLayout -> addWidget(labelBreed);
    leftLayout -> addWidget(breed);

    labelAge = new QLabel ("Age");
    this -> age = new QLineEdit();
    labelName -> setBuddy(age);
    leftLayout -> addWidget(labelAge);
    leftLayout -> addWidget(age);

    labelPhoto = new QLabel ("Photo Link");
    this -> link = new QLineEdit();
    labelName -> setBuddy(link);
    leftLayout -> addWidget(labelPhoto);
    leftLayout -> addWidget(link);

    this -> addButton = new QPushButton("Add");
    this -> removeButton = new QPushButton("Remove");
    this -> updateButton = new QPushButton("Update");
    this -> exitButton = new QPushButton("Exit");
    this -> nextButton = new QPushButton("Next");
    this -> saveAndDisplayList = new QPushButton("Save and display list");
    this -> chooseDogButton = new QPushButton("Choose");
    this -> userModeButton = new QPushButton("User\n >");
    this -> adminModeButton = new QPushButton("Admin\n <");

    this -> displayDog -> setReadOnly(true);
    int times = c.getRepo().getLen();
    std::string d = c.getRepo().getDogs()[i%times].toString();
    this -> displayDog -> setText(QString::fromStdString(d));
    bottomLeftLayout->addWidget(addButton);
    bottomLeftLayout->addWidget(removeButton);
    bottomLeftLayout->addWidget(updateButton);

    leftLayout -> addLayout(bottomLeftLayout);
    leftLayout->addWidget(exitButton);

    bottomRightLayout -> addWidget(nextButton);
    bottomRightLayout -> addWidget(chooseDogButton);
    bottomRightLayout -> addWidget(saveAndDisplayList);

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
    list->clear();
    for (const auto &i : c.getRepo().getDogs()) {
        std::string s = i.toString();
        this -> list -> addItem(QString::fromStdString(s));
    }

}

void MyGui::printAdoptionList() {
    adoptionList -> clear();
    if(c.getList()->getSize() == 0)
        return;
    for(auto& value:c.getList()->getList())
    {
        std::string s = value.toString();
        this -> adoptionList -> addItem(QString::fromStdString(s));
    }
}

void MyGui::addDog() {
    try{

        QString qname, qbreed, qlink, qage;
        qbreed = breed -> text();
        qname = name -> text();
        qage = age -> text();
        qlink = link -> text();
        std::string n, b, l;
        int a;
        n = qname.toUtf8().constData();
        b = qbreed.toUtf8().constData();
        l = qlink.toUtf8().constData();
        a = qage.toInt();
        c.add(b, n, a, l);
        addDogsIntoList();
        name->clear();
        breed->clear();
        link->clear();
        age->clear();
    }
    catch(Exception &e){
        for(auto&i: e.getErrors()){
            auto msg = new QErrorMessage(this);
            msg->showMessage(QString::fromStdString(i));
        }

    }
}

void MyGui::removeDog() {
    try{

        QString qname;
        qname = name -> text();
        std::string n;
        n = qname.toUtf8().constData();
        c.remove(n);
        addDogsIntoList();
        name->clear();
    }
    catch(Exception& e){
        for(auto&i: e.getErrors()){
            auto msg = new QErrorMessage(this);
            msg->showMessage(QString::fromStdString(i));
        }

    }
}

void MyGui::updateDog() {
    try{

        QString qname, qbreed, qlink, qage;
        qbreed = breed -> text();
        qname = name -> text();
        qage = age -> text();
        qlink = link -> text();
        std::string n, b, l;
        int a;
        n = qname.toUtf8().constData();
        b = qbreed.toUtf8().constData();
        l = qlink.toUtf8().constData();
        a = qage.toInt();
        std::cout << a;
        c.update(n, b, a, l);
        addDogsIntoList();
        name->clear();
        breed->clear();
        link->clear();
        age->clear();
    }
    catch(Exception& e){
        for(auto&i: e.getErrors()){
            auto msg = new QErrorMessage(this);
            msg->showMessage(QString::fromStdString(i));
        }

    }
}


void MyGui::next() {
    increment();
    int times = c.getRepo().getLen();
    Dog d = c.getRepo().getDogs()[i%times];
    std::string s = d.toString();
    d.play();
    this -> displayDog -> setText(QString::fromStdString(s));
}

void MyGui::chooseDog() {
    int times = c.getRepo().getLen();
    this -> c.addToList(c.getRepo().getDogs()[i%times]);
    this -> c.remove(c.getRepo().getDogs()[i%times].getName());
    printAdoptionList();
    addDogsIntoList();
}

void MyGui::savedisplayList() {
    this->c.saveList();
    this->c.showList();
}

MyGui::MyGui(const Controller &ctrl) : c {ctrl} {

    this->initGUI();
    this->addDogsIntoList();
    this->printAdoptionList();
    QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addDog()));
    QObject::connect(this->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(this->removeButton, SIGNAL(clicked()), this, SLOT(removeDog()));
    QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateDog()));
    QObject::connect(this->nextButton, SIGNAL(clicked()), this, SLOT(next()));
    QObject::connect(this->chooseDogButton, SIGNAL(clicked()), this, SLOT(chooseDog()));
    QObject::connect(this->saveAndDisplayList, SIGNAL(clicked()), this, SLOT(savedisplayList()));
    QObject::connect(this -> userModeButton, SIGNAL(clicked()), this, SLOT(whereToSave()));
    QObject::connect(this -> list ->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(selectedItemList(QItemSelection)));
    QObject::connect(this->options, SIGNAL(currentTextChanged(QString)), this, SLOT(displayOptions()));
}

void MyGui::whereToSave() {
    QMessageBox messageBox(QMessageBox::Question,
                           tr("Sure want to quit?"),
                           tr("Select the type of file"),
                           QMessageBox::Yes | QMessageBox::No,
                           this);
    messageBox.setButtonText(QMessageBox::Yes, tr("Save to HTML file"));
    messageBox.setButtonText(QMessageBox::No, tr("Save to CSV file"));
    FileAdoptionList *p;
    if(messageBox.exec() == QMessageBox::No)
    {

        p = new CSVAdoptionList("list.csv");
        this -> adoptionList->clear();
    }
    else{

        p = new HTMLAdoptionList("list.html");
        this -> adoptionList->clear();
    }
    c.setList(p);
}

void MyGui::selectedItemList(const QItemSelection &selection) {
    int nr =  this->list->currentRow();
    Dog d = c.getRepo().getDogs()[nr];
    this -> name->setText(QString::fromStdString(d.getName()));
    this -> breed->setText(QString::fromStdString(d.getBreed()));
    this -> age->setText(QString::fromStdString(std::to_string(d.getAge())));
    this -> link->setText(QString::fromStdString(d.getPhoto()));
}

void MyGui::displayOptions() {
    if(options->currentText() == "short"){

        list->clear();
        for (const auto &i : c.getRepo().getDogs()) {
            std::string s = i.getName();
            this -> list -> addItem(QString::fromStdString(s));
        }
    }
    else {
        list -> clear();
        for(const auto&i : c.getRepo().getDogs()){
            std::string s = i.toString();
            this -> list -> addItem(QString::fromStdString(s));
        }
    }

}

