//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_GLOBALS_HPP
#define CEMENTENGINE_GLOBALS_HPP

#include <cstdio>
#include <cstdint>
#include <bitset>
#include <cassert>
#include <array>
#include <unordered_map>
#include <memory>
#include <set>

#define MAX_ENTITIES 1000000
#define MAX_COMPONENTS 64

#define CEMENT_ASSERT(expr) (static_cast <bool> (expr) ? void (0) : throw std::runtime_error(#expr, __FILE__, __LINE__, __ASSERT_FUNCTION))
CEMENT_ASSERT(1==1 && "");
using Entity = size_t;
using ComponentType = std::uint8_t;
using Signature = std::bitset<MAX_COMPONENTS>;

#endif //CEMENTENGINE_GLOBALS_HPP
