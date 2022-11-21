
#ifndef CEMENTENGINE_BASESCENE_HPP
#define CEMENTENGINE_BASESCENE_HPP

#include <stdexcept>
#include <vector>
#include "../EntityComponentSystem/Entity.hpp"

namespace Cement {
    class BaseScene {

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

        BaseScene();

        explicit BaseScene(uint32_t id);

        template<typename T, typename... Args>
        T addEntity(Args... args);

    };

    template<typename T, typename... Args>
    T BaseScene::addEntity(Args... args) {
        T entity = T(std::make_shared<entt::registry>(entityRegistry), args...);
        CEMENT_ASSERT(dynamic_cast<Entity *>(&entity) != nullptr, "Class passed is does not inherit from Cement::Entity");
        entities.push_back(entity);
        return entity;
    }
}

#endif //CEMENTENGINE_BASESCENE_HPP
