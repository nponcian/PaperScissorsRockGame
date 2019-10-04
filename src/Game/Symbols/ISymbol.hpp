#ifndef SRC_GAME_SYMBOLS_ISYMBOL_HPP
#define SRC_GAME_SYMBOLS_ISYMBOL_HPP

#include <memory>
#include <sstream>
#include <string>

namespace src::game::symbols
{

enum class BattleResult
{
    Win,
    Lose,
    Draw
};

enum class SymbolState
{
    Paper,
    Scissors,
    Rock,
};

// New symbols can be integrated to the project seamlessly just by implementing this
class ISymbol
{
public:
    ISymbol(){}

    virtual ~ISymbol(){}

    virtual std::string name() const = 0;

    virtual SymbolState getSymbolState() const = 0;

    virtual BattleResult engageBattle(const SymbolState otherSymbolState) const = 0;

    virtual BattleResult engageBattle(const std::shared_ptr<ISymbol> otherSymbol) const
    {
        return engageBattle(otherSymbol->getSymbolState());
    }

    virtual std::stringstream streamLogo() const = 0;
};

} // namespace src::game::symbols

#endif // SRC_GAME_SYMBOLS_ISYMBOL_HPP
