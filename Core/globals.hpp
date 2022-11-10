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

#define MAX_ENTITIES 1000000
#define MAX_COMPONENTS 64

using Entity = size_t;
using Signature = std::bitset<MAX_COMPONENTS>;

#endif //CEMENTENGINE_GLOBALS_HPP
