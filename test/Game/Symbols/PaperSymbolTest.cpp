#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <Game/Symbols/PaperSymbol.hpp>
#include <Game/Symbols/SymbolsGetter.hpp>

using namespace src::game::symbols;
using namespace ::testing;

struct PaperSymbolTest : public ::testing::Test
{
    PaperSymbolTest() :
        impl_(std::make_shared<PaperSymbol>()),
        symbols_(getAllSymbols())
    {
    }

    virtual ~PaperSymbolTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    std::shared_ptr<ISymbol> impl_;
    std::vector<std::shared_ptr<ISymbol>> symbols_;
};

TEST_F(PaperSymbolTest, CheckName)
{
    EXPECT_EQ(impl_->name(), "Paper");
}

TEST_F(PaperSymbolTest, CheckSymbolState)
{
    EXPECT_EQ(impl_->getSymbolState(), SymbolState::Paper);
}

TEST_F(PaperSymbolTest, CheckBattleResults)
{
    for (const auto symbol : symbols_)
    {
        auto result = impl_->engageBattle(symbol);
        switch (symbol->getSymbolState())
        {
            case SymbolState::Paper :    EXPECT_EQ(result, BattleResult::Draw); continue;
            case SymbolState::Scissors : EXPECT_EQ(result, BattleResult::Lose); continue;
            case SymbolState::Rock :     EXPECT_EQ(result, BattleResult::Win);  continue;
        }
    }
}
