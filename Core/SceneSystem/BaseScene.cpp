//
// Created by kolterdyx on 2/11/22.
//
#include "BaseScene.hpp"

unsigned int BaseScene::getId() const {
    return _id;
}

BaseScene::BaseScene(unsigned int id) {
    if (id == 0) {
        throw std::invalid_argument("Scene id cannot be 0");
    }
    this->_id = id;
}

BaseScene::BaseScene() {
    _id = 0;
}

