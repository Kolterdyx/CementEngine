//
// Created by kolterdyx on 7/02/23.
//


#include "Box2DDebugDraw.hpp"

void Box2DDebugDraw::DrawTransform(const b2Transform &xf) {
    b2Vec2 p1 = xf.p, p2;
    const float32 k_axisScale = 0.4f;
    p2 = p1 + k_axisScale * xf.q.GetXAxis();
    DrawSegment(p1, p2, b2Color(1, 0, 0));
    p2 = p1 + k_axisScale * xf.q.GetYAxis();
    DrawSegment(p1, p2, b2Color(0, 1, 0));

}

void Box2DDebugDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {
    Vector2f size = Cement::Conversions::b2Vec2ToVec2(p2 - p1);
    sf::RectangleShape line(sf::Vector2f(size.length(), 2));
    float angle = atan2(size.getY(), size.getX());
    line.setRotation(angle * 180 / M_PI);
    Vector2f pos = Cement::Conversions::b2Vec2ToVec2(p1);
    line.setPosition(pos.getX(), pos.getY());
    line.setFillColor(Cement::Conversions::b2ColorTosfColor(color));
    line.setOutlineThickness(0);


    _window->draw(line);
}

void Box2DDebugDraw::DrawPolygon(const b2Vec2 *vertices, int vertexCount, const b2Color &color) {

    for (int i = 0; i < vertexCount; i++) {
        DrawSegment(vertices[i], vertices[(i + 1) % vertexCount], color);
    }
}

void Box2DDebugDraw::DrawSolidPolygon(const b2Vec2 *vertices, int vertexCount, const b2Color &color) {
    sf::ConvexShape convex;
    convex.setPointCount(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        Vector2f pos = Cement::Conversions::b2Vec2ToVec2(vertices[i]);
        convex.setPoint(i, sf::Vector2f(pos.getX(), pos.getY()));
    }
    convex.setFillColor(Cement::Conversions::b2ColorTosfColor(color));
    convex.setOutlineThickness(0);

    _window->draw(convex);
}

void Box2DDebugDraw::DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) {

    sf::CircleShape circle(Cement::Conversions::m2p(radius));
    Vector2f pos = Cement::Conversions::b2Vec2ToVec2(center);
    circle.setPosition(pos.getX(), pos.getY());
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(Cement::Conversions::b2ColorTosfColor(color));
    circle.setOutlineThickness(1);
    _window->draw(circle);
}


void Box2DDebugDraw::DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) {
    sf::CircleShape circle(Cement::Conversions::m2p(radius));
    Vector2f pos = Cement::Conversions::b2Vec2ToVec2(center);
    sf::Color c = Cement::Conversions::b2ColorTosfColor(color);
    circle.setPosition(pos.getX(), pos.getY());
    circle.setFillColor(c);
    circle.setOutlineThickness(0);

    _window->draw(circle);
}
