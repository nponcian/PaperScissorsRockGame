#ifndef SRC_GAME_OUTPUT_ESPANOLOUTPUTTER_HPP
#define SRC_GAME_OUTPUT_ESPANOLOUTPUTTER_HPP

#include <memory>
#include <string>

#include <Game/Output/IOutputter.hpp>

namespace src::game::output
{

class EspanolOutputter : public IOutputter
{
public:
    EspanolOutputter();

    virtual std::string name() const override;

    virtual void welcome() const override;

    virtual void selectDifficulty() const override;

    virtual void numberOfGameRounds(const int rounds) const override;

    virtual void battleCountdown(const int battleId) const override;

    virtual void selectSymbol(const std::vector<std::shared_ptr<symbols::ISymbol>>& symbols) const override;

    virtual void symbolLogoBattle(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const override;

    virtual void roundWin(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const override;

    virtual void roundLose(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const override;

    virtual void roundDraw(
        const std::shared_ptr<symbols::ISymbol> symbol1,
        const std::shared_ptr<symbols::ISymbol> symbol2) const override;

    virtual void gameTally(
        const int player1Score,
        const int player2Score) const override;

    virtual void gameWin() const override;

    virtual void gameLose() const override;
};

} // namespace src::game::output

#endif // SRC_GAME_OUTPUT_ESPANOLOUTPUTTER_HPP
