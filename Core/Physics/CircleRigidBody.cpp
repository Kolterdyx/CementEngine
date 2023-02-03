#include <stdexcept>
#include "CircleRigidBody.hpp"

namespace Cement::Physics {

	bool CircleRigidBody::collide(RigidBody &rigidBody) {
		switch (rigidBody.getShape()) {
			case Shape::CIRCLE:
				return true;
			case Shape::RECTANGLE:
				return true;
			default:
				throw std::runtime_error("Unknown shape");
		}
	}

	float CircleRigidBody::getRadius() const {
		return radius;
	}
}