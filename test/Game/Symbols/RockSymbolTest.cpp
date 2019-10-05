#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <Game/Symbols/RockSymbol.hpp>
#include <Game/Symbols/SymbolsGetter.hpp>

using namespace src::game::symbols;
using namespace ::testing;

struct RockSymbolTest : public ::testing::Test
{
    RockSymbolTest() :
        impl_(std::make_shared<RockSymbol>()),
        symbols_(getAllSymbols())
    {
    }

    virtual ~RockSymbolTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    std::shared_ptr<ISymbol> impl_;
    std::vector<std::shared_ptr<ISymbol>> symbols_;
};

TEST_F(RockSymbolTest, CheckName)
{
    EXPECT_EQ(impl_->name(), "Rock");
}

TEST_F(RockSymbolTest, CheckSymbolState)
{
    EXPECT_EQ(impl_->getSymbolState(), SymbolState::Rock);
}

TEST_F(RockSymbolTest, CheckBattleResults)
{
    for (const auto symbol : symbols_)
    {
        auto result = impl_->engageBattle(symbol);
        switch (symbol->getSymbolState())
        {
            case SymbolState::Paper :    EXPECT_EQ(result, BattleResult::Lose); continue;
            case SymbolState::Scissors : EXPECT_EQ(result, BattleResult::Win);  continue;
            case SymbolState::Rock :     EXPECT_EQ(result, BattleResult::Draw); continue;
        }
    }
}
