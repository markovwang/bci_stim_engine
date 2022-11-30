/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-26 00:41:25
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-29 20:08:39
 * @FilePath: \bishe\src\graphics\game_graphics.hpp
 */
#pragma once

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "engine/entity_manager.hpp"
#include "graphics.hpp"
#include <vector>

class game_graphics : public graphic {

  entity_manager manager;

  sf::Font font;
  sf::Text profiling_text;
  bool show_text;
public:
  game_graphics();
  ~game_graphics();

  inline virtual void init() override;
  inline virtual void update() override;
  inline virtual void fixed_update(const float dt) override;
  inline virtual void render(const float lerp) override;
};