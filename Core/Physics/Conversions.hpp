#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics/Color.hpp>
#include "Math/Vector2f.hpp"

using namespace Cement::Math;
namespace Cement {

	class Conversions {

	private:
		static constexpr float PIXELS_PER_METER = 32.0f;

	public:

		static b2Vec2 vec2ToB2Vec2(const Vector2f &vec);

		static Vector2f b2Vec2ToVec2(const b2Vec2 &vec);

		static float p2m(float pixels);

		static float m2p(float meters);

        static sf::Color b2ColorTosfColor(const b2Color &color);

	};

} // Cement

#endif //CONVERSIONS_HPP
