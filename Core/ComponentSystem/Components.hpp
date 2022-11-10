//
// Created by kolterdyx on 9/11/22.
//

enum class Components {
    TRANSFORM,
    DYNAMIC,
    TEXTURE,
    SHAPE
};

struct TransformComponent {
    double x;
    double y;
};

struct DynamicComponent {
    double vel_x;
    double vel_y;

    double acc_x;
    double acc_y;
};
