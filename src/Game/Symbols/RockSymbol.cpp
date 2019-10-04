#include <Game/Symbols/RockSymbol.hpp>

#include <memory>
#include <sstream>

#include <Game/Symbols/ISymbol.hpp>

namespace src::game::symbols
{

const std::string RockSymbol::SYMBOL_NAME_ = "Rock";

const SymbolState RockSymbol::SYMBOL_STATE_ = SymbolState::Rock;

RockSymbol::RockSymbol()
{
}

std::string RockSymbol::name() const
{
    return SYMBOL_NAME_;
}

SymbolState RockSymbol::getSymbolState() const
{
    return SYMBOL_STATE_;
}

BattleResult RockSymbol::engageBattle(const SymbolState otherSymbolState) const
{
    switch (otherSymbolState)
    {
        case SymbolState::Paper    : return BattleResult::Lose;
        case SymbolState::Scissors : return BattleResult::Win;
        case SymbolState::Rock     : return BattleResult::Draw;
    }
    return BattleResult::Draw;
}

std::stringstream RockSymbol::streamLogo() const
{
    std::stringstream ss;
    ss << "\n             _____";
    ss << "\n       ____  |   | _____";
    ss << "\n       |   | |   | |   | ____";
    ss << "\n   ____|   | |   | |   | |  |";
    ss << "\n  /   /|   | |   | |   | |  |";
    ss << "\n /   / |   | |   | |   | |  |";
    ss << "\n/   /  |   |_|   |_|   |_|  |";
    ss << "\n|   | /|   | |   | |   | |__|";
    ss << "\n|   |/ |   | |   | |   | \\__/";
    ss << "\n\\      |___| |   | |___|    |";
    ss << "\n \\     \\___/ |___| \\___/    |";
    ss << "\n  \\          \\___/          |";
    ss << "\n   \\                        |";
    ss << "\n    \\                       |";
    ss << "\n     \\                     /";
    ss << "\n      \\                   /";
    ss << "\n";
    return ss;
}

} // namespace src::game::symbols
