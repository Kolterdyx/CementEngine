#ifndef CIRCLERIGIDBODY_HPP
#define CIRCLERIGIDBODY_HPP


#include "Shape.hpp"
#include "RigidBody.hpp"

namespace Cement::Physics {
	class CircleRigidBody : public RigidBody {

	private:
		const float radius;

	public:
		explicit CircleRigidBody(float radius) : RigidBody(Shape::CIRCLE), radius(radius) {}

		bool collide(RigidBody &rigidBody) override;

		[[nodiscard]] float getRadius() const;

	};

}


#endif //CIRCLERIGIDBODY_HPP
