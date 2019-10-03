#ifndef SRC_COMMON_DATATYPEHANDLER_HPP
#define SRC_COMMON_DATATYPEHANDLER_HPP

#include <type_traits>

namespace src::common
{

template <typename T>
bool isIntegralType()
{
    return std::is_integral<T>::value;
}

template <typename T>
bool isFloatingType()
{
    return std::is_floating_point<T>::value;
}

} // namespace src::common

#endif // SRC_COMMON_DATATYPEHANDLER_HPP
