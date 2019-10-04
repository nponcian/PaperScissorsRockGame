#ifndef SRC_GAME_GAMETOOLS_HPP
#define SRC_GAME_GAMETOOLS_HPP

#include <memory>
#include <vector>

namespace src::game
{
namespace level
{

class ILevelChance;

} // namespace level

namespace output
{

class IOutputter;

} // namespace output

namespace random
{

class IRandomGenerator;

} // namespace random

namespace symbols
{

class ISymbol;

} // namespace symbols

struct GameTools
{
    std::vector<std::shared_ptr<symbols::ISymbol>> symbols;

    std::vector<std::shared_ptr<output::IOutputter>> outputters;

    std::shared_ptr<output::IOutputter> chosenOutputter;

    std::shared_ptr<level::ILevelChance> levelChance;

    std::shared_ptr<random::IRandomGenerator> randomGenerator;
};

} // namespace src::game

#endif // SRC_GAME_GAMETOOLS_HPP
