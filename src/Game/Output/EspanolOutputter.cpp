#include <Game/Output/EspanolOutputter.hpp>

#include <memory>
#include <string>

#include <Common/Logger.hpp>
#include <Game/Level/ILevelChance.hpp>
#include <Game/Symbols/ISymbol.hpp>

namespace src::game::output
{
namespace
{

common::Logger logger("EspanolOutputter");

} // namespace

EspanolOutputter::EspanolOutputter()
{
}

std::string EspanolOutputter::name() const
{
    return "Espanol";
}

void EspanolOutputter::welcome() const
{
    logger.print("Hola mi amigo, como estas! Vamos a jugar Paper Scissors Rock!");
}

void EspanolOutputter::selectDifficulty() const
{
    logger.print("Elige dificultad:");
    unsigned ctr = 0;
    for (const auto& levelString : level::LEVELS_AND_NAME_VEC)
    {
        logger.print("    ", ctr, " ", levelString.second);
        ++ctr;
    }
}

void EspanolOutputter::numberOfGameRounds(const int rounds) const
{
    logger.print("El juego se jugara ", rounds, " veces");
}

void EspanolOutputter::battleCountdown(const int battleId) const
{
    logger.print();
    logger.print("Cuenta regresiva: Batalla #", battleId);
}

void EspanolOutputter::selectSymbol(const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols) const
{
    logger.print("Elige tu simbolo:");
    for (unsigned ctr = 0; ctr < symbols.size(); ++ctr)
    {
        logger.print("    ", ctr, " ", symbols[ctr]->name());
    }
}

void EspanolOutputter::symbolLogoBattle(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Tu:", symbol1->streamLogo().str());
    logger.print("contra");
    logger.print("Computadora:", symbol2->streamLogo().str());
}

void EspanolOutputter::roundWin(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Tu ganas esta ronda");
    logger.print(symbol1->name(), " vencio ", symbol2->name());
}

void EspanolOutputter::roundLose(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Tu pierdes esta ronda");
    logger.print(symbol1->name(), " pierde a ", symbol2->name());
}

void EspanolOutputter::roundDraw(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Empate para esta ronda!");
    logger.print(symbol1->name(), " tampoco vencio ni pierde a ", symbol2->name());
}

void EspanolOutputter::gameTally(
    const int player1Score,
    const int player2Score) const
{
    logger.print("Cuenta: Tu ", player1Score, " vs Computadora ", player2Score);
}

void EspanolOutputter::gameWin() const
{
    logger.print("Tu ganaste en este concurso. Debes estar lleno de suerte!");
}

void EspanolOutputter::gameLose() const
{
    logger.print("Tu no ganaste. Te deseo mejor suerte la proxima vez.");
}

} // namespace src::game::output
