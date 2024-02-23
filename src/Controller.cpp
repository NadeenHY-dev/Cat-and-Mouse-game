#include"Controller.h"



Controller::Controller() 
    : m_mouse(sf::Vector2f(0,0)), m_cat({sf::Vector2f(0,0), sf::Vector2f(0, 0), sf::Vector2f(0, 0)})
{
}

Controller::~Controller()
{
}

void Controller::Run()
{
    auto window = sf::RenderWindow(sf::VideoMode(800, 800), "mouse cat");
    sf::Clock clock;
    std::ifstream file("Levels.txt");

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Unable to open file Levels.txt" << std::endl;
    }

    std::string level_name;

    // Read the file line by line
    while (std::getline(file, level_name)) {
        // Process the level name here
        std::cout << level_name << std::endl;
        m_board.readToFile(level_name,m_mouse,m_cat);


        while (window.isOpen())
        {
            window.clear();
            m_board.printer(window);
            m_mouse.draw(window);

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