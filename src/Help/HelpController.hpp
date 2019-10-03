#ifndef SRC_HELP_HELPCONTROLLER_HPP
#define SRC_HELP_HELPCONTROLLER_HPP

#include <Help/IHelpController.hpp>

namespace src::help
{

class HelpController : public IHelpController
{
public:
    HelpController();

    virtual void displayHelp() const override;
};

} // namespace src::help

#endif // SRC_HELP_HELPCONTROLLER_HPP
