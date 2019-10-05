#include <Game/Output/OutputtersGetter.hpp>

#include <memory>
#include <vector>

#include <Game/Output/EnglishOutputter.hpp>
#include <Game/Output/EspanolOutputter.hpp>
#include <Game/Output/FilipinoOutputter.hpp>

namespace src::game::output
{

std::vector<std::shared_ptr<IOutputter>> getAllLanguageOutputters()
{
    return
        {
            std::make_shared<EnglishOutputter>(),
            std::make_shared<EspanolOutputter>(),
            std::make_shared<FilipinoOutputter>(),
        };
}

} // namespace src::game::output
