#include "visitor.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace {
    int visitorCount = 0;
}

Visitor::Visitor()
    : Visitor("Невідомий відвідувач", 18) {
}

Visitor::Visitor(std::string name)
    : Visitor(std::move(name), 18) {
}

Visitor::Visitor(std::string name, int age)
    : name_(std::move(name)),
      age_(age) {

    if (name_.empty()) {
        throw std::invalid_argument("Ім'я відвідувача не може бути порожнім");
    }

    if (age_ < 0 || age_ > 120) {
        throw std::invalid_argument("Вік відвідувача має бути від 0 до 120");
    }

    ++visitorCount;
    std::clog << "[Visitor] Створено: " << name_
              << " | Активних об'єктів: " << visitorCount << '\n';
}

Visitor::~Visitor() {
    std::clog << "[Visitor] Знищено: " << name_
              << " | Активних об'єктів: " << visitorCount - 1 << '\n';
    --visitorCount;
}

const std::string& Visitor::getName() const {
    return name_;
}

int Visitor::getAge() const {
    return age_;
}