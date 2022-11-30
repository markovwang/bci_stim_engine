/*
 * @Author: markovwang markov_wang@outlook.com
 * @Date: 2022-10-07 11:36:24
 * @LastEditors: markovwang markov_wang@outlook.com
 * @LastEditTime: 2022-12-01 00:57:05
 * @FilePath: \bishe\src\main.cc
 */

#include "kafka/Properties.h"
#include "util/read_cfg.hpp"
#include <atomic>
#include <thread>
#include <vector>
#include "kafka/AdminClient.h"

int main() {
  // auto cfg = config_loader("../config/cfg.toml");
  // std::cout<<cfg<<'\n';
  auto properties = kafka::Properties{};
  properties.put("bootstrap.servers", "server:60000");
  auto client = kafka::clients::AdminClient{properties};
  
}