/*
 * @Date: 2022-11-30 01:25:56
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-01 22:18:11
 * @FilePath: \bishe\src\systems\logic_system.hpp
 */
#pragma once
#include "base_system.hpp"
#include "events/spawnssvep.hpp"
#include <cstdint>

class logic_system : public base_system {

  void on_init() override;

  public:

  logic_system();

  void update(const float dt,const std::uint64_t frame_cnt) override;

  // todo: add some logics

  void on_spawn_ssvep(const spawn_ssvep& props);

};