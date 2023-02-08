#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics/Color.hpp>

namespace Cement {

	class Conversions {

	private:
		static constexpr float PIXELS_PER_METER = 32.0f;

	public:

		static float p2m(float pixels);

		static float m2p(float meters);

        static sf::Color b2ColorTosfColor(const b2Color &color);

	};

} // Cement

#endif //CONVERSIONS_HPP
