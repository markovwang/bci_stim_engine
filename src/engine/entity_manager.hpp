/*
 * @Date: 2022-10-26 01:01:46
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-28 14:08:12
 * @FilePath: \bishe\src\engine\entity_manager.hpp
 */
#pragma once

#include "engine.hpp"
#include "systems/base_system.hpp"
#include <memory>
#include <vector>

class entity_manager {

  Stimulation *stim;
  entt::registry registry;
  entt::dispatcher dispatcher;

  std::vector<std::unique_ptr<base_system>> systems;
  std::vector<std::unique_ptr<base_system>> render_systems;

public:
  entity_manager();
  ~entity_manager();

  void init(Stimulation *stim);
  void on_update(float dt);
  void on_render(float lerp);

  void add_system(std::unique_ptr<base_system>);
  void add_render_system(std::unique_ptr<base_system>);

  inline auto &get_register() { return registry; }
  inline auto &get_dispatcher() { return dispatcher; }
};
