#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

#include <string>
#include <valarray>
#include <SFML/System/Vector2.hpp>
#include <Box2D/Common/b2Math.h>
#include "Physics/Conversions.hpp"

namespace Cement::Math {

	class Vector2f {

	public:
		float x;
		float y;

		Vector2f(float x, float y) : x(x), y(y) {}
		Vector2f() : x(0), y(0) {}
		template<typename T>
		explicit Vector2f(const sf::Vector2<T> &other) : x(other.x), y(other.y) {}
		explicit Vector2f(const b2Vec2 &other) : x(Conversions::m2p(other.x)), y(Conversions::m2p(other.y)) {}

		Vector2f operator+(const Vector2f &other) const;
		Vector2f operator-(const Vector2f &other) const;
		Vector2f operator-() const;
		Vector2f operator*(const Vector2f &other) const;
		Vector2f operator*(const float &scalar) const;
		Vector2f operator/(const Vector2f &other) const;
		Vector2f operator/(const float &scalar) const;

		Vector2f &operator+=(const Vector2f &other);
		Vector2f &operator-=(const Vector2f &other);
		Vector2f &operator*=(const Vector2f &other);
		Vector2f &operator*=(const float &scalar);
		Vector2f &operator/=(const Vector2f &other);
		Vector2f &operator/=(const float &scalar);

		bool operator==(const Vector2f &other) const;
		bool operator!=(const Vector2f &other) const;


		[[nodiscard]] float getX() const;
		[[nodiscard]] float getY() const;

		void setX(float x);
		void setY(float y);

		static float dot(const Vector2f &a, const Vector2f &b);
		static float cross(const Vector2f &a, const Vector2f &b);

		[[nodiscard]] float dot(const Vector2f &other) const;
		[[nodiscard]] float cross(const Vector2f &other) const;

		[[nodiscard]] float length() const;
		[[nodiscard]] float lengthSquared() const;
		void normalize();
		/**
		 * Rotates the vector by the given angle in radians. Modifies the vector.
		 * @param angle Angle in radians
		 * @return Rotated vector (modified *this);
		 */
		[[nodiscard]] Vector2f rotate(float angle) const;

		static Vector2f zero();
		static Vector2f one();
		static Vector2f up();
		static Vector2f down();
		static Vector2f left();
		static Vector2f right();

		static Vector2f lerp(const Vector2f &a, const Vector2f &b, float t);
		static Vector2f lerpUnclamped(const Vector2f &a, const Vector2f &b, float t);
		/**
		 * Rotates the vector by the given angle in radians. Does not modify the vector.
		 * @param a Vector to rotate
		 * @param angle Angle in radians
		 * @return Rotated copy of the vector
		 */
		static Vector2f rotated(const Vector2f &a, float angle);

		static Vector2f fromAngle(float angle);

		operator std::string() const;

		operator sf::Vector2f() const;

		operator sf::Vector2i() const;

		operator sf::Vector2u() const;

		operator b2Vec2() const;
	};

} // Math

#endif //VECTOR2F_HPP
