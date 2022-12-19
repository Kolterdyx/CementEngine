
#ifndef CEMENTENGINE_UUID_HPP
#define CEMENTENGINE_UUID_HPP

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace Cement {
    using UUID = boost::uuids::uuid;

    UUID nilUUID();

    UUID generateUUID();

    std::string uuidToString(UUID uuid);
}

namespace std {
    template<>
    struct hash<Cement::UUID> {
        std::size_t operator()(const Cement::UUID &uuid) const {
            return std::hash<std::string>()(boost::uuids::to_string(uuid));
        }
    };
}

#endif //CEMENTENGINE_UUID_HPP
