#ifndef MATH_HPP
#define MATH_HPP

#include <vector>
#include "Vector2f.hpp"

namespace Cement::Math {

	Vector2f averagePoint(const std::vector<Vector2f> &points);

	Vector2f averagePoint(const std::vector<Vector2f> &points, const std::vector<float> &weights);

	float radiansToDegrees(float radians);

	float degreesToRadians(float degrees);



} // Cement

#endif //MATH_HPP
