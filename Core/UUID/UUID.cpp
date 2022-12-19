
#include "UUID.hpp"

namespace Cement {
    UUID generateUUID() {
        return boost::uuids::random_generator()();
    }

    UUID nilUUID() {
        return boost::uuids::nil_uuid();
    }

    std::string uuidToString(UUID uuid) {
        return boost::uuids::to_string(uuid);
    }
}