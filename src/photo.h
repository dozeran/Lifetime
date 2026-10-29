#ifndef PHOTO_H
#define PHOTO_H

#include <string>

class Photo {
public:
    Photo();
    explicit Photo(std::string title);
    Photo(std::string title, std::string author,
          int width, int height, std::string date);

    ~Photo();

    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    int getWidth() const;
    int getHeight() const;
    const std::string& getDate() const;

    bool isValid() const;

private:
    std::string title_ = "Без назви";
    std::string author_ = "Невідомий автор";
    const int width_ = 0;
    int height_ = 0;
    std::string date_ = "Невідома дата";
};

#endif