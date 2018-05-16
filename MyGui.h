//
// Created by andreea on 09.05.2018.
//

#ifndef LAB5_12_MYGUI_H
#define LAB5_12_MYGUI_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextBrowser>
#include "controller.h"

class MyGui : public QWidget{
private:
    Controller c;
    QListWidget * list;
    QLineEdit * displayDog;
    QListWidget * adoptionList;
    QPushButton * addButton;
    QPushButton * updateButton;
    QPushButton * removeButton;
    QPushButton * exitButton;
    QPushButton * showButton;
    QPushButton * nextButton;
    QPushButton * chooseDogButton;
    QPushButton * userModeButton;
    QPushButton * adminModeButton;
    QLabel * labelName;
    QLabel * labelBreed;
    QLabel * labelAge;
    QLabel * labelPhoto;

    void addDogsIntoList();
    void initGUI();

public:
    MyGui(const Controller &ctrl);
    ~MyGui(){}
};


#endif //LAB5_12_MYGUI_H
