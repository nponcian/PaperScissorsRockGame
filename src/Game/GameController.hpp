#ifndef SRC_GAME_GAMECONTROLLER_HPP
#define SRC_GAME_GAMECONTROLLER_HPP

#include <memory>

#include <Game/IGameController.hpp>

namespace src::game
{
namespace level
{

enum class LevelState;

} // namespace level

struct GameTools;

class GameController : public IGameController
{
public:
    GameController(std::shared_ptr<GameTools> gameTools);

    virtual void run(std::istream& inputStream = std::cin) override;

private:
    void initializeLanguageChoice(std::istream& inputStream);

    level::LevelState getLevelOfDifficulty(std::istream& inputStream);

    int randomizeGamesCount();

    unsigned getPlayerSymbolIndex(std::istream& inputStream);

    unsigned getComputerSymbolIndex(
        const unsigned userChoiceIndex,
        const level::LevelState levelState);

    void executeGame(
        const unsigned player1SymbolIndex,
        const unsigned player2SymbolIndex,
        unsigned& player1Score,
        unsigned& player2Score);

    void assessContestResult(
        const unsigned player1Score,
        const unsigned player2Score);

    std::shared_ptr<GameTools> gameTools_;
};

} // namespace src::game

#endif // SRC_GAME_GAMECONTROLLER_HPP
