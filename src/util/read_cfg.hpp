/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-25 21:51:11
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-29 21:58:13
 * @FilePath: \bishe\src\util\read_cfg.hpp
 */
#pragma once

#include "toml.hpp"
#include <array>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

struct stim_cfg {

  enum class stim_type : std::uint8_t { ssvep = 0, rsvp, mi };

  std::uint32_t width;
  std::uint32_t height;
  std::uint32_t target_fps;
  std::string cfg_string;
  std::string font_path;
  std::string window_style;
  stim_type type;
  std::uint32_t target_cnts;
  std::vector<double> freqs;
  std::vector<std::array<double, 2>> pos;
  std::vector<double> size;
  std::string hint_color;
};

inline std::ostream &operator<<(std::ostream &os, const stim_cfg &cfg) {
  os << "width:" << cfg.width << '\n'
     << "height: " << cfg.height << '\n'
     << "target fps: " << cfg.target_fps << '\n'
     << "window mode: " << cfg.window_style << '\n'
     << '\n'
     << "font path is " << cfg.font_path << '\n';

  return os;
};

inline stim_cfg config_loader(std::string &&file_path) {
  toml::table tbl;
  if (!file_path.empty()) {
    tbl = toml::parse_file(file_path);
  }
  stim_cfg cfg;
  std::stringstream stream;
  {
    cfg.width = tbl["display"]["width"].as_integer()->value_or(0);
    cfg.height = tbl["display"]["height"].as_integer()->value_or(0);
    cfg.target_fps = tbl["display"]["target_fps"].as_integer()->value_or(0);
    cfg.window_style = tbl["display"]["window_mode"].as_string()->value_or("");
  }
  { cfg.font_path = tbl["path"]["font"].as_string()->value_or(""); }
  {
    if (auto ssvep_table = tbl["stim"]["ssvep"]) {
      std::cout << "ssvep config detected..." << '\n';
      cfg.type = stim_cfg::stim_type::ssvep;
      cfg.target_cnts = ssvep_table["len"].as_integer()->value_or(0);
      cfg.hint_color = ssvep_table["hint_color"].as_string()->value_or("");
      if (cfg.target_cnts == 0) {
        throw std::logic_error{"ssvel stim length is 0"};
      }
      for (auto ind = 0; ind != cfg.target_cnts; ++ind) {
        cfg.freqs.emplace_back(
            ssvep_table["freqs"][ind].as_floating_point()->value_or(0));
      }
      for (auto ind = 0; ind != cfg.target_cnts; ++ind) {
        auto pos_x =
            ssvep_table["pos"][ind][0].as_floating_point()->value_or(0.0);
        auto pos_y =
            ssvep_table["pos"][ind][1].as_floating_point()->value_or(0.0);
        cfg.pos.push_back({pos_x, pos_y});
      }
      for (auto ind = 0; ind != cfg.target_cnts; ++ind) {
        auto rect_size =
            ssvep_table["size"][ind].as_floating_point()->value_or(0.0);
        cfg.size.push_back(rect_size);
      }
    }
  }
  stream << toml::json_formatter{tbl};
  cfg.cfg_string = stream.str();
  return cfg;
} 