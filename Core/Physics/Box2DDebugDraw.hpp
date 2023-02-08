//
// Created by kolterdyx on 7/02/23.
//

#ifndef CEMENTENGINE_BOX2DDEBUGDRAW_HPP
#define CEMENTENGINE_BOX2DDEBUGDRAW_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Conversions.hpp"
#include "Math/Vector2f.hpp"
#include <iostream>

using namespace Cement::Math;
class Box2DDebugDraw : public b2Draw {
private:
    sf::RenderWindow *_window;

public:
    explicit Box2DDebugDraw(sf::RenderWindow *window) : _window(window) {
    }

    Box2DDebugDraw(const Box2DDebugDraw &other) : _window(other._window) {
    };

    Box2DDebugDraw &operator=(const Box2DDebugDraw &other) {
        _window = other._window;
        return *this;
    }

    void DrawPolygon(const b2Vec2 *vertices, int vertexCount, const b2Color &color) override;

    void DrawSolidPolygon(const b2Vec2 *vertices, int vertexCount, const b2Color &color) override;

    void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) override;

    void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) override;

    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;

    void DrawTransform(const b2Transform &xf) override;

};

#endif //CEMENTENGINE_BOX2DDEBUGDRAW_HPP
