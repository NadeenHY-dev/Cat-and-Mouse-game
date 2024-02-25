#include"Controller.h"



Controller::Controller() 
    : m_mouse(sf::Vector2f(0,0))/*, m_cat({sf::Vector2f(0,0), sf::Vector2f(0, 0), sf::Vector2f(0, 0)}*///)
{
}

Controller::~Controller()
{
}

void Controller::Run()
{
    auto window = sf::RenderWindow(sf::VideoMode(800, 800), "mouse cat");
    sf::Clock clock;


    if(setLevel())
    {
        m_board.readToFile(m_level,m_mouse, m_cat);

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
            for (auto& cat : m_cat) {
                const auto deltaTime = clock.restart();
                cat->move(deltaTime); // Polymorphic call to the appropriate move method
                cat->draw(window);
                window.display();
            }
        }
    }
}

bool Controller::setLevel()
{
    std::ifstream file("Levels.txt");
    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Unable to open file Levels.txt" << std::endl;
    }

    std::string level_name;

    // Read the file line by line
    if (std::getline(file, level_name))
    {
        m_level = level_name;
        return true;
    }
    return false;
}

void Controller::loadCats() {
    // Example positions for illustration
    std::vector<sf::Vector2f> positions = { sf::Vector2f(100, 100), sf::Vector2f(200, 200) };
    bool isSmart = false;

    for (auto& pos : positions) {
        if (isSmart) {
            m_cat.emplace_back(std::make_unique<SmartCat>(pos));
        }
        else {
            m_cat.emplace_back(std::make_unique<NormalCat>(pos));
        }
        isSmart = !isSmart; // Toggle between normal and smart
    }
}