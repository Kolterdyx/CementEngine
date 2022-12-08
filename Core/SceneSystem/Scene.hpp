
#ifndef CEMENTENGINE_SCENE_HPP
#define CEMENTENGINE_SCENE_HPP

#include <stdexcept>
#include <vector>
#include "../EntityComponentSystem/Entity.hpp"

namespace Cement {
    class Scene {

    private:
        uint32_t _id;
        std::vector<Entity> entities;
        entt::registry entityRegistry;

    public:
        virtual void onCreate() {};

        virtual void onDestroy() {};

        virtual void update() {};

        virtual void load() {};

        [[nodiscard]] uint32_t getId() const;

        Scene();

        explicit Scene(uint32_t id);

        template<typename T, typename... Args>
        T addEntity(Args... args);

        void removeEntity(entt::entity entity);

    };

    template<typename T, typename... Args>
    T Scene::addEntity(Args... args) {
        T entity(entityRegistry);
        entity.init(args...);
        CEMENT_ASSERT(dynamic_cast<Entity *>(&entity) != nullptr,
                      "Class passed is does not inherit from Cement::Entity");
        entities.emplace_back(entity);
        return entity;
    }
}

#endif //CEMENTENGINE_SCENE_HPP
