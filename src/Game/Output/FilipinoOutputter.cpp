#include <Game/Output/FilipinoOutputter.hpp>

#include <memory>
#include <string>

#include <Common/Logger.hpp>
#include <Game/Level/ILevelChance.hpp>
#include <Game/Symbols/ISymbol.hpp>

namespace src::game::output
{
namespace
{

common::Logger logger("FilipinoOutputter");

} // namespace

FilipinoOutputter::FilipinoOutputter()
{
}

std::string FilipinoOutputter::name() const
{
    return "Filipino";
}

void FilipinoOutputter::welcome() const
{
    logger.print("Uy kumusta! Tara at maglaro tayo ng Paper Scissors Rock!");
}

void FilipinoOutputter::selectDifficulty() const
{
    logger.print("Mamili ng kahirapan:");
    unsigned ctr = 0;
    for (const auto& levelString : level::LEVELS_AND_NAME_VEC)
    {
        logger.print("    ", ctr, " ", levelString.second);
        ++ctr;
    }
}

void FilipinoOutputter::numberOfGameRounds(const int rounds) const
{
    logger.print("Ang laro na ito ay mayroong ", rounds, " rounds");
}

void FilipinoOutputter::battleCountdown(const int battleId) const
{
    logger.print();
    logger.print("Pagbilang pabalik: Laban #", battleId);
}

void FilipinoOutputter::selectSymbol(const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols) const
{
    logger.print("Pumili ng iyong simbolo:");
    for (unsigned ctr = 0; ctr < symbols.size(); ++ctr)
    {
        logger.print("    ", ctr, " ", symbols[ctr]->name());
    }
}

void FilipinoOutputter::symbolLogoBattle(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Ikaw:", symbol1->streamLogo().str());
    logger.print("laban");
    logger.print("Kompyuter:", symbol2->streamLogo().str());
}

void FilipinoOutputter::roundWin(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Panalo ka sa round na ito");
    logger.print(symbol1->name(), " tatalunin ang ", symbol2->name());
}

void FilipinoOutputter::roundLose(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Talo ka sa round na ito");
    logger.print(symbol1->name(), " talo sa ", symbol2->name());
}

void FilipinoOutputter::roundDraw(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Tabla ang round na ito!");
    logger.print(symbol1->name(), " ay hindi tatalunin at hindi din talo sa ", symbol2->name());
}

void FilipinoOutputter::gameTally(
    const int player1Score,
    const int player2Score) const
{
    logger.print("Listahan: Ikaw ", player1Score, " vs Kompyuter ", player2Score);
}

void FilipinoOutputter::gameWin() const
{
    logger.print("Nanalo ka sa paligsahan! Malamang ay marami kang taglay na swerte!");
}

void FilipinoOutputter::gameLose() const
{
    logger.print("Ndi ka nanalo. Sana ay palarin ka sa susunod!");
}

} // namespace src::game::output
