#include "photo.h"
#include "visitor.h"

#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::clog << "\n=== Початок програми ===\n";

    Photo firstPhoto(
        "Гірський пейзаж",
        "Олена Коваль",
        1920,
        1080,
        "2026-05-12"
    );

    Visitor firstVisitor("Іван Петренко", 25);

    {
        std::clog << "\n=== Вкладена область видимості ===\n";

        Photo secondPhoto(
            "Морський світанок",
            "Марія Шевченко",
            3840,
            2160,
            "2026-06-20"
        );

        Visitor secondVisitor("Андрій Мельник", 31);

        std::cout << "Фото: " << secondPhoto.getTitle() << '\n';
        std::cout << "Відвідувач: " << secondVisitor.getName() << '\n';

        std::clog << "=== Завершення вкладеної області ===\n";
    }

    std::clog << "\n=== Статичний об'єкт ===\n";

    static Photo staticPhoto(
        "Архітектура міста",
        "Олексій Бондар",
        2560,
        1440,
        "2026-07-01"
    );

    std::cout << "Статичне фото: " << staticPhoto.getTitle() << '\n';

    std::clog << "\n=== Експеримент: new без delete ===\n";

    Photo* leakedPhoto = new Photo(
        "Тест витоку пам'яті",
        "Тестовий автор",
        800,
        600,
        "2026-09-01"
    );

std::cout << "Динамічне фото: " << leakedPhoto->getTitle() << '\n';

    std::clog << "\n=== Динамічний об'єкт через unique_ptr ===\n";

    auto dynamicPhoto = std::make_unique<Photo>(
        "Лісова стежка",
        "Ірина Ткаченко",
        1600,
        900,
        "2026-08-15"
    );

    std::cout << "Динамічне фото: " << dynamicPhoto->getTitle() << '\n';

    std::clog << "\n=== Вектор об'єктів ===\n";

    std::vector<Photo> photos;

    photos.emplace_back(
        "Зимовий ліс",
        "Петро Савчук",
        1920,
        1080,
        "2026-01-10"
    );

    photos.emplace_back(
        "Осінній парк",
        "Наталія Лисенко",
        2048,
        1536,
        "2026-10-05"
    );

    std::cout << "Кількість фото у векторі: " << photos.size() << '\n';

    std::clog << "\n=== Завершення програми ===\n";

    return 0;
}