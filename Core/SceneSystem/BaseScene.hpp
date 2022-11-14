
#ifndef CEMENTENGINE_BASESCENE_HPP
#define CEMENTENGINE_BASESCENE_HPP

#include <stdexcept>

namespace Cement {
    class BaseScene {

    private:
        unsigned int _id;

    public:
        virtual void onCreate() {};

        virtual void onDestroy() {};

        virtual void update() {};

        virtual void load() {};

        unsigned int getId() const;

        BaseScene();

        explicit BaseScene(unsigned int id);

    };
}

#endif //CEMENTENGINE_BASESCENE_HPP
