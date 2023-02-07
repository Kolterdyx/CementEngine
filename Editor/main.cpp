#include "../Core/Application.hpp"

using namespace Cement;

class TestScene : public Scene {
public:
    int n;

    TestScene(unsigned int i) : Scene() {
        n = 0;
    }

    void onCreate() override {
    }

    void onDestroy() override {
    }

    void update() override {
        n++;
    }
};

int main() {

	Application app("Test", 800, 600);


    return 0;
}
