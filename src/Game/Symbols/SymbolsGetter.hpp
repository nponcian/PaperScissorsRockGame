#ifndef SRC_GAME_SYMBOLS_SYMBOLSGETTER_HPP
#define SRC_GAME_SYMBOLS_SYMBOLSGETTER_HPP

#include <memory>
#include <vector>

namespace src::game::symbols
{

class ISymbol;

std::vector<std::shared_ptr<ISymbol>> getAllSymbols();

} // namespace src::game::symbols

#endif // SRC_GAME_SYMBOLS_SYMBOLSGETTER_HPP
