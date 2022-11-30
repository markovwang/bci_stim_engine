/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-11-29 21:37:07
 * @FilePath: \bishe\src\main.cc
 */

#include "util/read_cfg.hpp"
#include <atomic>
#include <thread>
#include <vector>

int main() {
  auto cfg = config_loader("../config/cfg.toml");
  std::cout<<cfg<<'\n';
}