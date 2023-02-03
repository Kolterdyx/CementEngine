#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

namespace Cement::Math {

	class Vector2f {

	private:
		float x;
		float y;

	public:
		Vector2f(float x, float y) : x(x), y(y) {}

		Vector2f operator+(const Vector2f &other) const;
		Vector2f operator-(const Vector2f &other) const;
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
	};

} // Math

#endif //VECTOR2F_HPP
