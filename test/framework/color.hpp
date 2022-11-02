//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_COLOR_HPP
#define CEMENTENGINE_COLOR_HPP

#include <string>

#define DYE_BLACK(s) ((std::string("\x1B[30m") + (s) + std::string("\x1B[0m")))
#define DYE_RED(s) ((std::string("\x1B[31m") + (s) + std::string("\x1B[0m")))
#define DYE_GREEN(s) ((std::string("\x1B[32m") + (s) + std::string("\x1B[0m")))
#define DYE_YELLOW(s) ((std::string("\x1B[33m") + (s) + std::string("\x1B[0m")))
#define DYE_BLUE(s) ((std::string("\x1B[34m") + (s) + std::string("\x1B[0m")))
#define DYE_MAGENTA(s) ((std::string("\x1B[35m") + (s) + std::string("\x1B[0m")))
#define DYE_CYAN(s) ((std::string("\x1B[36m") + (s) + std::string("\x1B[0m")))
#define DYE_WHITE(s) ((std::string("\x1B[37m") + (s) + std::string("\x1B[0m")))


#endif //CEMENTENGINE_COLOR_HPP
