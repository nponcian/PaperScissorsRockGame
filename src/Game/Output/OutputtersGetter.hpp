#ifndef SRC_GAME_OUTPUT_OUTPUTTERSGETTER_HPP
#define SRC_GAME_OUTPUT_OUTPUTTERSGETTER_HPP

#include <memory>
#include <vector>

namespace src::game::output
{

class IOutputter;

std::vector<std::shared_ptr<IOutputter>> getAllLanguageOutputters();

} // namespace src::game::output

#endif // SRC_GAME_OUTPUT_OUTPUTTERSGETTER_HPP
