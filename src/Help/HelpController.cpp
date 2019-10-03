#include <Help/HelpController.hpp>

#include <Common/Logger.hpp>

namespace src::help
{
namespace
{

common::Logger logger("HelpController");

} // namespace

HelpController::HelpController()
{
}

void HelpController::displayHelp() const
{
    logger.print();
    logger.print("PaperScissorsRock (PSR) is a hand-game of symbols where you can play versus the computer.");
    logger.print("The winner is determined by the following schema:");
    logger.print("    paper beats (wraps) rock,");
    logger.print("    rock beats (blunts) scissors,");
    logger.print("    scissors beats (cuts) paper.");
    logger.print();
    logger.print("Postfix the following commands upon running <./psr_src>");
    logger.print();
    logger.print("\t--help");
    logger.print("\t\tDisplay the information about this project.");
    logger.print("\t\tGuides you with the available commands to move through what the project can offer.");
    logger.print();
    logger.print("\t--play");
    logger.print("\t\tAccess the game! Different languages are supported such as English, Spanish, and Filipino");
    logger.print("\t\tSi no lo entiendes, lo que estoy diciendo es Espanol esta disponible en este app!");
    logger.print("\t\tOo pati Filipino! At posibleng marami pang iba!");
    logger.print("\t\tDifferent modes of difficulty can also be chosen such as easy, average, and hard");
    logger.print("\t\tThe question now is, are you lucky enough to win? Vamos a jugarlo, mi amigo!");
    logger.print();
    logger.print("\t\tGood luck predicting the computer's next move! :)");
}

} // namespace src::help
