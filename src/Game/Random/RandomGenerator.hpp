#ifndef SRC_GAME_RANDOM_RANDOMGENERATOR_HPP
#define SRC_GAME_RANDOM_RANDOMGENERATOR_HPP

#include <memory>
#include <vector>

#include <Game/Random/IRandomGenerator.hpp>

namespace src::game
{
namespace level
{

struct OpponentGroups;
class ILevelChance;

} // namespace level

namespace random
{

class RandomGenerator : public IRandomGenerator
{
public:
    RandomGenerator(
        const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols,
        const std::shared_ptr<level::ILevelChance> levelChance);

    virtual bool randomDecision(const int chance = 50) const override;

    virtual int randomNumber(const int limit) const override;

    virtual symbols::SymbolState generateComputerSymbolState(
        const symbols::SymbolState userSymbolState,
        const level::LevelState levelState) const override;

private:
    // We are tied to GameTools instance of symbols! Changes there will reflect here. GameTools are
    // assured to be present within the game's lifetime.
    const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols_;

    const std::shared_ptr<level::ILevelChance> levelChance_;
};

} // namespace random
} // namespace src::game

#endif // SRC_GAME_RANDOM_RANDOMGENERATOR_HPP
