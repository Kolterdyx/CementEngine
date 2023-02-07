
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
#include <utility>
#include <stdexcept>
#include <regex>

namespace Cement {

    class AssertionFail : public std::runtime_error {
    private:
        std::string msg;
    public:
        AssertionFail(std::string expr, std::string text, std::string file, int line, std::string func) : runtime_error(
                "") {
            msg += text;
            msg += std::string("\n    ");
            msg += file + std::string(":") + std::to_string(line) + std::string("\n    ") + func +
                   std::string("\n    ") + expr;
        }

        [[nodiscard]] const char *what() const noexcept override {
            return msg.c_str();
        }
    };

}

#define CEMENT_ASSERT(expr, text) (static_cast <bool> (expr) ? void (0) : throw Cement::AssertionFail(#expr, text, __FILE__, __LINE__, __ASSERT_FUNCTION))

#endif //CEMENTENGINE_GLOBALS_HPP
