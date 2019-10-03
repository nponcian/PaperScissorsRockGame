#ifndef SRC_CONTROLLERSFACTORY_HPP
#define SRC_CONTROLLERSFACTORY_HPP

#include <memory>

namespace src
{
namespace help
{

class IHelpController;

} // namespace help;

namespace game
{

class IGameController;

} // namespace game

struct ControllersFactory
{
    std::unique_ptr<help::IHelpController> getHelpController() const;

    std::unique_ptr<game::IGameController> getGameController() const;
};

} // namespace src

#endif // SRC_CONTROLLERSFACTORY_HPP
