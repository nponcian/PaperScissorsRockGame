#include <Game/Output/EnglishOutputter.hpp>

#include <memory>
#include <string>

#include <Common/Logger.hpp>
#include <Game/Level/ILevelChance.hpp>
#include <Game/Symbols/ISymbol.hpp>

namespace src::game::output
{
namespace
{

common::Logger logger("EnglishOutputter");

} // namespace

EnglishOutputter::EnglishOutputter()
{
}

std::string EnglishOutputter::name() const
{
    return "English";
}

void EnglishOutputter::welcome() const
{
    logger.print("Hi there! Let's play Paper Scissors Rock!");
}

void EnglishOutputter::selectDifficulty() const
{
    logger.print("Select difficulty:");
    unsigned ctr = 0;
    for (const auto& levelString : level::LEVELS_AND_NAME_VEC)
    {
        logger.print("    ", ctr, " ", levelString.second);
        ++ctr;
    }
}

void EnglishOutputter::numberOfGameRounds(const int rounds) const
{
    logger.print("The game will be played for ", rounds, " rounds");
}

void EnglishOutputter::battleCountdown(const int battleId) const
{
    logger.print();
    logger.print("Countdown: Battle #", battleId);
}

void EnglishOutputter::selectSymbol(const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols) const
{
    logger.print("Select your symbol:");
    for (unsigned ctr = 0; ctr < symbols.size(); ++ctr)
    {
        logger.print("    ", ctr, " ", symbols[ctr]->name());
    }
}

void EnglishOutputter::symbolLogoBattle(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("You:", symbol1->streamLogo().str());
    logger.print("versus");
    logger.print("Computer:", symbol2->streamLogo().str());
}

void EnglishOutputter::roundWin(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("You win this round");
    logger.print(symbol1->name(), " beats ", symbol2->name());
}

void EnglishOutputter::roundLose(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("You lose this round");
    logger.print(symbol1->name(), " loses to ", symbol2->name());
}

void EnglishOutputter::roundDraw(
    const std::shared_ptr<symbols::ISymbol> symbol1,
    const std::shared_ptr<symbols::ISymbol> symbol2) const
{
    logger.print("Draw for this round!");
    logger.print(symbol1->name(), " neither beats nor lose to ", symbol2->name());
}

void EnglishOutputter::gameTally(
    const int player1Score,
    const int player2Score) const
{
    logger.print("Tally: You ", player1Score, " vs Computer ", player2Score);
}

void EnglishOutputter::gameWin() const
{
    logger.print("You win this contest! You must be really lucky!");
}

void EnglishOutputter::gameLose() const
{
    logger.print("You didn't win. Better luck next time!");
}

} // namespace src::game::output
