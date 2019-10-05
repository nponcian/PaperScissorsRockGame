#ifndef SRC_GAME_LEVEL_ILEVELCHANCE_HPP
#define SRC_GAME_LEVEL_ILEVELCHANCE_HPP

#include <unordered_map>
#include <vector>

namespace src::game
{
namespace symbols
{

class ISymbol;

} // namespace symbols;

namespace level
{

using PercentageChance = int;

enum class LevelState
{
    Easy,
    Average,
    Hard,
};

static const std::vector<std::pair<LevelState, std::string>> LEVELS_AND_NAME_VEC
    {
        {LevelState::Easy,    "Easy"},
        {LevelState::Average, "Average"},
        {LevelState::Hard,    "Hard"},
    };

class ILevelChance
{
public:
    virtual ~ILevelChance(){}

    virtual std::unordered_map<LevelState, PercentageChance> getLevelsPercentageChances(
        const LevelState levelState) const = 0;
};

} // namespace level
} // namespace src::game

#endif // SRC_GAME_LEVEL_ILEVELCHANCE_HPP
