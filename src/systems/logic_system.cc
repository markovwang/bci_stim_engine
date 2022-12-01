/*
 * @Date: 2022-11-30 01:26:10
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-02 02:31:28
 * @FilePath: \bishe\src\systems\logic_system.cc
 */
#include "SFML/Graphics/Color.hpp"
#include "components/body.hpp"
#include "components/colorable.hpp"
#include "components/id.hpp"
#include "events/spawnssvep.hpp"
#include "logic_system.hpp"

logic_system::logic_system() = default;

void logic_system::on_init() {

  // 初始化时注册事件
  dispatcher->sink<spawn_ssvep>().connect<&logic_system::on_spawn_ssvep>(this);
}

void logic_system::update(const float dt, const std::uint64_t frame_count) {
  // 刺激逻辑映在此处实现
}

void logic_system::on_spawn_ssvep(const spawn_ssvep &props) {
  std::cout << "spawn ssvep stimulation\n";
  auto entity = registry->create();
  registry->emplace<body>(entity, props.position, props.size, props.freq);
  registry->emplace<colorable>(entity, sf::Color::White);
  registry->emplace<id>(entity, props.id);
}