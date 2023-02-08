#include "Vector2f.hpp"

namespace Cement::Math {
	Vector2f Vector2f::operator+(const Vector2f &other) const {
		return {x + other.x, y + other.y};
	}

	Vector2f Vector2f::operator-(const Vector2f &other) const {
		return {x - other.x, y - other.y};
	}

	Vector2f Vector2f::operator*(const Vector2f &other) const {
		return {x * other.x, y * other.y};
	}

	Vector2f Vector2f::operator*(const float &scalar) const {
		return {x * scalar, y * scalar};
	}

	Vector2f Vector2f::operator/(const Vector2f &other) const {
		return {x / other.x, y / other.y};
	}

	Vector2f Vector2f::operator/(const float &scalar) const {
		return {x / scalar, y / scalar};
	}

	Vector2f &Vector2f::operator+=(const Vector2f &other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2f &Vector2f::operator-=(const Vector2f &other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2f &Vector2f::operator*=(const Vector2f &other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2f &Vector2f::operator*=(const float &scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2f &Vector2f::operator/=(const Vector2f &other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2f &Vector2f::operator/=(const float &scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	bool Vector2f::operator==(const Vector2f &other) const {
		return x == other.x && y == other.y;
	}

	bool Vector2f::operator!=(const Vector2f &other) const {
		return x != other.x || y != other.y;
	}

	float Vector2f::getX() const {
		return x;
	}

	float Vector2f::getY() const {
		return y;
	}

	void Vector2f::setX(float x) {
		this->x = x;
	}

	void Vector2f::setY(float y) {
		this->y = y;
	}

	float Vector2f::dot(const Vector2f &a, const Vector2f &b) {
		return a.x * b.x + a.y * b.y;
	}

	float Vector2f::cross(const Vector2f &a, const Vector2f &b) {
		return a.x * b.y - a.y * b.x;
	}

	float Vector2f::length() const {
		return sqrt(lengthSquared());
	}

	float Vector2f::lengthSquared() const {
		return dot(*this, *this);
	}

	void Vector2f::normalize() {
		float length = this->length();
		x /= length;
		y /= length;
	}

	Vector2f Vector2f::rotate(float angle) const {
		float cos = std::cos(angle);
		float sin = std::sin(angle);
		return {x * cos - y * sin, x * sin + y * cos};
	}

	Vector2f Vector2f::zero() {
		return {0, 0};
	}

	Vector2f Vector2f::one() {
		return {1, 1};
	}

	Vector2f Vector2f::up() {
		return {0, 1};
	}

	Vector2f Vector2f::down() {
		return {0, -1};
	}

	Vector2f Vector2f::left() {
		return {-1, 0};
	}

	Vector2f Vector2f::right() {
		return {1, 0};
	}

	Vector2f Vector2f::fromAngle(float angle) {
		return {std::cos(angle), std::sin(angle)};
	}

	Vector2f Vector2f::lerp(const Vector2f &a, const Vector2f &b, float t) {
		return a + (b - a) * std::clamp(t, 0.0f, 1.0f);
	}

	Vector2f Vector2f::lerpUnclamped(const Vector2f &a, const Vector2f &b, float t) {
		return a + (b - a) * t;
	}

	Vector2f Vector2f::rotated(const Vector2f &a, float angle) {
		return Vector2f(a).rotate(angle);
	}

	float Vector2f::dot(const Vector2f &other) const {
		return dot(*this, other);
	}

	float Vector2f::cross(const Vector2f &other) const {
		return cross(*this, other);
	}

	Vector2f Vector2f::operator-() const {
		return {-x, -y};
	}

	Vector2f::operator std::string() const {
		return std::string("Vector2f(") + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	Vector2f::operator sf::Vector2f() const {
		return {x, y};
	}

	Vector2f::operator sf::Vector2i() const {
		return {static_cast<int>(x), static_cast<int>(y)};
	}

	Vector2f::operator sf::Vector2u() const {
		return {static_cast<unsigned int>(x), static_cast<unsigned int>(y)};
	}

	Vector2f::operator b2Vec2() const {
		return {Conversions::p2m(x), Conversions::p2m(y)};
	}


} // Math