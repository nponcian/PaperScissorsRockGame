#ifndef SRC_GAME_OUTPUT_IOUTPUTTER_HPP
#define SRC_GAME_OUTPUT_IOUTPUTTER_HPP

#include <memory>
#include <string>
#include <vector>

#include <Common/Logger.hpp>

namespace src::game
{
namespace symbols
{

class ISymbol;

} // namespace symbols

namespace output
{

// This basically supports displaying of different text using different human languages. Support
// for new languages and messages can be added easily here and ported to all languages.
class IOutputter
{
public:
    virtual ~IOutputter(){}

    virtual std::string name() const = 0;

    virtual void selectLanguage(const std::vector<std::shared_ptr<IOutputter>>& outputters) const
    {
        common::Logger logger("IOutputter::selectLanguage");
        logger.print("Select your language, me entiendes?");
        for (unsigned ctr = 0; ctr < outputters.size(); ++ctr)
        {
            logger.print("    ", ctr, " ", outputters[ctr]->name());
        }
    }

    virtual void welcome() const = 0;

    virtual void selectDifficulty() const = 0;

    virtual void numberOfGameRounds(const int rounds) const = 0;

    virtual void battleCountdown(const int battleId) const = 0;

    virtual void selectSymbol(const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols) const = 0;

    virtual void symbolLogoBattle(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const = 0;

    virtual void roundWin(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const = 0;

    virtual void roundLose(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const = 0;

    virtual void roundDraw(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const = 0;

    virtual void gameTally(
        const int player1Score,
        const int player2Score) const = 0;

    virtual void gameWin() const = 0;

    // Draw is considered defeat!
    virtual void gameLose() const = 0;
};

} // namespace output
} // namespace src::game

#endif // SRC_GAME_OUTPUT_IOUTPUTTER_HPP
