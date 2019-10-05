#ifndef SRC_GAME_LEVEL_LEVELCHANCE_HPP
#define SRC_GAME_LEVEL_LEVELCHANCE_HPP

#include <Game/Level/ILevelChance.hpp>

namespace src::game::level
{

class LevelChance : public ILevelChance
{
public:
    LevelChance();

    virtual std::unordered_map<LevelState, PercentageChance> getLevelsPercentageChances(
        const LevelState levelState) const override;
};

} // namespace src::game::level

#endif // SRC_GAME_LEVEL_LEVELCHANCES_HPP
