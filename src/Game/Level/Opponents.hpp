#ifndef SRC_GAME_LEVEL_OPPONENTS_HPP
#define SRC_GAME_LEVEL_OPPONENTS_HPP

#include <functional>
#include <memory>
#include <vector>

namespace src::game
{
namespace symbols
{

class ISymbol;

} // namespace symbols;

namespace level
{

using ISymbolPtrConstRef = std::reference_wrapper<const std::shared_ptr<symbols::ISymbol>>;

struct OpponentGroups
{
    std::vector<ISymbolPtrConstRef> easy;
    std::vector<ISymbolPtrConstRef> average;
    std::vector<ISymbolPtrConstRef> hard;
};

bool isOpponentGroupsEmpty(const OpponentGroups& opponentGroups);

OpponentGroups classifyOpponents(
    const std::shared_ptr<symbols::ISymbol> targetSymbol,
    const std::vector<std::shared_ptr<symbols::ISymbol>>& symbolsPassedByReference);

// Deleted on purpose. Please see Opponents.cpp file for more info
OpponentGroups classifyOpponents(
    const std::shared_ptr<symbols::ISymbol> targetSymbol,
    std::vector<std::shared_ptr<symbols::ISymbol>>&& symbolsPassedByTempRValue) = delete;

} // namespace level
} // namespace src::game

#endif // SRC_GAME_LEVEL_OPPONENTS_HPP
