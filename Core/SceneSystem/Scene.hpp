
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
        std::vector<Entity> entities;
        entt::registry entityRegistry;

    public:
        virtual void onCreate() {};

        virtual void onDestroy() {};

        virtual void update() {};

        virtual void load() {};

        [[nodiscard]] UUID getId() const;

        Scene();

        explicit Scene(UUID id);

        template<typename T, typename... Args>
        T addEntity(Args... args);

        void removeEntity(entt::entity entity);

    };
}

#include "Scene.tpp"

#endif //CEMENTENGINE_SCENE_HPP
