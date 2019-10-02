#include <Common/Logger.hpp>
#include <MainController.hpp>

namespace
{

src::common::Logger logger("main");

} // namespace

int main(int argc, char** argv)
{
    logger.print("Start of execution");

    src::MainController mainController;
    for (int ctr = 0 ; ctr < argc; ++ctr)
    {
        if (ctr == 0 && argc > 1) continue;

        logger.print("Input to main is ", *(argv+ctr));
        mainController.handle(argv[ctr]);
    }

    logger.print("End of execution\n");
    return 0;
}
