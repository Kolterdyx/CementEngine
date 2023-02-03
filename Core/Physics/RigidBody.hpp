//
// Created by kolterdyx on 3/02/23.
//

#ifndef CEMENTENGINE_RIGIDBODY_HPP
#define CEMENTENGINE_RIGIDBODY_HPP

#include "Shape.hpp"

namespace Cement::Physics {

    class RigidBody {

	private:
		const Shape shape;

		Vector2f position;

    public:
		explicit RigidBody(Shape shape) : shape(shape) {}

        virtual bool collide(RigidBody &rigidBody) = 0;

		[[nodiscard]] Shape getShape() const;

    };

} // Physics

#endif //CEMENTENGINE_RIGIDBODY_HPP
