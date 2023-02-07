//
// Created by kolterdyx on 7/02/23.
//

#ifndef CEMENTENGINE_TESTOBJECT_HPP
#define CEMENTENGINE_TESTOBJECT_HPP


#include "EntityComponentSystem/Entity.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <utility>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include "Math/Vector2f.hpp"
#include "Components.hpp"

class TestObject : public Cement::Entity {

public:

    void init(Cement::Math::Vector2f position);

    friend Cement::Scene;
};

#endif //CEMENTENGINE_TESTOBJECT_HPP
