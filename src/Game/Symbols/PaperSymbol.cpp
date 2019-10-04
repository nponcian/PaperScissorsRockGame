#include <Game/Symbols/PaperSymbol.hpp>

#include <memory>
#include <sstream>

#include <Game/Symbols/ISymbol.hpp>

namespace src::game::symbols
{

const std::string PaperSymbol::SYMBOL_NAME_ = "Paper";

const SymbolState PaperSymbol::SYMBOL_STATE_ = SymbolState::Paper;

PaperSymbol::PaperSymbol()
{
}

std::string PaperSymbol::name() const
{
    return SYMBOL_NAME_;
}

SymbolState PaperSymbol::getSymbolState() const
{
    return SYMBOL_STATE_;
}

BattleResult PaperSymbol::engageBattle(const SymbolState otherSymbolState) const
{
    switch (otherSymbolState)
    {
        case SymbolState::Paper    : return BattleResult::Draw;
        case SymbolState::Scissors : return BattleResult::Lose;
        case SymbolState::Rock     : return BattleResult::Win;
    }
    return BattleResult::Draw;
}

std::stringstream PaperSymbol::streamLogo() const
{
    std::stringstream ss;
    ss << "\n             _____";
    ss << "\n       _____ |   | _____";
    ss << "\n       |   | |   | |   |";
    ss << "\n       |   | |   | |   |";
    ss << "\n       |   | |   | |   | ____";
    ss << "\n       |   | |   | |   | |  |";
    ss << "\n       |   | |   | |   | |  |";
    ss << "\n       |   | |   | |   | |  |";
    ss << "\n       |   | |   | |   | |  |";
    ss << "\n_____  |   | |   | |   | |  |";
    ss << "\n|   |  |   | |   | |   | |  |";
    ss << "\n|   |  |   |_|   |_|   |_|  |";
    ss << "\n|   | /                     |";
    ss << "\n|   |/                      |";
    ss << "\n\\                           |";
    ss << "\n \\                          |";
    ss << "\n  \\                         |";
    ss << "\n   \\                        |";
    ss << "\n    \\                       |";
    ss << "\n     \\                     /";
    ss << "\n      \\                   /";
    ss << "\n";
    return ss;
}

} // namespace src::game::symbols
