#include <Game/Symbols/ScissorsSymbol.hpp>

#include <memory>
#include <sstream>

#include <Game/Symbols/ISymbol.hpp>

namespace src::game::symbols
{

const std::string ScissorsSymbol::SYMBOL_NAME_ = "Scissors";

const SymbolState ScissorsSymbol::SYMBOL_STATE_ = SymbolState::Scissors;

ScissorsSymbol::ScissorsSymbol()
{
}

std::string ScissorsSymbol::name() const
{
    return SYMBOL_NAME_;
}

SymbolState ScissorsSymbol::getSymbolState() const
{
    return SYMBOL_STATE_;
}

BattleResult ScissorsSymbol::engageBattle(const SymbolState otherSymbolState) const
{
    switch (otherSymbolState)
    {
        case SymbolState::Paper    : return BattleResult::Win;
        case SymbolState::Scissors : return BattleResult::Draw;
        case SymbolState::Rock     : return BattleResult::Lose;
    }
    return BattleResult::Draw;
}

std::stringstream ScissorsSymbol::streamLogo() const
{
    std::stringstream ss;
    ss << "\n                _____";
    ss << "\n        _____   |   | ";
    ss << "\n        |   |   |   |";
    ss << "\n        |   |   |   |";
    ss << "\n        |   |   |   |";
    ss << "\n        |   |   |   |";
    ss << "\n        |   |   |   |";
    ss << "\n        |   |   |   |";
    ss << "\n        |   |   |   | _____";
    ss << "\n  ____  |   |   |   | |   | ____";
    ss << "\n /   /  |   |   |   | |   | |  |";
    ss << "\n/   /  /    |___|   |_|   |_|  |";
    ss << "\n|   | /               |   | |  |";
    ss << "\n|   |/                |   | |__|";
    ss << "\n\\                     |___| \\__/";
    ss << "\n \\                    \\___/    |";
    ss << "\n  \\                            |";
    ss << "\n   \\                           |";
    ss << "\n    \\                          |";
    ss << "\n     \\                        /";
    ss << "\n      \\                      /";
    ss << "\n";
    return ss;
}

} // namespace src::game::symbols
