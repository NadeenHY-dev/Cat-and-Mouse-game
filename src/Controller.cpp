#include"Controller.h"



Controller::Controller() 
    : m_mouse(sf::Vector2f(0,0)) ,m_menu(800, 600)/*, m_cat({sf::Vector2f(0,0), sf::Vector2f(0, 0), sf::Vector2f(0, 0)})*/
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
        bool gameRunning = true; //to track if the game is still running  //its false when it is done either winning or lost

        m_board.readToFile(m_level,m_mouse, m_cat);

        while (window.isOpen())
        {
            // If game ends, display menu
            if (!gameRunning)
                dealWithMenu(gameRunning, window);

            //print
            window.clear();
            m_board.printer(window);
            m_mouse.draw(window);
            for (size_t i = 0; i < m_cat.size(); i++) {
                m_cat.at(i)->draw(window);
            }


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
            for (size_t i = 0; i < m_cat.size(); i++) {
                m_cat.at(i)->SetDirection(m_mouse.getMousePosition());
            }
            const auto deltaTime = clock.restart();
            m_mouse.move(deltaTime);    
            for (size_t i = 0; i < m_cat.size(); i++) {
                m_cat.at(i)->move(deltaTime);
            }
            window.display();
        }
    }
}

void Controller::resetGame() {
    // Reset the level to its initial state
    setLevel(); // Assuming this sets up the level
    m_board.readToFile(m_level, m_mouse, m_cat); // Re-initialize the level entities

    // Reset player and enemy positions, if they're not already reset in the above functions
    // For example:
    // m_mouse.setPosition(initialMousePosition);
    // for (auto& cat : m_cat) {
    //     cat->setPosition(initialCatPosition);
    // }

    // Reset any other game state variables, such as scores, timers, etc.
    // score = 0;
    // gameTime = 0;
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

void Controller::dealWithMenu(bool& gameRunning, sf::RenderWindow& window)
{
    window.clear();
    m_menu.draw(window);
    window.display();

    // Handle menu selection

    if (auto event = sf::Event{}; window.pollEvent(event))  //checks if there are any events (like key presses, mouse moves, etc.) 
    {
        if (event.type == sf::Event::MouseButtonPressed) //checks if the event is a mouse button press event
        {
            if (event.mouseButton.button == sf::Mouse::Left) //checks if the pressed button is the left mouse button
            {
                int selectedItem = m_menu.getSelectedItem(window.mapPixelToCoords(sf::Mouse::getPosition(window))); //etermines which menu item, if any, was clicked.
                switch (selectedItem) {
                case 0: // New Game
                    gameRunning = true;
                    resetGame(); // Reset the game to start a new game
                    break;
                case 1: // Help
                    // Show help
                    break;
                case 2: // Exit
                    window.close();
                    break;
                }
            }
        }
    }

}

void Controller::displayHelp(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("arial.png");
    sf::Text helpText;
    helpText.setFont(font); // Assuming 'font' is an sf::Font loaded elsewhere
    helpText.setCharacterSize(24);
    helpText.setFillColor(sf::Color::White);
    helpText.setPosition(50, 50); // Example position
    helpText.setString("Help Information:\n"
        "- Use arrow keys to move\n"
        "- Avoid enemies\n"
        "Press any key to return.");

    window.clear();
    window.draw(helpText);
    window.display();

    // Wait for any key press to return
    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                return; // Return to the main loop or previous state
            }
        }
    }
}