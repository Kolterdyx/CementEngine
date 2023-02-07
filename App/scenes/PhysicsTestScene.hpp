//
// Created by kolterdyx on 7/02/23.
//

#ifndef CEMENTENGINE_PHYSICSTESTSCENE_HPP
#define CEMENTENGINE_PHYSICSTESTSCENE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Scenes/Scene.hpp"


class PhysicsTestScene : public Cement::Scene {
private:

    std::vector<b2Body *> bodies;

public:

    void onCreate() override;

    void onUpdate(float delta) override;

    void onDestroy() override;

};


#endif //CEMENTENGINE_PHYSICSTESTSCENE_HPP
