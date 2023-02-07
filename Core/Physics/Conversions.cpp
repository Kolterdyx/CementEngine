#include "Conversions.hpp"

namespace Cement {
	float Conversions::p2m(float pixels) {
		return pixels / PIXELS_PER_METER;
	}

	Vector2f Conversions::b2Vec2ToVec2(const b2Vec2 &vec) {
		return (Vector2f(vec.x, vec.y) * PIXELS_PER_METER);
	}

	b2Vec2 Conversions::vec2ToB2Vec2(const Vector2f &vec) {
		return {p2m(vec.getX()), p2m(vec.getY())};
	}

    sf::Color Conversions::b2ColorTosfColor(const b2Color &color) {
        return sf::Color(color.r * 255., color.g * 255., color.b * 255., color.a * 255.);
    }

    float Conversions::m2p(float meters) {
        return meters * PIXELS_PER_METER;
    }
} // Cement