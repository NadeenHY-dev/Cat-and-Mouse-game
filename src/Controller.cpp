#include"Controller.h"


Controller::Controller() 
    : m_mouse(sf::Vector2f(0,0)), m_cat(sf::Vector2f(0,0))
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
            m_board.printer(window);

            for (auto event = sf::Event{}; window.pollEvent(event); )
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed: 
                    m_mouse.setDirection(event.key.code);
                    break;
                }
            }
            const auto deltaTime = clock.restart();
            m_mouse.move(deltaTime);
            window.display();
        }
    }
}



