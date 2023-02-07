#include "Application.hpp"
#include "Events/EventDispatcher.hpp"

namespace Cement {

	Application::Application(const std::string &title, unsigned int width, unsigned int height) : sceneManager(SceneManager(&window)) {
		window.create(sf::VideoMode(width, height), title);
		eventDispatcher = EventDispatcher();
	}

	void Application::run() {
		while (window.isOpen()) {
            Cement::sleep(1);
			window.clear();
			sf::Event event;
			while (window.pollEvent(event)) {
				events(event);
			}
			sceneManager.updateCurrentScene();
			window.display();
		}
	}

	void Application::events(sf::Event event) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		eventDispatcher.emit<sf::Event>();
	}

}