/*
 * @Date: 2022-11-30 01:05:41
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-30 01:24:28
 * @FilePath: \bishe\src\systems\render_system.cc
 */
#include "SFML/Graphics/RenderWindow.hpp"
#include "render_system.hpp"

render_system::render_system(sf::RenderWindow *_window) : window{_window} {}

void render_system::update(const float alpha, const std::uint64_t frame_cnt) {
  // todo: impl
}