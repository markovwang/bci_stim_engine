#pragma once
#include "SFML/System/Vector2.hpp"

// 这个类来存放SSVEP的位置信息和大小信息
struct body {
  body(const sf::Vector2f &_position, const sf::Vector2f &_size)
      : position{_position}, size{_size} {}

  sf::Vector2f position, size;
};