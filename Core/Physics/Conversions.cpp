#include "Conversions.hpp"

namespace Cement {
	float Conversions::p2m(float pixels) {
		return pixels / PIXELS_PER_METER;
	}

    sf::Color Conversions::b2ColorTosfColor(const b2Color &color) {
        return sf::Color(color.r * 255., color.g * 255., color.b * 255., color.a * 255.);
    }

    float Conversions::m2p(float meters) {
        return meters * PIXELS_PER_METER;
    }
} // Cement