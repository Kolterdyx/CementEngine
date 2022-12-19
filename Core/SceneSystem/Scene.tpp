//
// Created by kolterdyx on 19/12/22.
//

#ifndef CEMENTENGINE_SCENE_TPP
#define CEMENTENGINE_SCENE_TPP

namespace Cement {

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

#endif //CEMENTENGINE_SCENE_TPP
