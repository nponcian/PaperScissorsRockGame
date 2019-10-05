#include <Game/Level/Opponents.hpp>

#include <functional>
#include <memory>
#include <vector>

#include <Game/Symbols/ISymbol.hpp>

namespace src::game::level
{

bool isOpponentGroupsEmpty(const OpponentGroups& opponentGroups)
{
    return opponentGroups.easy.empty() && opponentGroups.average.empty() && opponentGroups.hard.empty();
}

// Be aware that we are using const references to shared_ptr, so & in function argument and const auto
// below is important, or else we will be left with a const reference to a dead shared_ptr (not the
// object pointed but the shared_ptr itself)
OpponentGroups classifyOpponents(
    const std::shared_ptr<symbols::ISymbol> targetSymbol,
    const std::vector<std::shared_ptr<symbols::ISymbol>>& symbolsPassedByReference)
{
    OpponentGroups opponentGroups;
    for (const auto& symbol : symbolsPassedByReference)
    {
        auto battleResult = targetSymbol->engageBattle(symbol);
        if (battleResult == symbols::BattleResult::Win)       opponentGroups.easy.push_back(std::cref(symbol));
        else if (battleResult == symbols::BattleResult::Lose) opponentGroups.hard.push_back(std::cref(symbol));
        else                                                  opponentGroups.average.push_back(std::cref(symbol));
    }
    return opponentGroups;
}

} // namespace src::game::level
