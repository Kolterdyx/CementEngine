//
// Created by kolterdyx on 3/02/23.
//

#ifndef CEMENTENGINE_RIGIDBODY_HPP
#define CEMENTENGINE_RIGIDBODY_HPP

#include "Shape.hpp"
#include "Vector2f.hpp"

using namespace Cement::Math;

namespace Cement::Physics {

    class RigidBody {

	private:
		const Shape shape;

	protected:
		Vector2f position;
	public:
		explicit RigidBody(Shape shape) : shape(shape), position(Vector2f::zero()) {}

        virtual bool collide(RigidBody &rigidBody) = 0;

		[[nodiscard]] Shape getShape() const;

		const Vector2f &getPosition();
	};

} // Physics

#endif //CEMENTENGINE_RIGIDBODY_HPP
