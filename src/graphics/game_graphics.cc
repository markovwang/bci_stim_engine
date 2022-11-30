/*
 * @Date: 2022-10-26 00:41:34
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-01 01:01:34
 * @FilePath: \bishe\src\graphics\game_graphics.cc
 */
#include "SFML/Graphics/Color.hpp"
#include "SFML/Window/Event.hpp"
#include "game_graphics.hpp"
#include "graphics.hpp"
#include "systems/logic_system.hpp"
#include "systems/render_system.hpp"
#include <filesystem>
#include <memory>
#include <string_view>
#include <system_error>

game_graphics::game_graphics() : graphic("STIMULATION") {

  std::string_view font_path = stim->config.font_path;
  if (font.loadFromFile(font_path)) {

  } else {
    throw std::filesystem::filesystem_error{"cannot load font file",
                                            std::error_code{}};
  }
}

game_graphics::~game_graphics() = default;

void game_graphics::init() {
  manager.init(stim);
  { manager.add_system(std::make_unique<logic_system>()); }
  {
    manager.add_render_system(
        std::make_unique<render_system>(&stim->get_window()));
  }
}

void game_graphics::update() {
  sf::Event evt;
  while (window->pollEvent(evt)) {
    handle_window_event(evt);
    // 可以在此处处理kafka消息
  }
}

void game_graphics::fixed_update(const float dt) { manager.on_update(dt); }

void game_graphics::render(const float lerp) {
  window->clear(sf::Color::Black);
  manager.on_render(lerp);
  if (show_text) {
    window->draw(profiling_text);
  }
  window->display();
}