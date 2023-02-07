#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include "box2d/box2d.h"
#include "../Math/Vector2f.hpp"

using namespace Cement::Math;
namespace Cement {

	class Conversions {

	private:
		static constexpr float PIXELS_PER_METER = 32.0f;

	public:

		static b2Vec2 vec2ToB2Vec2(const Vector2f &vec);

		static Vector2f b2Vec2ToVec2(const b2Vec2 &vec);

		static float pixelsToMeters(float pixels);

	};

} // Cement

#endif //CONVERSIONS_HPP
