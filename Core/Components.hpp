//
// Created by kolterdyx on 7/02/23.
//

#ifndef CEMENTENGINE_COMPONENTS_HPP
#define CEMENTENGINE_COMPONENTS_HPP

#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics/Shape.hpp>
#include <Box2D/Dynamics/b2Fixture.h>

namespace Cement {

    struct BodyComponent {
        b2BodyDef bodyDef;
        b2Shape *shape;
        b2FixtureDef fixtureDef;
        b2Body *body;
    };

    struct RenderComponent {
        sf::Shape *shape;
    };

}

#endif //CEMENTENGINE_COMPONENTS_HPP
