
#include "RigidBody.hpp"

namespace Cement::Physics {
	Shape RigidBody::getShape() const {
		return shape;
	}

	const Vector2f &RigidBody::getPosition() {
		return position;
	}
}