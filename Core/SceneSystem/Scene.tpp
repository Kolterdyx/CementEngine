
#ifndef CEMENTENGINE_SCENE_TPP
#define CEMENTENGINE_SCENE_TPP

namespace Cement {

    template<typename T, typename... Args>
    T Scene::addEntity(Args... args) {
        T entity(generateUUID());
        entity.init(args...);
        CEMENT_ASSERT((dynamic_cast<Entity *>(&entity) != nullptr), "Class passed is does not inherit publicly from Cement::Entity");
        entities.insert(std::make_pair(entity.getId(), std::make_unique<T>(entity)));
        handles.insert(std::make_pair(entity.getId(), entityRegistry.create()));
        return entity;
    }

    template<typename... T>
    bool Scene::hasAnyComponents(UUID entity) {
        return entityRegistry.any_of<T...>(handles[entity]);
    }

    template<typename... T>
    bool Scene::hasAllComponents(UUID entity) {
        return entityRegistry.all_of<T...>(handles[entity]);
    }

    template<typename T>
    T &Scene::addComponent(UUID entity) {
        return entityRegistry.emplace<T>(handles[entity]);
    }

    template<typename T>
    void Scene::removeComponent(UUID entity) {
        entityRegistry.remove<T>(handles[entity]);
    }

    template<typename T>
    T &Scene::getComponent(UUID entity) {
        return entityRegistry.get<T>(handles[entity]);
    }

    template<typename T>
    bool Scene::hasComponent(UUID entity) {
        return hasAllComponents<T>(entity);
    }

    template<typename... T>
    auto Scene::view(UUID entity) {
        return entityRegistry.view<T...>(handles[entity]);
    }

}

#endif //CEMENTENGINE_SCENE_TPP
