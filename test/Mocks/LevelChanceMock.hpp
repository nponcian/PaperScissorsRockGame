#ifndef TEST_MOCKS_LEVELCHANCEMOCK_HPP
#define TEST_MOCKS_LEVELCHANCEMOCK_HPP

#include <gmock/gmock.h>

#include <Game/Level/ILevelChance.hpp>

namespace test::mocks
{

using namespace src::game::level;

class LevelChanceMock : public ILevelChance
{
public:
    MOCK_CONST_METHOD1(getLevelsPercentageChances,
        std::unordered_map<LevelState, PercentageChance>(const LevelState levelState));
};

} // namespace test::mocks

#endif // TEST_MOCKS_LEVELCHANCEMOCK_HPP
