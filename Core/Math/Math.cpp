#include <cmath>
#include "Math.hpp"

namespace Cement::Math {

	Vector2f averagePoint(const std::vector<Vector2f> &points) {
		Vector2f average = Vector2f::zero();
		for (const Vector2f &point : points) {
			average += point;
		}
		return average / points.size();
	}

	Vector2f averagePoint(const std::vector<Vector2f> &points, const std::vector<float> &weights) {
		Vector2f average = Vector2f::zero();
		for (int i = 0; i < points.size(); i++) {
			average += points[i] * weights[i];
		}
		return average / points.size();
	}

	float radiansToDegrees(float radians) {
		return radians * 180.0f / M_PI;
	}

	float degreesToRadians(float degrees) {
		return degrees * M_PI / 180.0f;
	}

} // Cement