/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-25 10:14:58
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-01 22:26:22
 * @FilePath: \bishe\src\systems\base_system.hpp
 * @Description: base system
 */

#pragma once

#include "engine/engine.hpp"
#include <cstdint>
#include <entt/entity/registry.hpp>
#include <entt/signal/dispatcher.hpp>

class base_system {
protected:
  Stimulation *stim;
  entt::registry *registry;
  entt::dispatcher *dispatcher;

public:
  base_system() = default;
  virtual ~base_system() = default;

  void init(Stimulation *_stim, entt::registry &regr, entt::dispatcher &dispt);

  virtual void update(const float dt, const std::uint64_t frame_count);
  
  inline virtual void on_init() { }
};