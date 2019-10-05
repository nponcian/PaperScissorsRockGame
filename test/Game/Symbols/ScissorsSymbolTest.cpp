#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <Game/Symbols/ScissorsSymbol.hpp>
#include <Game/Symbols/SymbolsGetter.hpp>

using namespace src::game::symbols;
using namespace ::testing;

struct ScissorsSymbolTest : public ::testing::Test
{
    ScissorsSymbolTest() :
        impl_(std::make_shared<ScissorsSymbol>()),
        symbols_(getAllSymbols())
    {
    }

    virtual ~ScissorsSymbolTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    std::shared_ptr<ISymbol> impl_;
    std::vector<std::shared_ptr<ISymbol>> symbols_;
};

TEST_F(ScissorsSymbolTest, CheckName)
{
    EXPECT_EQ(impl_->name(), "Scissors");
}

TEST_F(ScissorsSymbolTest, CheckSymbolState)
{
    EXPECT_EQ(impl_->getSymbolState(), SymbolState::Scissors);
}

TEST_F(ScissorsSymbolTest, CheckBattleResults)
{
    for (const auto symbol : symbols_)
    {
        auto result = impl_->engageBattle(symbol);
        switch (symbol->getSymbolState())
        {
            case SymbolState::Paper :    EXPECT_EQ(result, BattleResult::Win);  continue;
            case SymbolState::Scissors : EXPECT_EQ(result, BattleResult::Draw); continue;
            case SymbolState::Rock :     EXPECT_EQ(result, BattleResult::Lose); continue;
        }
    }
}
