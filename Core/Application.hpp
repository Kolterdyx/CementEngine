#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "Scenes/SceneManager.hpp"
#include "Events/EventDispatcher.hpp"

namespace Cement {
	class Application {

	protected:
		sf::RenderWindow window;

		SceneManager sceneManager;

		EventDispatcher eventDispatcher;

	public:
		Application(const std::string &title, unsigned int width, unsigned int height);

        /**
         * @brief Override this method to add your own code to be executed when the application is created.
         */
        virtual void onCreate() {};

        /**
         * @brief Call this method to run the application.
         */
		void run();

		void events(sf::Event event);
	};
}

#endif //APPLICATION_HPP
