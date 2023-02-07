
#include "globals.hpp"

namespace Cement {
    void sleep(int ms) {
        struct timespec ts{};
        ts.tv_sec = ms / 1000;
        ts.tv_nsec = ms % 1000 * 1000000;

        while (nanosleep(&ts, &ts) == -1 && errno == EINTR);
    }
}