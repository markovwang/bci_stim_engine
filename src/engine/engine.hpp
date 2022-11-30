/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-29 00:26:10
 * @FilePath: \bishe\src\engine\engine.hpp
 * @Description: 这是软件引擎入口
 */
#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/String.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "util/read_cfg.hpp"

class Stimulation {

  bool running{true};
  sf::RenderWindow window;

public:
  Stimulation(stim_cfg &&_config);
  ~Stimulation() = default;
  stim_cfg config;

  std::uint32_t update_per_sec{};
  std::uint32_t ts_n;
  std::uint32_t ts_s;
  std::uint64_t frame_count{0};

  void start();
  void stop();

  inline sf::RenderWindow &get_window() { return this->window; }
};
