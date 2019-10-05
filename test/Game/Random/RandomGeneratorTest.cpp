#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <set>
#include <unordered_set>

#include <Game/Random/RandomGenerator.hpp>
#include <Game/Symbols/SymbolsGetter.hpp>

#include <Mocks/LevelChanceMock.hpp>

using namespace src::game::random;
using namespace src::game::symbols;
using namespace test::mocks;
using namespace ::testing;

struct RandomGeneratorTest : public ::testing::Test
{
    RandomGeneratorTest() :
        levelChanceMock_(std::make_shared<LevelChanceMock>()),
        impl_(std::make_shared<RandomGenerator>(getAllSymbols(), levelChanceMock_))
    {
    }

    virtual ~RandomGeneratorTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    std::shared_ptr<LevelChanceMock> levelChanceMock_;
    std::shared_ptr<RandomGenerator> impl_;
};

TEST_F(RandomGeneratorTest, DecideOnCasesThatShouldBeYes)
{
    const int DEFINITELY_YES = 100;

    int ctr = 100;
    while (--ctr >= 0)
    {
        EXPECT_TRUE(impl_->randomDecision(DEFINITELY_YES));
    }
}

TEST_F(RandomGeneratorTest, DecideOnCasesThatShouldBeNo)
{
    const int DEFINITELY_NO = 0;

    int ctr = 100;
    while (--ctr >= 0)
    {
        EXPECT_FALSE(impl_->randomDecision(DEFINITELY_NO));
    }
}

TEST_F(RandomGeneratorTest, GenerateRandomDecisions)
{
    // Yes it might be random by nature, but if the same result happens after a dozen count,
    // implementation logic then deserves to be revisited as from user POV, there might be times
    // that nothing seems to be happening.
    const int MAX_BOOLEAN_VALUES = 2;
    std::unordered_set<bool> values;

    int ctr = 12;
    while (--ctr >= 0 && values.size() < MAX_BOOLEAN_VALUES)
    {
        values.insert(impl_->randomDecision());
    }
    EXPECT_EQ(values.size(), MAX_BOOLEAN_VALUES);
}

TEST_F(RandomGeneratorTest, GenerateRandomNumbers)
{
    // Yes it might be random by nature, but if the same result happens after a dozen count,
    // implementation logic then deserves to be revisited as from user POV, there might be times
    // that nothing seems to be happening.
    const int ACCEPTED_RANDOMNESS_THRESHOLD = 3;
    std::unordered_set<int> values;

    int ctr = 12;
    while (--ctr >= 0)
    {
        values.insert(impl_->randomNumber(ACCEPTED_RANDOMNESS_THRESHOLD));
    }
    EXPECT_GE(values.size(), ACCEPTED_RANDOMNESS_THRESHOLD);
}

TEST_F(RandomGeneratorTest, NotExceedLimit)
{
    const int LIMIT = 22;

    int ctr = 100;
    while (--ctr >= 0)
    {
        int generated = impl_->randomNumber(LIMIT);
        EXPECT_LE(generated, LIMIT);
    }
}
