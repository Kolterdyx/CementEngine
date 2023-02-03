//
// Created by kolterdyx on 3/02/23.
//

#ifndef CEMENTENGINE_RIGIDBODY_HPP
#define CEMENTENGINE_RIGIDBODY_HPP

namespace Cement::Physics {

    class RigidBody {

    public:
        virtual bool collide(RigidBody &rigidBody) = 0;

    };

} // Physics

#endif //CEMENTENGINE_RIGIDBODY_HPP
