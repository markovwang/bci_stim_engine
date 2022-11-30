/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-11-02 10:47:37
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-02 20:15:19
 * @FilePath: \bishe\src\components\colorable.hpp
 */
#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Texture.hpp"

// 用来存放刺激的颜色, 需要和纹理区分
struct colorable {
  sf::Color color;
  // sf::Texture
};
