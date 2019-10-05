#include <Game/Random/RandomGenerator.hpp>

#include <functional>
#include <memory>
#include <random>
#include <vector>

#include <Game/Level/ILevelChance.hpp>
#include <Game/Level/Opponents.hpp>
#include <Game/Symbols/ISymbol.hpp>

namespace src::game::random
{
namespace
{

unsigned generateRandomPositiveNumber(const int limit)
{
    const int INCLUDE_LIMIT = 1;

    std::random_device dev;
    return dev() % (limit + INCLUDE_LIMIT);
}

} // namespace

RandomGenerator::RandomGenerator(
    const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols,
    const std::shared_ptr<level::ILevelChance> levelChance) :
        symbols_(symbols),
        levelChance_(levelChance)
{
}

bool RandomGenerator::randomDecision(const int chance) const
{
    const int MIN_PERCENTAGE = 0;
    const int MAX_PERCENTAGE = 100;

    if (chance <= MIN_PERCENTAGE) return false;
    if (chance >= MAX_PERCENTAGE) return true;

    int indicator = generateRandomPositiveNumber(MAX_PERCENTAGE);
    return indicator <= chance;
}

int RandomGenerator::randomNumber(const int limit) const
{
    int generated = generateRandomPositiveNumber(limit);
    return generated;
}

symbols::SymbolState RandomGenerator::generateComputerSymbolState(
    const symbols::SymbolState userSymbolState,
    const level::LevelState levelState) const
{
    auto it = std::find_if(symbols_.begin(), symbols_.end(),
                            [&userSymbolState](const auto symbol)
                            {
                                return symbol->getSymbolState() == userSymbolState;
                            });
    if (it == symbols_.end()) return userSymbolState;

    auto opponentGroups = level::classifyOpponents(*it, symbols_);
    if (level::isOpponentGroupsEmpty(opponentGroups)) return userSymbolState;

    // To prevent rechecking for every loop below (assuming compiler doesn't optimize it)
    bool isEasyOpponentsEmpty = opponentGroups.easy.empty();
    bool isAverageOpponentsEmpty = opponentGroups.average.empty();
    bool isHardOpponentsempty = opponentGroups.hard.empty();

    int maxRandomizeRuns = 1000;
    auto chancesMap = levelChance_->getLevelsPercentageChances(levelState);

    // 1. Opponents are grouped based on their difficulty level
    // 2. Each group has a specific chance to face the user (see LevelChance.cpp)
    // 3. It will be randomized to select the group to choose from
    // 4. Once a group has been chosen, it will be again randomized within the group (equal chances)
    //    to who specifically in the group will face the user
    // This makes sense if more and more symbols ("opponentGroups") are added to the application
    while (--maxRandomizeRuns >= 0)
    {
        if (!isAverageOpponentsEmpty && randomDecision(chancesMap[level::LevelState::Average]))
        {
            int computerchoice = randomNumber(opponentGroups.average.size() - 1);
            return opponentGroups.average[computerchoice].get()->getSymbolState();
        }
        if (!isEasyOpponentsEmpty && randomDecision(chancesMap[level::LevelState::Easy]))
        {
            int computerchoice = randomNumber(opponentGroups.easy.size() - 1);
            return opponentGroups.easy[computerchoice].get()->getSymbolState();
        }
        if (!isHardOpponentsempty && randomDecision(chancesMap[level::LevelState::Hard]))
        {
            int computerchoice = randomNumber(opponentGroups.hard.size() - 1);
            return opponentGroups.hard[computerchoice].get()->getSymbolState();
        }
    }
    return userSymbolState;
}

} // namespace src::game::random
