#include <stdexcept>
#include "CircleRigidBody.hpp"

namespace Cement::Physics {
	bool CircleRigidBody::collide(RigidBody &rigidBody) {
		float totalRadius;
		switch (rigidBody.getShape()) {
			case Shape::CIRCLE:
				totalRadius = radius + dynamic_cast<CircleRigidBody*>(&rigidBody)->radius;
				return (position - rigidBody.getPosition()).lengthSquared() <  totalRadius * totalRadius;
			case Shape::POLYGON:
				return true;
			case Shape::LINE:
				return true;
			default:
				throw std::runtime_error("Unknown shape");
		}
	}

	float CircleRigidBody::getRadius() const {
		return radius;
	}
}