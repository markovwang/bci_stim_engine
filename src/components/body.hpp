/*
 * @Date: 2022-10-31 15:08:19
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-01 15:29:52
 * @FilePath: \bishe\src\components\body.hpp
 */
#pragma once
#include "SFML/System/Vector2.hpp"

// 这个类来存放SSVEP的位置信息和大小信息
struct body {
  body(const sf::Vector2f &_position, float _size, float _freq)
      : position{_position}, size{_size}, freq{_freq} {}

  sf::Vector2f position;
  float size;
  float freq;
};