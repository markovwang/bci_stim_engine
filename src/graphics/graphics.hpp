/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-30 22:36:23
 * @FilePath: \bishe\src\graphics\graphics.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "engine/engine.hpp"
#include <string>

class graphic {

  std::string name;

protected:
  sf::RenderWindow *window;
  void handle_window_event(sf::Event &evt);

public:
  graphic(const std::string &name);
  virtual ~graphic();
  Stimulation *stim;
  void set_stim(Stimulation *stim);
  inline const std::string &get_name() { return name; }

  inline virtual void init() {}
  inline virtual void update() {}
  inline virtual void fixed_update(const float dt) {}
  inline virtual void render(const float lerp) {}
};