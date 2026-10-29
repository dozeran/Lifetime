#include "photo.h"

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

TEST(PhotoTest, DefaultConstructor) {
    Photo photo;

    EXPECT_EQ(photo.getTitle(), "Без назви");
    EXPECT_EQ(photo.getAuthor(), "Невідомий автор");
    EXPECT_EQ(photo.getWidth(), 1);
    EXPECT_EQ(photo.getHeight(), 1);
    EXPECT_EQ(photo.getDate(), "Невідома дата");
    EXPECT_TRUE(photo.isValid());
}

TEST(PhotoTest, OneArgumentConstructor) {
    Photo photo("Гірський пейзаж");

    EXPECT_EQ(photo.getTitle(), "Гірський пейзаж");
    EXPECT_EQ(photo.getAuthor(), "Невідомий автор");
    EXPECT_TRUE(photo.isValid());
}

TEST(PhotoTest, FullConstructor) {
    Photo photo(
        "Морський світанок",
        "Олена Коваль",
        1920,
        1080,
        "2026-05-12"
    );

    EXPECT_EQ(photo.getTitle(), "Морський світанок");
    EXPECT_EQ(photo.getAuthor(), "Олена Коваль");
    EXPECT_EQ(photo.getWidth(), 1920);
    EXPECT_EQ(photo.getHeight(), 1080);
    EXPECT_EQ(photo.getDate(), "2026-05-12");
    EXPECT_TRUE(photo.isValid());
}

TEST(PhotoTest, EmptyTitleThrowsException) {
    EXPECT_THROW(
        Photo("", "Олена Коваль", 1920, 1080, "2026-05-12"),
        std::invalid_argument
    );
}

TEST(PhotoTest, EmptyAuthorThrowsException) {
    EXPECT_THROW(
        Photo("Пейзаж", "", 1920, 1080, "2026-05-12"),
        std::invalid_argument
    );
}

TEST(PhotoTest, InvalidResolutionThrowsException) {
    EXPECT_THROW(
        Photo("Пейзаж", "Олена Коваль", 0, 1080, "2026-05-12"),
        std::invalid_argument
    );

    EXPECT_THROW(
        Photo("Пейзаж", "Олена Коваль", 1920, -1, "2026-05-12"),
        std::invalid_argument
    );
}

TEST(PhotoTest, EmptyDateThrowsException) {
    EXPECT_THROW(
        Photo("Пейзаж", "Олена Коваль", 1920, 1080, ""),
        std::invalid_argument
    );
}