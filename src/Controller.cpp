#include"Controller.h"


Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Run()
{
	auto window = sf::RenderWindow(sf::VideoMode(800,800),"mouse cat");
    sf::Clock clock;
    size_t i = 1;
    while (i < LEVELS) {
        m_board.readToFile(i); // pushback chars ;

        while (window.isOpen())
        {
            window.clear();
            window.display();

            for (auto event = sf::Event{}; window.pollEvent(event); )
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed: // m_player.setDirection(event.key.code);
                    break;
                }
            }
        }
    }
}
