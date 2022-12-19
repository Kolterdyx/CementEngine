
#ifndef CEMENTENGINE_SCENE_HPP
#define CEMENTENGINE_SCENE_HPP

#include <stdexcept>
#include <vector>
#include "../EntityComponentSystem/Entity.hpp"
#include "../UUID/UUID.hpp"

namespace Cement {


    class Scene {

    private:
        UUID _id;
        std::unordered_map<UUID, std::unique_ptr<Entity>> entities;
        std::unordered_map<UUID, entt::entity> handles;
        entt::registry entityRegistry;

    public:
        virtual void onCreate() {};

        virtual void onDestroy() {};

        virtual void update() {};

        virtual void load() {};

        [[nodiscard]] UUID getId() const;

        Scene();

        template<typename T, typename... Args>
        T addEntity(Args... args);

        void removeEntity(UUID entity);

        // API for entt::registry

        template<typename... T>
        bool hasAnyComponents(UUID entity);

        template<typename... T>
        bool hasAllComponents(UUID entity);

        template<typename T>
        T &addComponent(UUID entity);

        template<typename T>
        void removeComponent(UUID entity);

        template<typename T>
        T &getComponent(UUID entity);

        template<typename T>
        bool hasComponent(UUID entity);

        template<typename... T>
        auto view(UUID entity);
    };
}

#include "Scene.tpp"

#endif //CEMENTENGINE_SCENE_HPP
