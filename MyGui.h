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
#include <QtWidgets/QDialog>
#include <QtWidgets/QComboBox>
#include "controller.h"

class MyGui : public QWidget{
    Q_OBJECT
private:
    Controller c;
    QListWidget * list;
    QListWidget * adoptionList;
    QLineEdit * displayDog;
    QLineEdit *name;
    QLineEdit *breed;
    QLineEdit *link;
    QLineEdit *age;
    QPushButton * addButton;
    QPushButton * updateButton;
    QPushButton * removeButton;
    QPushButton * exitButton;
    QPushButton * nextButton;
    QPushButton * chooseDogButton;
    QPushButton * userModeButton;
    QPushButton * adminModeButton;
    QPushButton * saveAndDisplayList;
    QLabel * labelName;
    QLabel * labelBreed;
    QLabel * labelAge;
    QLabel * labelPhoto;
    QComboBox * options;
    int i = 0;

    void addDogsIntoList();
    void printAdoptionList();
    void initGUI();

public:
    MyGui(const Controller &ctrl);
    ~MyGui(){}
public slots:
    void addDog();
    void removeDog();
    void updateDog();
    void next();
    void increment(){i++;}
    void chooseDog();
    void savedisplayList();
    void whereToSave();
    void selectedItemList(const QItemSelection& selection);
    void displayOptions();

};


#endif //LAB5_12_MYGUI_H
