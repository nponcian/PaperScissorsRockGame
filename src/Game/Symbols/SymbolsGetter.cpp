#include <Game/Symbols/SymbolsGetter.hpp>

#include <memory>
#include <vector>

#include <Game/Symbols/PaperSymbol.hpp>
#include <Game/Symbols/RockSymbol.hpp>
#include <Game/Symbols/ScissorsSymbol.hpp>

namespace src::game::symbols
{

std::vector<std::shared_ptr<ISymbol>> getAllSymbols()
{
    return
        {
            std::make_shared<PaperSymbol>(),
            std::make_shared<RockSymbol>(),
            std::make_shared<ScissorsSymbol>(),
        };
}

} // namespace src::game::symbols
