/*
 * @Date: 2022-10-26 01:01:55
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-30 01:01:49
 * @FilePath: \bishe\src\engine\entity_manager.cc
 */
#include "engine.hpp"
#include "entity_manager.hpp"
#include <algorithm>
#include <utility>

entity_manager::entity_manager() = default;

entity_manager::~entity_manager() = default;

void entity_manager::init(Stimulation *_stim) { this->stim = _stim; }

void entity_manager::add_system(std::unique_ptr<base_system> system) {
  system->init(stim, registry, dispatcher);
  systems.emplace_back(std::move(system));
}

void entity_manager::add_render_system(std::unique_ptr<base_system> system) {
  system->init(stim, registry, dispatcher);
  render_systems.emplace_back(std::move(system));
}

void entity_manager::on_update(float dt) {
  for (auto &sys : systems) {
    sys->update(dt, stim->frame_count);
  }
}

void entity_manager::on_render(float lerp) {
  for (auto &s : render_systems) {
    s->update(lerp, stim->frame_count);
  }
}