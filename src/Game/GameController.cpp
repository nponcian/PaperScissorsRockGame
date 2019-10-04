#include <Game/GameController.hpp>

#include <locale>
#include <limits>
#include <vector>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>
#include <Game/GameTools.hpp>
#include <Game/Level/LevelChance.hpp>
#include <Game/Output/OutputtersGetter.hpp>
#include <Game/Output/IOutputter.hpp>
#include <Game/Random/RandomGenerator.hpp>
#include <Game/Symbols/ISymbol.hpp>
#include <Game/Symbols/SymbolsGetter.hpp>

namespace src::game
{
namespace
{

common::Logger logger("GameController");

const int MIN_GAMES_COUNT = 5;
const int MAX_GAMES_COUNT = 15;

} // namespace

GameController::GameController(
    std::shared_ptr<GameTools> gameTools) :
        gameTools_(gameTools)
{
}

void GameController::run(std::istream& inputStream)
{
    // Here is the main flow of the program. Code is pretty much self-explanatory and self-documenting.
    unsigned userWinCount = 0;
    unsigned computerWinCount = 0;

    initializeLanguageChoice(inputStream);
    auto levelState = getLevelOfDifficulty(inputStream);
    int gamesCount = randomizeGamesCount();

    while (gamesCount > 0)
    {
        gameTools_->chosenOutputter->battleCountdown(gamesCount);
        --gamesCount;

        unsigned userChoiceIndex = getPlayerSymbolIndex(inputStream);
        unsigned computerChoiceIndex = getComputerSymbolIndex(userChoiceIndex, levelState);
        executeGame(userChoiceIndex, computerChoiceIndex, userWinCount, computerWinCount);
    }

    assessContestResult(userWinCount, computerWinCount);
}

void GameController::initializeLanguageChoice(std::istream& inputStream)
{
    gameTools_->chosenOutputter->selectLanguage(gameTools_->outputters);
    unsigned languageChoice = common::getUserInputIntegralOrFloating<unsigned>(inputStream);
    if (languageChoice >= gameTools_->outputters.size())
    {
        return;
    }
    gameTools_->chosenOutputter = gameTools_->outputters[languageChoice];
    gameTools_->chosenOutputter->welcome();
}

level::LevelState GameController::getLevelOfDifficulty(std::istream& inputStream)
{
    gameTools_->chosenOutputter->selectDifficulty();
    unsigned difficultyChoice = common::getUserInputIntegralOrFloating<unsigned>(inputStream);
    if (difficultyChoice >= level::LEVELS_AND_NAME_VEC.size())
    {
        difficultyChoice = 0u;
    }
    return level::LEVELS_AND_NAME_VEC[difficultyChoice].first;
}

int GameController::randomizeGamesCount()
{
    int gamesCount = std::max(MIN_GAMES_COUNT, gameTools_->randomGenerator->randomNumber(MAX_GAMES_COUNT));
    gameTools_->chosenOutputter->numberOfGameRounds(gamesCount);
    return gamesCount;
}

unsigned GameController::getPlayerSymbolIndex(std::istream& inputStream)
{
    gameTools_->chosenOutputter->selectSymbol(gameTools_->symbols);
    unsigned userChoiceIndex = common::getUserInputIntegralOrFloating<unsigned>(inputStream);
    if (userChoiceIndex >= gameTools_->symbols.size())
    {
        userChoiceIndex = 0u;
    }
    return userChoiceIndex;
}

unsigned GameController::getComputerSymbolIndex(
    const unsigned userChoiceIndex,
    const level::LevelState levelState)
{
    auto computerSymbolState = gameTools_->randomGenerator->generateComputerSymbolState(
                                gameTools_->symbols[userChoiceIndex]->getSymbolState(), levelState);
    for (unsigned ctr = 0; ctr < gameTools_->symbols.size(); ++ctr)
    {
        if (gameTools_->symbols[ctr]->getSymbolState() == computerSymbolState)
        {
            return ctr;
        }
    }
    return 0u;
}

void GameController::executeGame(
    const unsigned player1SymbolIndex,
    const unsigned player2SymbolIndex,
    unsigned& player1Score,
    unsigned& player2Score)
{
    gameTools_->chosenOutputter->symbolLogoBattle(
        gameTools_->symbols[player1SymbolIndex], gameTools_->symbols[player2SymbolIndex]);

    auto battleResult = gameTools_->symbols[player1SymbolIndex]->engageBattle(
                            gameTools_->symbols[player2SymbolIndex]);

    switch (battleResult)
    {
        case symbols::BattleResult::Win :
        {
            ++player1Score;
            gameTools_->chosenOutputter->roundWin(gameTools_->symbols[player1SymbolIndex],
                                                    gameTools_->symbols[player2SymbolIndex]);
            break;
        }
        case symbols::BattleResult::Lose :
        {
            ++player2Score;
            gameTools_->chosenOutputter->roundLose(gameTools_->symbols[player1SymbolIndex],
                                                    gameTools_->symbols[player2SymbolIndex]);
            break;
        }
        case symbols::BattleResult::Draw :
        {
            gameTools_->chosenOutputter->roundDraw(gameTools_->symbols[player1SymbolIndex],
                                                    gameTools_->symbols[player2SymbolIndex]);
            break;
        }
    }
}

void GameController::assessContestResult(
    const unsigned player1Score,
    const unsigned player2Score)
{
    gameTools_->chosenOutputter->gameTally(player1Score, player2Score);
    if (player1Score > player2Score) gameTools_->chosenOutputter->gameWin();
    else                             gameTools_->chosenOutputter->gameLose();
}

} // namespace src::game
