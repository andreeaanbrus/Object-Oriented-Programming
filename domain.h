//
// Created by Andreea on 3/22/2018.
//

#ifndef LAB5_7_DOMAIN_H
#define LAB5_7_DOMAIN_H

#include <string>
#include <ostream>

class Dog {
private:
    int age;
    std::string name;
    std::string photo;
    std::string breed;
public:
    Dog();
    Dog(const std::string& breed, const std::string& name,  const int& age, const std::string& photo);
    ~Dog() = default;
    bool operator== (Dog &other) const;
    bool operator<(Dog & other) const;
    friend std::istream& operator >>(std::istream& is, Dog &d);
    friend std::ostream&operator <<(std::ostream& os, const Dog &d);
    std::string getName() const {return  name;}
    std::string getBreed() const {return breed;}
    std::string getPhoto() const {return photo;}
    int getAge() const {return age;};
    std::string toString() const;
    void play();
};


#endif //LAB5_7_DOMAIN_H
