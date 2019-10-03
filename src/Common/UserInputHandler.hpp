#ifndef SRC_COMMON_USERINPUTHANDLER_HPP
#define SRC_COMMON_USERINPUTHANDLER_HPP

#include <Common/DataTypeHandler.hpp>
#include <Common/Logger.hpp>

namespace src::common
{
namespace
{

Logger userInputLogger("UserInputHandler");

} // namespace

inline std::string getUserInputString(std::istream& inputStream = std::cin)
{
    userInputLogger.print("Input:");
    std::string input;
    std::getline(inputStream, input);
    return input;
}

// To be used for user inputs such as int, unsigned, long, short, char, bool and float, double.
// Need not to be explicitly declared as inline because the method is a template, thus, is automatically
// compiled as a weak (W) symbol as opposed to text (T) symbol for non-template non-inline methods.
template <typename IntegralOrFloatingType>
IntegralOrFloatingType getUserInputIntegralOrFloating(std::istream& inputStream = std::cin)
{
    if (!isIntegralType<IntegralOrFloatingType>() && !isFloatingType<IntegralOrFloatingType>())
    {
        userInputLogger.print("Error. Usage of method ", __FUNCTION__, " for non-integral/floating type!");
        return IntegralOrFloatingType{};
    }

    userInputLogger.print("Input:");
    IntegralOrFloatingType input;
    inputStream >> input;
    inputStream.ignore();
    return input;
}

} // namespace src::common

#endif // SRC_COMMON_USERINPUTHANDLER_HPP
