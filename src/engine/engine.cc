/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-29 19:40:17
 * @FilePath: \bishe\src\engine\engine.cc
 */
#include "engine.hpp"
#include "graphics/game_graphics.hpp"
#include "graphics/graphics.hpp"
#include <__msvc_chrono.hpp>
#include <chrono>
#include <memory>

Stimulation::Stimulation(stim_cfg &&_config) : config{_config} {
  update_per_sec = config.target_fps;
  ts_n = 1000000000 / update_per_sec;
  ts_s = 1.f / update_per_sec;

  sf::VideoMode v_mode{{config.width, config.height}};
  window.create(v_mode, sf::String{"haha"}, sf::Style::None);
  window.setVerticalSyncEnabled(true);
}

void Stimulation::start() {
  std::unique_ptr<graphic> scene{std::make_unique<game_graphics>()};
  using clock = std::chrono::high_resolution_clock;
  std::chrono::nanoseconds timestep{ts_n};
  std::chrono::nanoseconds acc{0};
  auto time_start = clock::now();

  while (running) {
    auto delta_time = clock::now() - time_start;
    time_start = clock::now();
    acc += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
    scene->update();
    while (acc >= timestep) {
      acc -= timestep;
      scene->fixed_update(ts_s);
    }
    const auto alpha = (float)acc.count() / timestep.count();
    scene->render(alpha);
    ++frame_count;
  }
}

void Stimulation::stop() { running = false; }