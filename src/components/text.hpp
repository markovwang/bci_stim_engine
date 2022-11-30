/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-11-28 11:04:10
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-28 13:10:20
 * @FilePath: \bishe\src\components\text.hpp
 */
#pragma once
#include "SFML/System/Vector2.hpp"
#include <cstdint>
#include <string>

struct text {
  std::string text;
  sf::Vector2f position;
  std::uint32_t text_size;
};