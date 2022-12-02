/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-02 22:26:18
 * @FilePath: \bishe\src\main.cc
 */

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/String.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "kafka/AdminClient.h"
#include "kafka/Properties.h"
#include "util/read_cfg.hpp"
#include <atomic>
#include <thread>
#include <vector>

int main() {
  using namespace std::chrono_literals;
  // auto cfg = config_loader("../config/cfg.toml");
  // std::cout<<cfg<<'\n';
  std::array<sf::Texture, 300> textures;
  for (uint64_t ind = 1; ind <= 300; ++ind) {
    std::string file = std::to_string(ind - 1) + ".png";
    std::cout << "loading file..." << ind << '\n';
    auto res = textures[ind - 1].loadFromFile("../config/pics/" + file);
    if (res != 1)
      std::cerr << "wrong\n";
  }
  uint64_t count{0};
  sf::Sprite sprite;
  sf::RenderWindow window;
  window.create(sf::VideoMode{sf::Vector2u{1920, 1080}}, sf::String{"text"},
                sf::Style::Fullscreen);
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  window.setMouseCursorVisible(false);
  sf::Event event;
  using clock = std::chrono::high_resolution_clock;
  auto start_time = clock::now();
  while (window.isOpen()) {
    if (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed or
          event.type == sf::Event::KeyPressed and
              event.key.code == sf::Keyboard::Escape)
        window.close();
    }
    auto delta_time = clock::now() - start_time;
    if (delta_time.count() != 0)
      std::cout << "frame time: " << (unsigned int)(1e9 / (delta_time / 1ns))
                << '\n';
    start_time = clock::now();
    window.clear(sf::Color{83, 83, 83});
    sprite.setTexture(textures[count++ % 300]);
    window.draw(sprite);
    window.display();
  }
}