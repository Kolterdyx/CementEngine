#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "Scenes/SceneManager.hpp"
#include "Events/EventDispatcher.hpp"

namespace Cement {
	class Application {

	private:
		sf::RenderWindow window;

		SceneManager sceneManager;

		EventDispatcher eventDispatcher;

	public:
		Application(const std::string &title, unsigned int width, unsigned int height);

		void run();

		void events(sf::Event event);
	};
}

#endif //APPLICATION_HPP
