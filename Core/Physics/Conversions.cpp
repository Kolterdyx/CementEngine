#include "Conversions.hpp"

namespace Cement {
	float Conversions::pixelsToMeters(float pixels) {
		return pixels / PIXELS_PER_METER;
	}

	Vector2f Conversions::b2Vec2ToVec2(const b2Vec2 &vec) {
		return {vec.x, vec.y};
	}

	b2Vec2 Conversions::vec2ToB2Vec2(const Vector2f &vec) {
		return {vec.getX(), vec.getY()};
	}
} // Cement