#pragma once
/*
 * @Date: 2022-11-30 01:03:32
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-30 01:04:42
 * @FilePath: \bishe\src\systems\render_system.hpp
 */
#include "SFML/Graphics/RenderWindow.hpp"
#include "base_system.hpp"
#include <cstdint>
#include <stdint.h>

class render_system : public base_system {

  sf::RenderWindow *window;

public:
  render_system(sf::RenderWindow *win);

  void update(const float alpha, const std::uint64_t frame_cnt) override;
};