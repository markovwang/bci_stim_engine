/*
 * @Date: 2022-12-01 13:50:21
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-02 02:29:14
 * @FilePath: \bishe\src\events\spawnssvep.hpp
 */
#pragma once

#include "SFML/System/Vector2.hpp"
#include <cstdint>
#include <string_view>

struct spawn_ssvep {

  sf::Vector2f position;
  float size;
  float freq;
  std::string_view text_str;
  std::int32_t id;
  spawn_ssvep() = default;

  spawn_ssvep(const sf::Vector2f &pos, float _size, float _freq,
              std::string_view text, std::int32_t _id)
      : position{pos}, size{_size}, freq{_freq}, text_str{text}, id{_id} {}
};