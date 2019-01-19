#pragma once
#include <cstdint>
#include <tuple>
#include <vector>

using VertedID = std::uint16_t;
using Connection = std::tuple<VertedID, VertedID>;
using Connections = std::vector<Connection>;


