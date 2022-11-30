/*
 * @Date: 2022-10-25 10:27:55
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-28 21:19:55
 * @FilePath: \bishe\src\systems\base_system.cc
 */
#include "engine.hpp"
#include "systems/base_system.hpp"

void base_system::init(Stimulation *_stim, entt::registry &regr,
                       entt::dispatcher &dispt) {
  registry = &regr;
  dispatcher = &dispt;
  stim = _stim;
  on_init();
}

void base_system::update(const float dt, const std::uint64_t frame_count) {}