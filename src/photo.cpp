#include "photo.h"

#include <iostream>
#include <stdexcept>
#include <utility>

Photo::Photo()
    : Photo("Без назви", "Невідомий автор", 1, 1, "Невідома дата") {
}

Photo::Photo(std::string title)
    : Photo(std::move(title), "Невідомий автор", 1, 1, "Невідома дата") {
}

Photo::Photo(std::string title, std::string author,
             int width, int height, std::string date)
    : title_(std::move(title)),
      author_(std::move(author)),
      width_(width),
      height_(height),
      date_(std::move(date)) {

    if (title_.empty()) {
        throw std::invalid_argument("Назва фото не може бути порожньою");
    }

    if (author_.empty()) {
        throw std::invalid_argument("Автор фото не може бути порожнім");
    }

    if (width_ <= 0 || height_ <= 0) {
        throw std::invalid_argument(
            "Роздільна здатність має бути додатною"
        );
    }

    if (date_.empty()) {
        throw std::invalid_argument("Дата зйомки не може бути порожньою");
    }

    std::clog << "[Photo] Створено: " << title_ << '\n';
}

Photo::~Photo() {
    std::clog << "[Photo] Знищено: " << title_ << '\n';
}

const std::string& Photo::getTitle() const {
    return title_;
}

const std::string& Photo::getAuthor() const {
    return author_;
}

int Photo::getWidth() const {
    return width_;
}

int Photo::getHeight() const {
    return height_;
}

const std::string& Photo::getDate() const {
    return date_;
}

bool Photo::isValid() const {
    return !title_.empty()
        && !author_.empty()
        && width_ > 0
        && height_ > 0
        && !date_.empty();
}