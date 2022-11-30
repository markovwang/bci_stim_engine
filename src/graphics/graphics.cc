/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-30 23:23:02
 * @FilePath: \bishe\src\graphics\graphics.cc
 */

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "engine/engine.hpp"
#include "graphics.hpp"

graphic::graphic(const std::string &_name) : name{_name} {}

graphic::~graphic() = default;

void graphic::set_stim(Stimulation *stim) {
  this->stim = stim;
  window = &stim->get_window();
}

void graphic::handle_window_event(sf::Event &evt) {
  if (evt.type == sf::Event::Closed or
      evt.type == sf::Event::KeyPressed and
          evt.key.code == sf::Keyboard::Escape) {
    stim->stop();
  } else if (evt.type == sf::Event::Resized) {
    stim->get_window().setView(sf::View(sf::FloatRect(
        {0, 0}, sf::Vector2f{(float)evt.size.width, (float)evt.size.height})));
  }

  // todo: may have other input processing
}