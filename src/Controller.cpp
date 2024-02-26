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
    //sf::Music music;
    //if (!music.openFromFile("music.ogg"))
    //    std::cout << "no music"; // error
    //music.play();

    auto window = sf::RenderWindow(sf::VideoMode(800, 800), "mouse cat");
    sf::Clock clock;

    while (!gameRunning)
        dealWithMenu(gameRunning, window);

    if (setLevel())
    {
        bool gameRunning = true; //to track if the game is still running  //its false when it is done either winning or lost

        m_board.readToFile(m_level, m_mouse, m_cat);

        while (window.isOpen())
        {
            // If game ends, display menu
            //gameRunning = false;       // if win or lose
            if (!gameRunning)
                dealWithMenu(gameRunning, window);
            else {
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
}

void Controller::resetGame() {

    // Reset the level to its initial state
    if (setLevel()) {
        m_board.readToFile(m_level, m_mouse, m_cat); // Re-initialize the level entities
    }

    m_mouse.setPosition(m_mouse.getFirstPos());
    for (size_t i = 0; i < m_cat.size(); i++) {
        m_cat.at(i)->SetPosition(m_cat.at(i)->getFirstPos());
    }

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

    if (auto event = sf::Event{}; window.pollEvent(event))  //checks if there are any events (like key presses, mouse moves, etc.) 
    {
        if (event.type == sf::Event::MouseButtonPressed) //checks if the event is a mouse button press event
        {
            if (event.mouseButton.button == sf::Mouse::Left) //checks if the pressed button is the left mouse button
            {
                //the sound 

                int selectedItem = m_menu.getSelectedItem(window.mapPixelToCoords(sf::Mouse::getPosition(window))); //etermines which menu item, if any, was clicked.
                switch (selectedItem) 
                {
                case 0: // Play
                    gameRunning = true;
                    //resetGame(); // Reset the game to start a new game
                    break;

                case 1: // Help /v
                    displayHelp(window);
                    break;

                case 2: // Exit /v
                    window.close();
                    break;
                }
            }
        }
    }

}

void Controller::displayHelp(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text helpText;
    helpText.setFont(font); 
    helpText.setCharacterSize(24);
    helpText.setFillColor(sf::Color::White);
    helpText.setPosition(30, 70); 
    helpText.setString("Help Information:\n\n"
        "- Your goal is to help the mouse navigate through the maze and collect \n all the cheese.\n\n"
        "- Be cautious! Cats are lurking around, trying to catch the mouse. \n If caught, you'll lose a life.\n\n"
        "- You start with three lives. If you lose all your lives, the game ends,\n and you'll need to restart the level.\n\n"
    "- Additionally, if you find a key, you can unlock the door .\n\n"
    "- Use the arrow keys on your keyboard to move the mouse in the \n desired direction.\n\n"
    "- Make use of gifts to enhance your chances of success.\n\n"
    "- Remember, each level presents a new challenge, so stay \n focused and plan your moves wisely.\n\n"
    "- Press any key on the board to return to the main menu.");

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