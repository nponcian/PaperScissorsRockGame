#include <Game/Level/LevelChance.hpp>

#include <unordered_map>

namespace src::game::level
{
namespace
{

// Values came from a series of testing to determine the approximate level of randomness here
const PercentageChance SMALL_CHANCE = 20;
const PercentageChance AVERAGE_CHANCE = 30;
const PercentageChance BIG_CHANCE = 40;

} // namespace

LevelChance::LevelChance()
{
}

std::unordered_map<LevelState, PercentageChance> LevelChance::getLevelsPercentageChances(
    const LevelState levelState) const
{
    switch (levelState)
    {
        case LevelState::Easy :
        {
            const static std::unordered_map<LevelState, PercentageChance> EASY_MAP
                {
                    {LevelState::Easy, BIG_CHANCE},
                    {LevelState::Average, SMALL_CHANCE},
                    {LevelState::Hard, SMALL_CHANCE},
                };
            return EASY_MAP;
        }
        case LevelState::Average :
        {
            const static std::unordered_map<LevelState, PercentageChance> AVERAGE_MAP
                {
                    {LevelState::Easy, AVERAGE_CHANCE},
                    {LevelState::Average, AVERAGE_CHANCE},
                    {LevelState::Hard, AVERAGE_CHANCE},
                };
            return AVERAGE_MAP;
        }
        case LevelState::Hard :
        {
            const static std::unordered_map<LevelState, PercentageChance> HARD_MAP
                {
                    {LevelState::Easy, SMALL_CHANCE},
                    {LevelState::Average, SMALL_CHANCE},
                    {LevelState::Hard, BIG_CHANCE},
                };
            return HARD_MAP;
        }
    }
    return {};
}

} // namespace src::game::level
