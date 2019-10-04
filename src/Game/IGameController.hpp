#ifndef SRC_GAME_IGAMECONTROLLER_HPP
#define SRC_GAME_IGAMECONTROLLER_HPP

#include <iostream>

namespace src::game
{

class IGameController
{
public:
    virtual ~IGameController(){}

    // Parameter inputStream makes the module to be ut-testable
    virtual void run(std::istream& inputStream = std::cin) = 0;
};

} // namespace src::game

#endif // SRC_GAME_IGAMECONTROLLER_HPP
