#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class Visitor {
public:
    Visitor();
    explicit Visitor(std::string name);
    Visitor(std::string name, int age);

    ~Visitor();

    const std::string& getName() const;
    int getAge() const;

private:
    std::string name_ = "Невідомий відвідувач";
    int age_ = 18;
};

#endif