//
// Created by kolterdyx on 2/11/22.
//
#include "BaseScene.hpp"

namespace Cement {
    uint32_t BaseScene::getId() const {
        return _id;
    }

    BaseScene::BaseScene(uint32_t id) {
        if (id == 0) {
            throw std::invalid_argument("Scene id cannot be 0");
        }
        this->_id = id;
    }

    BaseScene::BaseScene() {
        _id = 0;
    }
}
