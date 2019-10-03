#ifndef SRC_COMMON_LOGGER_HPP
#define SRC_COMMON_LOGGER_HPP

#include <iostream>
#include <sstream>

namespace src::common
{
namespace detail
{

template <typename... Args>
typename std::enable_if<sizeof...(Args) == 0>::type concatenateMessages(std::ostream&)
{
}

template <typename T, typename... Args>
std::ostream& concatenateMessages(
    std::ostream& os,
    T&& message,
    Args&&... args)
{
    os << message;
    concatenateMessages(os, std::forward<Args>(args)...);
    return os;
}

} // namespace detail

class Logger
{
public:
    Logger() :
        fileName_("UnknownFile")
    {
    }

    explicit Logger(const char* fileName) :
        fileName_(fileName)
    {
    }

    template <typename T, typename... Args>
    void print(T&& message, Args&&... args)
    {
        std::ostringstream oss;
        oss << "\n[" << fileName_ << "] ";
        detail::concatenateMessages(oss, message, std::forward<Args>(args)...);
        #ifndef DONT_PRINT_TO_SCREEN // If not defined hence, printing is allowed
        std::cout << oss.str();
        #endif
    }

    template <typename T, typename... Args>
    void printNoFormatting(T&& message, Args&&... args)
    {
        std::ostringstream oss;
        detail::concatenateMessages(oss, message, std::forward<Args>(args)...);
        #ifndef DONT_PRINT_TO_SCREEN // If not defined hence, printing is allowed
        std::cout << oss.str();
        #endif
    }

    void print()
    {
        print("");
    }

private:
    const char* fileName_;
};

} // namespace src::common

#endif // SRC_COMMON_LOGGER_HPP
