#include "Application.hpp"
#include "Events/EventDispatcher.hpp"

namespace Cement {

	Application::Application(const std::string &title, unsigned int width, unsigned int height) {
		window.create(sf::VideoMode(width, height), title);
		sceneManager = SceneManager();
		eventDispatcher = EventDispatcher();
	}

	void Application::run() {
		while (window.isOpen()) {
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