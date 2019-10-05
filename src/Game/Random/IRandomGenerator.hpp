#ifndef SRC_GAME_RANDOM_IRANDOMGENERATOR_HPP
#define SRC_GAME_RANDOM_IRANDOMGENERATOR_HPP

namespace src::game
{
namespace symbols
{

class ISymbol;
enum class SymbolState;

} // namespace symbols

namespace level
{

enum class LevelState;

} // namespace level

namespace random
{

enum class LevelState;

class IRandomGenerator
{
public:
    virtual ~IRandomGenerator(){}

    virtual bool randomDecision(const int chance = 50) const = 0;

    virtual int randomNumber(const int limit) const = 0;

    virtual symbols::SymbolState generateComputerSymbolState(
        const symbols::SymbolState userSymbolState,
        const level::LevelState levelState) const = 0;
};

} // namespace random
} // namespace src::game

#endif // SRC_GAME_RANDOM_IRANDOMGENERATOR_HPP
