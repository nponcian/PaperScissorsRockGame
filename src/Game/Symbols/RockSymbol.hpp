#ifndef SRC_GAME_SYMBOLS_ROCKSYMBOL_HPP
#define SRC_GAME_SYMBOLS_ROCKSYMBOL_HPP

#include <memory>
#include <sstream>
#include <string>

#include <Game/Symbols/ISymbol.hpp>

namespace src::game::symbols
{

class RockSymbol : public ISymbol
{
public:
    RockSymbol();

    virtual std::string name() const override;

    virtual SymbolState getSymbolState() const override;

    virtual BattleResult engageBattle(const SymbolState otherSymbolState) const override;

    virtual std::stringstream streamLogo() const override;

private:
    static const std::string SYMBOL_NAME_;

    static const SymbolState SYMBOL_STATE_;
};

} // namespace src::game::symbols

#endif // SRC_GAME_SYMBOLS_ROCKSYMBOL_HPP
