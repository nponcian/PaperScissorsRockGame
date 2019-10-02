#include <MainController.hpp>

#include <memory>
#include <string>

#include <ControllersFactory.hpp>
#include <Game/GameController.hpp>
#include <Help/HelpController.hpp>
#include <Common/Logger.hpp>

namespace src
{
namespace
{

common::Logger logger("MainController");

} // namespace

MainController::MainController() :
    controllersFactory_(std::make_unique<ControllersFactory>())
{
}

void MainController::handle(const std::string& message) const
{
    if (message == "--help")
    {
        controllersFactory_->getHelpController()->displayHelp();
    }
    else if (message == "--play")
    {
        controllersFactory_->getGameController()->run();
    }
    else
    {
        logger.print("Unsupported message ", message);
        logger.print("Try with --help to display usage, sample command: ./psr_src --help");
    }
}

} // namespace src
