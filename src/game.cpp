#include "headers/game.h"

Game::Game(std::string mapFile, std::map<std::string, sf::Texture*> textures) : 
    map_(fileToArray(mapFile), textures["map"], TILE_SIZE),
    player_(textures["player"], sf::Vector2u(6,4), 0.1f, PLAYER_SPEED, TILE_SIZE, map2Screen(map_.startPos))
{
    this->level = 0;
    this->playerLives = 3;
    this->score = 0;
}

const sf::Vector2f Game::agentPos(Agent agent)
{
    sf::Vector2f agentPosition;
    switch (agent)
    {
    case Agent::PACMAN:
        agentPosition = this->player_.playerPos();
        break;
    
    default:
        break;
    }
    return agentPosition;
}

const Cell Game::mapCellType(Coord coord)
{
    Cell type = this->map_.cellType(coord);
    return type;
}

void Game::moveAgent(Agent agent, float deltaTime, Direction dir)
{
    const sf::Vector2f agentPosition = this->agentPos(agent);
    Coord mapPosition = screen2Map(agentPosition); 
    
    if (agent == Agent::PACMAN){
        if (this->canMove_(Agent::PACMAN, dir)){
            this->player_.update(deltaTime, dir);
        }
    };
}

bool Game::canMove_(Agent agent, Direction dir)
{
    sf::Vector2f agentPos = this->agentPos(agent);
    Coord mapPosition = screen2Map(agentPos);
    Coord dest;
    switch (dir)
    {
    case Direction::UP:
        dest.first = mapPosition.first - 1;
        dest.second = mapPosition.second;
        break;
    case Direction::DOWN:
        dest.first = mapPosition.first + 1;
        dest.second = mapPosition.second;
        break;
    case Direction::LEFT:
        dest.second = mapPosition.second - 1;
        dest.first = mapPosition.first;
        break;
    case Direction::RIGHT:
        dest.second = mapPosition.second + 1;
        dest.first = mapPosition.first;
        break;
    default:
        break;
    } 
    bool canMove = this->map_.cellType(dest) != Cell::WALL;
    return canMove;
}

void Game::resizeView(const sf::RenderWindow& window, sf::View& view){
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void Game::mainLoop(sf::RenderWindow& window, sf::View& view){
	float deltaTime = 0.0f;
	sf::Clock clock;
    Direction movement = RIGHT;
    while (window.isOpen())
    {
		deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				this->resizeView(window, view);
				break;
			}
            if (evnt.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                movement = Direction::LEFT;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                movement = Direction::RIGHT;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
                movement = Direction::UP;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                movement = Direction::DOWN;
            }
        }
        this->moveAgent(PACMAN, deltaTime, movement);
        window.clear();
		window.setView(view);
		this->map_.draw(window);
        this->player_.draw(window);
        window.display();
    }


}





#if TESTS
void Game::setAgentPos(Agent agent, sf::Vector2f position)
{
    if (agent == Agent::PACMAN){
        this->player_.setPlayerPos(position);
    }
}
#endif /*TESTS*/