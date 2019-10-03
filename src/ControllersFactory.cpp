#include <ControllersFactory.hpp>

#include <memory>

#include <Game/GameController.hpp>
#include <Game/GameTools.hpp>
#include <Game/Level/LevelChance.hpp>
#include <Game/Output/OutputtersGetter.hpp>
#include <Game/Random/RandomGenerator.hpp>
#include <Game/Symbols/SymbolsGetter.hpp>
#include <Help/HelpController.hpp>

namespace src
{

std::unique_ptr<help::IHelpController> ControllersFactory::getHelpController() const
{
    return std::make_unique<help::HelpController>();
}

std::unique_ptr<game::IGameController> ControllersFactory::getGameController() const
{
    auto tools = std::make_shared<game::GameTools>();

    tools->symbols = game::symbols::getAllSymbols();
    tools->outputters = game::output::getAllLanguageOutputters();
    tools->chosenOutputter = tools->outputters.front();
    tools->levelChance = std::make_shared<game::level::LevelChance>();
    tools->randomGenerator = std::make_shared<game::random::RandomGenerator>(tools->symbols, tools->levelChance);

    return std::make_unique<game::GameController>(tools);
}

} // namespace src
